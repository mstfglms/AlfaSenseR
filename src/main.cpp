#include <Arduino.h>

#include "NextionOutput.h"
#include "SensorConfig.h"
#include "SensorReader.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  const SensorSnapshot snapshot = readSensorSnapshot();

  sendDashboardValues(snapshot.dashboardValues);
  sendNextionText(F("t8.txt="), snapshot.coolantLevel);

  delay(LOOP_DELAY_MS);
}
