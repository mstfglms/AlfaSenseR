#pragma once

#include <Arduino.h>

#include "NextionOutput.h"

struct SensorSnapshot {
  DashboardValues dashboardValues;
  String coolantLevel;
};

SensorSnapshot readSensorSnapshot();
