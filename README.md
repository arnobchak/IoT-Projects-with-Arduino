# IoT Projects with Arduino UNO

## Overview
This repository contains a collection of IoT projects utilizing the Arduino UNO board with various sensors and components. These projects demonstrate how to interface the Arduino UNO with sensors and actuators, transmit data using LoRaWAN, and visualize it on displays. Each project includes a detailed explanation, circuit diagram, and source code.

## Components Used
- **Arduino UNO**: The microcontroller board used for all the projects.
- **Ultrasonic Sensor**: For distance measurement.
- **Air Quality Sensor**: To monitor air quality levels.
- **LoRaWAN Modules (Sender and Receiver)**: For long-range wireless communication.
- **DHT11 Sensor**: For temperature and humidity measurements.
- **LED**: For visual indications.
- **Push Button**: For user input.
- **Relay Module**: To control high-power devices.
- **16x2 LCD Display**: To display data locally.

## Project List

### 1. Distance Measurement with Ultrasonic Sensor
**Description**: Measure the distance of an object using the ultrasonic sensor and display it on the LCD.
- **Components**: Ultrasonic sensor, LCD display.
- **Features**:
  - Display real-time distance on the LCD.
  - Trigger an LED when an object is too close.
- **Applications**: Obstacle detection, parking systems.

### 2. Air Quality Monitoring
**Description**: Monitor air quality using an air quality sensor and log the data.
- **Components**: Air quality sensor, LoRaWAN sender and receiver, LCD display.
- **Features**:
  - Send real-time air quality data over LoRaWAN.
  - Display data locally on the LCD.
- **Applications**: Environmental monitoring, smart city solutions.

### 3. Temperature and Humidity Monitoring
**Description**: Measure and display temperature and humidity using the DHT11 sensor.
- **Components**: DHT11 sensor, LoRaWAN sender and receiver, LCD display.
- **Features**:
  - Transmit temperature and humidity data via LoRaWAN.
  - Display data on the LCD.
- **Applications**: Weather stations, HVAC systems.

### 4. Remote Control with LoRaWAN
**Description**: Use LoRaWAN to control devices remotely.
- **Components**: LoRaWAN modules (sender and receiver), relay module, push button, LED.
- **Features**:
  - Control an LED or other device connected to the relay remotely.
  - Use the push button to send control signals.
- **Applications**: Home automation, industrial control.

### 5. Combined IoT Dashboard
**Description**: Create a comprehensive IoT solution integrating all sensors and components.
- **Components**: All sensors and actuators listed above.
- **Features**:
  - Collect data from multiple sensors.
  - Display aggregated data on the LCD and send it via LoRaWAN.
  - Implement control features using the relay and push button.
- **Applications**: Smart home, industrial IoT systems.

## Circuit Diagrams
Circuit diagrams for each project are included in the `/circuit_diagrams` folder.

## Source Code
The source code for each project is available in the `/source_code` folder. Each project folder contains:
- `main.ino`: The Arduino sketch.
- `README.md`: Instructions for setting up and running the project.

## Setup and Usage
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/IoT-Projects-Arduino-UNO.git
   ```
2. Navigate to the desired project folder.
3. Follow the instructions in the `README.md` file to set up the hardware and upload the code.

## Requirements
- Arduino IDE
- Libraries:
  - `LiquidCrystal.h` for LCD display
  - `DHT.h` for DHT11 sensor
  - `LoRa.h` for LoRaWAN communication

## Future Enhancements
- Integrate MQTT for real-time data visualization on cloud platforms.
- Add support for other air quality and environmental sensors.
- Implement data logging using an SD card module.

## Contributing
Contributions are welcome! Please fork the repository, make your changes, and submit a pull request.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

