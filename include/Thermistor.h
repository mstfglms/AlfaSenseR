#pragma once

#include <Arduino.h>

#include "SensorConfig.h"

float readVoltage(uint8_t pin);
float calculateTemperature(float resistance, const SteinhartHart& coefficients);
float readTemperature(uint8_t pin, SensorType sensorType);
float voltageToResistance(float voltage);
