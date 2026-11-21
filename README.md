# IoT-Based Automatic Water Dispenser Using ESP8266 and KiwisIoT Platform

## 📌 Project Overview

The **IoT-Based Automatic Water Dispenser** is designed using the ESP8266 NodeMCU, IR sensor, relay module, and water pump. The system automatically detects an object using the IR sensor and activates the water pump for a predefined duration.

The project is integrated with the **KiwisIoT Platform**, allowing users to monitor the pump and dispenser status through cloud-based channels.

## 🎯 Objectives

- To develop an automatic water dispensing system.
- To detect objects using an IR sensor.
- To control the water pump using a relay module.
- To monitor dispenser status through the KiwisIoT platform.
- To reduce manual operation and improve convenience.

##

## ☁️ KiwisIoT Platform Integration

The system uses the KiwisIoT platform for cloud-based monitoring.

| Channel   | Parameter        | Description     |
| --------- | ---------------- | --------------- |
| Channel 0 | Pump Status      | 1 = ON, 0 = OFF |
| Channel 1 | Dispenser Status | ON / OFF        |

## ⚙️ Working Principle

1. The IR sensor continuously detects the presence of an object.
2. When an object is detected, the ESP8266 processes the sensor signal.
3. The relay module is activated, turning ON the water pump.
4. The LED indicates that the dispenser is active.
5. The pump dispenses water for approximately 2 seconds.
6. After the specified duration, the pump automatically turns OFF.
7. The pump and dispenser status are updated on the KiwisIoT cloud platform.
8. The system waits until the object is removed before detecting another object.

## 💻 Source Code

The complete Arduino source code for this project is available below:

[water dispenser.ino](water%20dispenser.ino)

## 📸 Project Output

![Water Dispenser](WATER%20DESPENSER.jpeg)

## 📊 Water Dispenser Dashboard Output

![Water Dispenser Dashboard Output](Water%20dispenser%20Dashboard%20output.jpeg)

## 💻 Software Requirements

- Arduino IDE
- ESP8266 Board Package
- ESP8266WiFi Library
- KiwisIoT Library
- KiwisIoT Cloud Platform

## 🌟 Applications

- Automatic drinking water dispensers
- Touchless water dispensing systems
- Smart water management
- Public water dispensing units
- IoT-based automation systems

## 🚀 Future Enhancements

- Add water-level monitoring.
- Integrate a flow sensor to measure water consumption.
- Implement mobile notifications.
