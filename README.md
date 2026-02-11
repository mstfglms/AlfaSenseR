# AlfaSenseR

## Overview
This project is a sensor data logger that reads and processes various analog sensor inputs, calculates values such as pressure and temperature, and sends the processed data to a serial output.

## VS Code (PlatformIO) migration
The project has been converted from a single Arduino IDE sketch to a VS Code-friendly structure with PlatformIO.

### New project structure
- `src/main.cpp`: Main firmware logic
- `include/SensorConfig.h`: Pin map and sensor coefficients
- `platformio.ini`: Build/upload/monitor configuration for Arduino Mega 2560
- `.vscode/extensions.json`: Recommended extensions for VS Code

### How to run in VS Code
1. Install **VS Code**.
2. Install the **PlatformIO IDE** extension.
3. Open this folder (`AlfaSenseR`) in VS Code.
4. Connect Arduino Mega 2560.
5. Use PlatformIO actions:
   - **Build**: `pio run`
   - **Upload**: `pio run -t upload`
   - **Serial Monitor**: `pio device monitor`

## Pin configuration
- `PIN_OP A0` // Oil Pressure
- `PIN_FP A2` // Fuel Pressure
- `PIN_MAP A4` // Manifold Absolute Pressure
- `PIN_P4 A6` // Coolant Pressure
- `PIN_OT A1` // Oil Temperature
- `PIN_ECT A3` // Engine Coolant Temperature
- `PIN_RIT A5` // Radiator Inlet Temperature
- `PIN_ROT A7` // Radiator Outlet Temperature
- `PIN_CHT A9` // Cylinder Head Temperature
- `PIN_IAT A11` // Intake Air Temperature
- `PIN_T7 A13` // T7 Temperature Sensor
- `PIN_T8 A15` // SCU Temperature Sensor
- `VOLTAGE_PIN A8` // Battery Voltage Measurement

## Future enhancements
- CAN-BUS capability
- Data logging to SD card
- Wireless communication for remote monitoring

## License
MIT
