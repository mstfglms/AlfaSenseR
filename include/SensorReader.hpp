#pragma once

#include <Arduino.h>

#include "NextionOutput.h"

<<<<<<< codex/review-the-code-txkgdp
struct SensorReadings {
  DisplayValues displayValues;
=======
struct SensorSnapshot {
  DashboardValues dashboardValues;
  uint8_t coolantLevelCode;
>>>>>>> main
};

SensorReadings readSensorReadings();
