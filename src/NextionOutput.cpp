#include "NextionOutput.h"

void sendNextionNumber(const __FlashStringHelper* key, float value, float multiplier) {
  Serial.print(key);
  Serial.print(value * multiplier, 0);
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFF);
}

void sendNextionText(const __FlashStringHelper* key, const String& value) {
  Serial.print(key);
  Serial.print('"');
  Serial.print(value);
  Serial.print('"');
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFF);
}
