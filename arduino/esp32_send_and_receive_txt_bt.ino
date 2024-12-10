 #include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial esp32_bt;

void setup() {
  Serial.begin(115200);
  esp32_bt.begin("esp32-bluetooth");
}

void loop() {
  if (Serial.available()) {
    Serial.println("Sending Data...");

    String msg = Serial.readString();
    esp32_bt.println(msg);

    Serial.println("Data Sent");
  } else if (esp32_bt.available()) {
    String receivedText = esp32_bt.readString();

    Serial.print("Received Data: ");
    Serial.println(receivedText);
  }
}
