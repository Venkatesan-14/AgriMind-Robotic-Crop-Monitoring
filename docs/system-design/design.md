# System Design

## Design Objective

The main objective of AgriMind is to simplify field monitoring by collecting important soil and environmental data using a mobile robotic platform. The system is designed as a prototype that combines embedded hardware, sensors, and wireless communication into a single solution.

## Design Approach

The project follows a modular design, where each part of the system performs a specific function. This makes the prototype easier to develop, test, and improve.

The major modules include:

- Sensor Module
- ESP32 Controller
- Motor Control System
- Communication Module
- Monitoring Dashboard

Each module works together to complete the data collection process.

## System Workflow

The working sequence of the prototype is as follows:

1. The rover moves to the required location.
2. The linear actuator places the soil sensor into the ground.
3. Sensor values are collected.
4. The ESP32 processes the data.
5. The information is displayed on the OLED screen.
6. The same data is transmitted to the web dashboard through Wi-Fi.

## Design Considerations

While developing the prototype, the following factors were considered:

- Simple hardware integration
- Easy maintenance
- Low development cost
- Wireless monitoring
- Expandability for future improvements

## Future Scope

The current prototype demonstrates the basic concept of robotic crop monitoring. Future versions can include autonomous navigation, cloud storage, AI-based analysis, and support for additional agricultural sensors.