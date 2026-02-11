#include "SensorIO.h"

float readVoltage(uint8_t pin) {
  const int sensorValue = analogRead(pin);
  return sensorValue * (5.0F / 1023.0F);
}

float calculateTemperature(float resistance, const SteinhartHart& coefficients) {
  const float logResistance = log(resistance);
  const float invTemp = coefficients.a + coefficients.b * logResistance +
                        coefficients.c * pow(logResistance, 3.0F);
  return (1.0F / invTemp) - 273.15F;
}

float readTemperature(uint8_t pin, SensorType sensorType) {
  const float voltage = readVoltage(pin);
  if (voltage < 0.1F) {
    return 0.0F;
  }

  const float buffer = (5.0F / voltage) - 1.0F;
  const float resistance = 1000.0F * buffer;
  return calculateTemperature(resistance, SENSOR_COEFFICIENTS[sensorType]);
}
