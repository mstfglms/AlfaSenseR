#include "SensorReader.h"

#include "SensorConfig.h"
#include "SensorIO.h"

namespace {
String detectCoolantLevel(float coolantVoltage) {
  if (coolantVoltage < 1.0F) {
    return "NOK";
  }
  if (coolantVoltage > 4.0F) {
    return "OK";
  }
  return "ERR";
}
}  // namespace

SensorSnapshot readSensorSnapshot() {
  const float opVoltage = readVoltage(pins::OP);
  const float fpVoltage = readVoltage(pins::FP);
  const float mapVoltage = readVoltage(pins::MAP);
  const float coolantVoltage = readVoltage(pins::P4);

  const float opPressure = 2.50F * (opVoltage - 0.5F);
  const float fpPressure = 1.25F * (fpVoltage - 0.5F);
  const float mapPressure = 1.25F * (mapVoltage - 0.5F);

  SensorSnapshot snapshot = {
      {
          readTemperature(pins::OT, NPT_NTC),
          opPressure,
          readTemperature(pins::RIT, M12_NTC),
          readTemperature(pins::ROT, M12_NTC),
          readTemperature(pins::ECT, M12_NTC),
          readTemperature(pins::CHT, M10_NTC),
          fpPressure,
          readVoltage(pins::BATTERY_VOLTAGE) * VOLTAGE_DIVIDER_RATIO,
          mapPressure,
          readTemperature(pins::IAT, M12_NTC),
          readTemperature(pins::T7, M12_NTC),
          readTemperature(pins::T8, M12_NTC),
      },
      detectCoolantLevel(coolantVoltage),
  };

  return snapshot;
}
