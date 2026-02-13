#pragma once

#include <Arduino.h>

#include "NextionOutput.h"

struct SensorSnapshot {
  DashboardValues dashboardValues;
  uint8_t coolantLevelCode;
};

SensorSnapshot readSensorSnapshot();
