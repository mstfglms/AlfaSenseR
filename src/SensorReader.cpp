#include "SensorReader.hpp"

#include "SensorConfig.hpp"
#include "Thermistor.hpp"

namespace {
constexpr uint8_t COOLANT_LEVEL_NOK = 0;
constexpr uint8_t COOLANT_LEVEL_OK = 1;
constexpr uint8_t COOLANT_LEVEL_ERR = 2;

uint8_t detectCoolantLevelCode(float coolantVoltage) {
  if (coolantVoltage < 1.0F) {
    return COOLANT_LEVEL_NOK;
  }
  if (coolantVoltage > 4.0F) {
    return COOLANT_LEVEL_OK;
  }
  return COOLANT_LEVEL_ERR;
}
}  // namespace

SensorReadings readSensorReadings() {
  const float opVoltage = readVoltage(pins::OP);
  const float fpVoltage = readVoltage(pins::FP);
  const float mapVoltage = readVoltage(pins::MAP);
  const float coolantVoltage = readVoltage(pins::P4);

  const float opPressure = 2.50F * (opVoltage - 0.5F);
  const float fpPressure = 1.25F * (fpVoltage - 0.5F);
  const float mapPressure = 1.25F * (mapVoltage - 0.5F);

  SensorReadings readings = {
      {
          readTemperature(pins::OT, NPT_NTC),
          opPressure,
          readTemperature(pins::RIT, M12_NTC),
          readTemperature(pins::ROT, M12_NTC),
          readTemperature(pins::ECT, M12_NTC),
          readTemperature(pins::CHT, M10_NTC),
          fpPressure,
          detectCoolantLevelCode(coolantVoltage),
          readVoltage(pins::BATTERY_VOLTAGE) * VOLTAGE_DIVIDER_RATIO,
          mapPressure,
          readTemperature(pins::IAT, M12_NTC),
          readTemperature(pins::T7, M12_NTC),
          readTemperature(pins::T8, M12_NTC),
      },
  };

  return readings;
}
