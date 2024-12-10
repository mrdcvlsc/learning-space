# Setting Up Arduino/ESP32/ESP8266/ETC.

## ESP32 Setup

NOTE: **Libraries** and **Board Managers** are two different thing

1. Install `esp32` by **Espressif Systems** in the board manager.
2. `Tools` > `Board` > `esp32` > Select `ESP32 Dev Module`.

## Allowing physical port in Ubuntu

```bash
# Display All Connected Ports
ls /dev/*

# Display All Connected Arduino Ports
ls /dev/ttyACM*

# Display All Connectd USB Ports (this is also for ESP32 and ESP8266 both USB)
ls /dev/ttyUSB*

# Allow A Port (Example : /dev/ttyACM0)
sudo chmod a+rw /dev/ttyACM0
```
