# Communication

## Introduction

Communication plays an important role in AgriMind by allowing sensor data collected by the rover to be viewed on a monitoring dashboard. The current prototype uses Wi-Fi communication through the ESP32.

## Communication Flow

The communication process follows these steps:

1. Sensors collect data from the field.
2. The ESP32 processes the sensor readings.
3. The processed data is transmitted using Wi-Fi.
4. The web dashboard receives and displays the information in real time.

## Data Transmitted

The following information is sent to the dashboard:

- Soil Moisture
- Soil pH
- Temperature
- Pressure
- GPS Coordinates

This allows the user to monitor field conditions without manually checking each sensor.

## Why Wi-Fi?

Wi-Fi was selected for the prototype because it is easy to configure, provides fast communication, and is suitable for demonstration and testing purposes.

## Future Improvements

The communication system can be expanded by integrating technologies such as LoRa, GSM, or cloud platforms for long-distance monitoring and data storage.