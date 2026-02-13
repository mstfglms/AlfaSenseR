#include "PressureReader.hpp"
#include "SensorReader.hpp"
#include "SensorConfig.hpp"

PressureReadings readPressureValues() {
  const float opVoltage = readVoltage(pins::OP);
  const float fpVoltage = readVoltage(pins::FP);
  const float mapVoltage = readVoltage(pins::MAP);

  const float opPressure = 2.50F * (opVoltage - 0.5F);
  const float fpPressure = 1.25F * (fpVoltage - 0.5F);
  const float mapPressure = 1.25F * (mapVoltage - 0.5F);

  PressureReadings readings = {
    opPressure,
    fpPressure,
    mapPressure
  };

  return readings;
}