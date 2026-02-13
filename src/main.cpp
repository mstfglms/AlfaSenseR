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
  sendNextionText(F("t8.txt="), snapshot.coolantLevel);

  delay(LOOP_DELAY_MS);
}
