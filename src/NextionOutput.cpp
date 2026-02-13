#include "NextionOutput.hpp"

namespace {
struct NextionNumericUpdate {
  const __FlashStringHelper* key;
  float value;
  float multiplier;
};

void sendDashboardUpdates(const NextionNumericUpdate* updates, size_t count) {
  for (size_t i = 0; i < count; ++i) {
    sendNextionNumber(updates[i].key, updates[i].value, updates[i].multiplier);
  }
}
}  // namespace

void sendNextionNumber(const __FlashStringHelper* key, int value, float multiplier) {
  Serial.print(key);
  Serial.print(static_cast<int>(value * multiplier));
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFF);
}

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

void sendDisplayValues(const DisplayValues& values) {
  const NextionNumericUpdate updates[] = {
      {F("n1.val="), values.otTemperature, 10.0F},   {F("n2.val="), values.opPressure, 100.0F},
      {F("n3.val="), values.ritTemperature, 100.0F}, {F("n4.val="), values.rotTemperature, 10.0F},
      {F("n5.val="), values.ectTemperature, 10.0F},  {F("n6.val="), values.chtTemperature, 10.0F},
      {F("n7.val="), values.fpPressure, 100.0F},     {F("n9.val="), values.batteryVoltage, 10.0F},
      {F("n13.val="), values.mapPressure, 100.0F},   {F("n14.val="), values.iatTemperature, 100.0F},
      {F("n15.val="), values.t7Temperature, 100.0F}, {F("n16.val="), values.t8Temperature, 100.0F},
  };

  sendDashboardUpdates(updates, sizeof(updates) / sizeof(updates[0]));

  // Send coolant level separately as int
  sendNextionNumber(F("n8.val="), values.coolantLevelCode, 1.0F);
}
