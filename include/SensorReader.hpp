#pragma once

#include <Arduino.h>

#include "NextionOutput.h"

struct SensorReadings {
  DisplayValues displayValues;
};

SensorReadings readSensorReadings();
