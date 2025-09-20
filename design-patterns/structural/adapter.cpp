#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct USB_interface {
  virtual ~USB_interface() = default;
  virtual void connect() = 0;    // plug into USB port
  virtual void disconnect() = 0; // unplug into USB port
  virtual void sendData(const std::string &payload) = 0;
  virtual std::string readData() const = 0;
};

// Native device implementing USB_interface
class FlashDrive : public USB_interface {
  std::string data;

public:
  void connect() override {
    std::cout << "[FlashDrive] connected to USB port\n";
  }

  void disconnect() override {
    std::cout << "[FlashDrive] disconnected to USB port\n";
  }

  void sendData(const std::string &payload) override { data = payload; }

  std::string readData() const override { return data; }
};

// Adaptee: Micro-USB device with its own (incompatible) API
class MicroUSB {
  std::string saved_memory;

public:
  void microPlugIn() {
    std::cout << "[MicroUSB] plugged into micro-USB port\n";
  }

  void microPlugOut() {
    std::cout << "[MicroUSB] plugged out from micro-USB port\n";
  }

  void microTransfer(const std::string &data) { saved_memory = data; }
  std::string microRead() const { return saved_memory; }
};

// Adapter: makes a MicroUSB look like an USB_interface to the Computer
class MicroUSBToUSBAdapter : public USB_interface {
  std::shared_ptr<MicroUSB> device;

public:
  explicit MicroUSBToUSBAdapter(std::shared_ptr<MicroUSB> dev) noexcept
      : device(std::move(dev)) {}

  void connect() override {
    std::cout << "[Adapter] adapting USB connect -> microPlugIn()\n";
    device->microPlugIn();
  }
  void disconnect() override {
    std::cout << "[Adapter] adapting USB disconnect -> microPlugOut()\n";
    device->microPlugOut();
  }
  void sendData(const std::string &payload) override {
    device->microTransfer(payload);
  }
  std::string readData() const override { return device->microRead(); }
};

// Client: the Computer that only knows about USB_interface
class Computer {
  std::vector<std::weak_ptr<USB_interface>> peripherals;

public:
  size_t attach(std::shared_ptr<USB_interface> peripheral) {
    peripheral->connect();

    // find an expired slot to reuse
    for (size_t i = 0; i < peripherals.size(); ++i) {
      if (peripherals[i].expired()) {
        peripherals[i] = peripheral;
        return i;
      }
    }

    peripherals.push_back(peripheral);
    return peripherals.size() - static_cast<size_t>(1);
  }

  void saveFile(size_t peripheral_index, const std::string &data) {
    if (peripherals.size() == 0) {
      std::cout << "[Computer] (save) no device attached\n";
      return;
    }

    if (peripheral_index >= peripherals.size()) {
      std::cout << "[Computer] (save) device not found\n";
      return;
    }

    if (auto peripheral = peripherals[peripheral_index].lock()) {
      peripheral->sendData(data);
    } else {
      std::cout << "[Computer] (save) device not found\n";
      peripherals[peripheral_index].reset(); // tidy up
    }
  }

  std::string readFile(size_t peripheral_index) {
    if (peripherals.size() == 0) {
      std::cout << "[Computer] (read) no device attached\n";
      return "";
    }

    if (peripheral_index >= peripherals.size()) {
      std::cout << "[Computer] (read) device not found\n";
      return "";
    }

    if (auto peripheral = peripherals[peripheral_index].lock()) {
      return peripheral->readData();
    } else {
      std::cout << "[Computer] (read) device expired or removed\n";
      peripherals[peripheral_index].reset();
    }

    return "";
  }
};

int main() {
  Computer pc;

  auto flash = std::make_shared<FlashDrive>();
  size_t flash_idx = pc.attach(flash);

  pc.saveFile(flash_idx, "photo.jpg");
  std::cout << "read flash: " << pc.readFile(flash_idx) << '\n';

  auto micro = std::make_shared<MicroUSB>();
  auto adapter = std::make_shared<MicroUSBToUSBAdapter>(micro);
  size_t adapter_idx = pc.attach(adapter);

  pc.saveFile(adapter_idx, "document.txt");
  std::cout << "read adapter: " << pc.readFile(adapter_idx) << '\n';

  return 0;
}
