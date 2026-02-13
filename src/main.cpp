#include <Arduino.h>

#include "NextionOutput.h"
#include "SensorConfig.hpp"
#include "SensorReader.hpp"

void setup() {
  Serial.begin(9600);
}

void loop() {
  const SensorSnapshot snapshot = readSensorSnapshot();

  sendDashboardValues(snapshot.dashboardValues);
  sendNextionNumber(F("n8.val="), snapshot.coolantLevelCode, 1.0F);

  delay(LOOP_DELAY_MS);
}
