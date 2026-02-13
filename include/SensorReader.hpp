#pragma once

#include <Arduino.h>

#include "NextionOutput.hpp"

struct SensorReadings {
  DisplayValues displayValues;
};

float readVoltage(uint8_t pin);

SensorReadings readSensorReadings();
