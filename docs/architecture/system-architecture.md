# System Architecture

## Overview

AgriMind is a robotic crop monitoring system developed to collect soil and environmental data from agricultural fields. The project combines embedded hardware, sensors, motor control, and wireless communication to reduce manual field inspection.

The ESP32 acts as the main controller of the system. It reads data from the sensors, controls the rover movement, and sends the collected information to a web dashboard through Wi-Fi.

## Main Components

The system is divided into the following modules:

- Sensor Module
- Processing Module
- Movement Module
- Communication Module
- Monitoring Dashboard

Each module performs a specific task, making the project easier to develop, test, and improve.

## Working Principle

1. The rover moves to the required location.
2. The linear actuator inserts the soil sensor into the ground.
3. Sensor values such as soil moisture, pH, temperature, and pressure are collected.
4. The ESP32 processes the data.
5. The information is displayed on the OLED screen and sent to the web dashboard over Wi-Fi.

## Future Improvements

The current prototype focuses on data collection and monitoring. In future versions, cloud storage, AI-based recommendations, and autonomous navigation can be added.