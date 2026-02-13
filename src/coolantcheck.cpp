#include "SensorReader.hpp"
#include "SensorConfig.hpp"
#include "Thermistor.hpp"
#include "coolantcheck.hpp"

uint8_t detectCoolantLevelCode(float coolantVoltage) {
  if (coolantVoltage < 1.0F) {
    return COOLANT_LEVEL_NOK;
  }
  if (coolantVoltage > 4.0F) {
    return COOLANT_LEVEL_OK;
  }
  return COOLANT_LEVEL_ERR;
}

uint8_t readCoolantLevel() {
  const float coolantVoltage = readVoltage(pins::P4);
  return detectCoolantLevelCode(coolantVoltage);
}
