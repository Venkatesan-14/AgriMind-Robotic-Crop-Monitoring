# Hardware Overview

## Introduction

The AgriMind prototype is built using commonly available embedded system components. The hardware was selected based on cost, availability, and ease of integration while developing the prototype.

## Main Components

### ESP32

The ESP32 is the main controller of the project. It reads sensor data, controls the motors, and manages Wi-Fi communication with the monitoring dashboard.

### Sensors

The following sensors are used to collect field information:

- Soil Moisture Sensor
- Soil pH Sensor
- BMP280 Sensor (Temperature and Pressure)
- GPS Module

These sensors provide the information required to monitor the condition of the agricultural field.

### Motor System

The movement of the rover is controlled using DC motors connected through L298N motor drivers.

A linear actuator is used to insert the soil sensor into the ground before taking measurements.

### Power Supply

The prototype is powered using a rechargeable Li-ion battery. A buck converter is used to provide a stable operating voltage for the electronic components.

## Hardware Design Approach

The hardware was designed so that each module can be replaced or upgraded without making major changes to the overall system. This modular approach also makes troubleshooting easier during development.