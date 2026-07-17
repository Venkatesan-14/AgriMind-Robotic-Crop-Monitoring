# Software Overview

## Introduction

The software for AgriMind is responsible for controlling the rover, collecting sensor data, and displaying the information to the user. The project was developed using the Arduino IDE, with the ESP32 acting as the main controller.

The software is divided into small modules so that each function can be developed and tested independently.

## Main Software Modules

### Sensor Module

This module reads data from all connected sensors, including the soil moisture sensor, soil pH sensor, BMP280 sensor, and GPS module. The collected values are processed before being displayed.

### Motor Control Module

The motor control module manages the movement of the rover. It controls forward and reverse movement, turning, and the operation of the linear actuator used for inserting the soil sensor into the ground.

### Communication Module

The ESP32 uses its built-in Wi-Fi capability to send sensor readings to the web dashboard. This allows the user to monitor field conditions without connecting directly to the rover.

### Display Module

An OLED display is used to show important sensor values during field testing. This helps verify that the sensors are working correctly even without opening the dashboard.

## Software Design

Each module performs a specific task, making the program easier to understand and maintain. This approach also makes it easier to add new sensors or features in future versions of the project.

## Future Improvements

Future versions of the software can include cloud data storage, automatic report generation, AI-based recommendations, and autonomous navigation.