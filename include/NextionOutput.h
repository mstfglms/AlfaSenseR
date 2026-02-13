#pragma once

#include <Arduino.h>

struct DisplayValues {
  float otTemperature;
  float opPressure;
  float ritTemperature;
  float rotTemperature;
  float ectTemperature;
  float chtTemperature;
  float fpPressure;
  uint8_t coolantLevelCode;
  float batteryVoltage;
  float mapPressure;
  float iatTemperature;
  float t7Temperature;
  float t8Temperature;
};

void sendNextionNumber(const __FlashStringHelper* key, float value, float multiplier);
void sendNextionText(const __FlashStringHelper* key, const String& value);
void sendDisplayValues(const DisplayValues& values);
