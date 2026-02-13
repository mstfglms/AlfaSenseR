#pragma once

#include <Arduino.h>

#define COOLANT_LEVEL_NOK 0
#define COOLANT_LEVEL_OK 1
#define COOLANT_LEVEL_ERR 2

uint8_t detectCoolantLevelCode(float coolantVoltage);