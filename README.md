AlfaSenseR 

Overview

This project is a sensor data logger that reads and processes various analog sensor inputs, calculates values such as pressure and temperature, and sends the processed data to a serial output. It is designed to work with multiple types of NTC temperature sensors and pressure sensors.

Features

Reads multiple sensor inputs including pressure, temperature, and voltage.

Uses Steinhart-Hart equations for accurate temperature calculation.

Outputs processed data via serial communication.

Displays coolant level status based on sensor readings.

Hardware Requirements

Microcontroller (e.g., Arduino Mega 2560 mini)

Analog sensors:

Pressure sensors (oil pressure, fuel pressure, MAP sensor, coolant pressure sensor)

Temperature sensors (various NTC sensors: M12, NPT, M10, 1K)

Voltage divider circuit for battery voltage measurement


Software Details

Pin Configuration

#define PIN_OP A0  // Oil Pressure
#define PIN_FP A2  // Fuel Pressure
#define PIN_MAP A4 // Manifold Absolute Pressure
#define PIN_P4 A6  // Coolant Pressure

#define PIN_OT A1  // Oil Temperature
#define PIN_ECT A3 // Engine Coolant Temperature
#define PIN_RIT A5 // Radiator Inlet Temperature
#define PIN_ROT A7 // Radiator Outlet Temperature
#define PIN_CHT A9 // Cylinder Head Temperature
#define PIN_IAT A11 // Intake Air Temperature
#define PIN_T7 A13 // T7 Temperature Sensor
#define PIN_T8 A15 // SCU Temperature Sensor
#define VOLTAGE_PIN A8 // Battery Voltage Measurement

Temperature Calculation

The temperature sensors use the Steinhart-Hart equation:

float inv_Temp = A + B * log(resistance) + C * pow(log(resistance), 3.0);
float temperature = 1.0 / inv_Temp - 273.15;

Where A, B, and C are predefined coefficients for different sensor types.

Coolant Level Detection

The coolant level is determined based on the voltage range:

if (coolant_voltage < 1.0) {
    coolant_level = "NOK";
} else if (coolant_voltage > 4.0) {
    coolant_level = "OK";
} else {
    coolant_level = "ERR";
}

Installation & Usage

Connect the sensors to the appropriate analog pins.

Upload the code to the microcontroller.

Open the serial monitor to view the sensor data output.

Future Enhancements

Can-BUS capability

Data logging to an SD card.

Wireless communication for remote monitoring.

License

MIT License

Author

Mustafa GULMUS

