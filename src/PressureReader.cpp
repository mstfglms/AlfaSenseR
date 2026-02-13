#include "PressureReader.hpp"
#include "SensorReader.hpp"
#include "SensorConfig.hpp"

PressureReadings readPressureValues() {
  const float opVoltage = readVoltage(pins::OP);
  const float fpVoltage = readVoltage(pins::FP);
  const float mapVoltage = readVoltage(pins::MAP);

  const float opPressure = PRESSURE_MULTIPLIERS[OP_PRESSURE] * (opVoltage - 0.5F);
  const float fpPressure = PRESSURE_MULTIPLIERS[FP_PRESSURE] * (fpVoltage - 0.5F);
  const float mapPressure = PRESSURE_MULTIPLIERS[MAP_PRESSURE] * (mapVoltage - 0.5F);

  PressureReadings pressureReadings = {
    opPressure,
    fpPressure,
    mapPressure
  };

  return pressureReadings;
}

float readPressure(uint8_t pin, PressureType pressureType) {
  const float voltage = readVoltage(pin);
  return PRESSURE_MULTIPLIERS[pressureType] * (voltage - 0.5F);
}