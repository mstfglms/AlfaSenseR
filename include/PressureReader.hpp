#pragma once

#include <Arduino.h>
#include "SensorConfig.hpp"

struct PressureReadings {
  float opPressure;
  float fpPressure;
  float mapPressure;
};

PressureReadings readPressureValues();

float readPressure(uint8_t pin, PressureType pressureType);