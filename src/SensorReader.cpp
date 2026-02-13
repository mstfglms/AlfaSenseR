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
  const float coolantVoltage = readVoltage(pins::P4);

  const PressureReadings pressures = readPressureValues();

  SensorReadings readings = {
      {
          readTemperature(pins::OT, NPT_NTC),
          pressures.opPressure,
          readTemperature(pins::RIT, M12_NTC),
          readTemperature(pins::ROT, M12_NTC),
          readTemperature(pins::ECT, M12_NTC),
          readTemperature(pins::CHT, M10_NTC),
          pressures.fpPressure,
          detectCoolantLevelCode(coolantVoltage),
          readVoltage(pins::BATTERY_VOLTAGE) * VOLTAGE_DIVIDER_RATIO,
          pressures.mapPressure,
          readTemperature(pins::IAT, M12_NTC),
          readTemperature(pins::T7, M12_NTC),
          readTemperature(pins::T8, M12_NTC),
      },
  };

  return readings;
}
