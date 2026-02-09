#pragma once

#include <Arduino.h>

void sendNextionNumber(const __FlashStringHelper* key, float value, float multiplier);
void sendNextionText(const __FlashStringHelper* key, const String& value);
