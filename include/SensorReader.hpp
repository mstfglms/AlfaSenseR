#pragma once

#include <Arduino.h>

#include "NextionOutput.hpp"

struct SensorReadings {
  DisplayValues displayValues;
};

SensorReadings readSensorReadings();
