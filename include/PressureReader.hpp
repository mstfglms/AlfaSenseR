#pragma once

#include <Arduino.h>

struct PressureReadings {
  float opPressure;
  float fpPressure;
  float mapPressure;
};

PressureReadings readPressureValues();