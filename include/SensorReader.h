#pragma once

#include <Arduino.h>
#include <DHT.h>
#include <max6675.h>

#include "NextionOutput.h"

struct SensorSnapshot {
  DashboardValues dashboardValues;
  String coolantLevel;
};

SensorSnapshot readSensorSnapshot(DHT& dht, MAX6675& thermocouple);
