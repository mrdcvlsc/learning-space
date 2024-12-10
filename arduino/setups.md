# Setting Up Arduino/ESP32/ESP8266/ETC.

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
