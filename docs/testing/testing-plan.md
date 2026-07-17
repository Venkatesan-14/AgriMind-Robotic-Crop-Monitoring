# Testing Plan

## Introduction

Testing was carried out throughout the development of AgriMind to ensure that both the hardware and software worked as expected. Individual components were tested first before integrating them into the complete system.

## Sensor Testing

Each sensor was tested independently to verify that it produced stable and reliable readings.

The following sensors were tested:

- Soil Moisture Sensor
- Soil pH Sensor
- BMP280 Temperature and Pressure Sensor
- GPS Module

The sensor values were displayed on both the OLED screen and the web dashboard to confirm correct operation.

## Motor Testing

The rover movement was tested in different directions to ensure proper motor control.

The following movements were verified:

- Forward
- Reverse
- Left Turn
- Right Turn
- Stop

The linear actuator was also tested to check smooth insertion and retraction of the soil sensor.

## Communication Testing

The ESP32 Wi-Fi connection was tested by sending sensor data to the dashboard.

The dashboard was tested repeatedly while tuning the Wi-Fi connection to reduce communication interruptions.

The following points were verified:

- Wi-Fi connection
- Dashboard updates
- OLED display output
- Data transmission without interruption

## Overall Testing

After testing each module separately, the complete system was tested as a single prototype. The rover successfully collected sensor data and transmitted the information to the monitoring dashboard.

## Future Testing

Future work can include long-duration field testing, battery performance analysis, communication range testing, and testing under different environmental conditions.