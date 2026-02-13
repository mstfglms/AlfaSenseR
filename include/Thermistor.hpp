#pragma once

#include <Arduino.h>

#include "SensorConfig.hpp"


float calculateTemperature(float resistance, const SteinhartHart& coefficients);
float readTemperature(uint8_t pin, SensorType sensorType);
