# IoT-Based Energy Meter with ESP32 ⚡️🔋
This project outlines the development of an IoT-based energy meter using an ESP32 microcontroller. The meter monitors energy consumption and safeguards connected devices with a relay. The setup includes an OLED display for local data visualization and sensors for current and voltage measurements.

## Features 🛠️
- Real-time energy monitoring using ESP32.
- OLED display for local energy consumption readings. 📟
- 30A Relay for device protection and control. 🔄
- Current sensor (ACS712 30A) for measuring current. 🔌
- AC voltage sensor (ZMPT101B) for voltage measurements. 🔍
- Wi-Fi connectivity for remote data access and control via a web server or IoT platform. 🌐

## Components Required 🧰
- ESP32 Microcontroller 🎛️
- OLED Display (128x64 or similar) 📺
- 30A Relay Module for load control and protection 🔧
- Current Sensor (ACS712 30A) 🔋
- AC Voltage Sensor Module (ZMPT101B) ⚙️
- Miscellaneous: Resistors, capacitors, connectors, and wiring 🛒

## Circuit Diagram ⚙️
Create the circuit as per the following guidelines:
1. Connect the ACS712 current sensor to the ESP32 for current readings.
2. Connect the ZMPT101B voltage sensor to the ESP32 for AC voltage readings.
3. Connect the OLED display to the ESP32 using I2C (default pins: SDA - GPIO 21, SCL - GPIO 22).
4. Wire the 30A relay to control the connected load and connect it to a GPIO pin of the ESP32.
5. Power the ESP32 and sensors appropriately.

## Circuit Schematic 🖼️
[Include a clear circuit diagram here]

## Software Requirements 💻
1. Arduino IDE (configured for ESP32 development)
2. Libraries:
- Adafruit_SSD1306 and Adafruit_GFX for the OLED display
- WiFi library for network connectivity
- WebServer or AsyncWebServer library for building the web interface
- Arduino_JSON or ArduinoJson for data formatting (optional)

## Usage 🚦
- Connect the meter to your mains supply, and ensure all connections are safe.
- Monitor the energy consumption on the OLED display. 📊
- Access energy readings remotely using a web browser by navigating to the ESP32's IP address. 🌍

## Safety and Precautions ⚠️
- Ensure proper insulation and handling when working with high voltages.
- Double-check connections before powering up.
- Use appropriate current and voltage ratings to avoid overloading the sensors or the relay.

## Future Enhancements 🌟
- Integrate with cloud platforms like ThingSpeak or Firebase for data logging. ☁️
- Add overcurrent and overvoltage protection logic for safer operation. 🔒
- Develop a mobile app for more accessible monitoring and control. 📱
