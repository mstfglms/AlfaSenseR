#include <Arduino.h>

#include "NextionOutput.h"
#include "SensorConfig.hpp"
#include "SensorReader.hpp"

void setup() {
  Serial.begin(9600);
}

void loop() {
  const SensorReadings readings = readSensorReadings();

  sendDisplayValues(readings.displayValues);

  delay(LOOP_DELAY_MS);
}
