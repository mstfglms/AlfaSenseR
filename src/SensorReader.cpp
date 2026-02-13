#include "SensorReader.hpp"
#include "SensorConfig.hpp"
#include "Thermistor.hpp"
#include "coolantcheck.hpp"
#include "PressureReader.hpp"

float readVoltage(uint8_t pin) {
  const int sensorValue = analogRead(pin);
  return sensorValue * (5.0F / 1023.0F);
}

SensorReadings readSensorReadings() {
  SensorReadings sensorData = {
      {
          readTemperature(pins::OT, NPT_NTC),
          readPressure(pins::OP, OP_PRESSURE),
          readTemperature(pins::RIT, M12_NTC),
          readTemperature(pins::ROT, M12_NTC),
          readTemperature(pins::ECT, M12_NTC),
          readTemperature(pins::CHT, M10_NTC),
          readPressure(pins::FP, FP_PRESSURE),
          readCoolantLevel(),
          readVoltage(pins::BATTERY_VOLTAGE) * VOLTAGE_DIVIDER_RATIO,
          readPressure(pins::MAP, MAP_PRESSURE),
          readTemperature(pins::IAT, M12_NTC),
          readTemperature(pins::T7, M12_NTC),
          readTemperature(pins::T8, M12_NTC),
      },
  };

  return sensorData;
}
