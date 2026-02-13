#include <Arduino.h>

#include "NextionOutput.hpp"
#include "SensorConfig.hpp"
#include "SensorReader.hpp"

void setup() {
  Serial.begin(9600);
}

void loop() {
  const SensorReadings finalValues = readSensorReadings();

  sendDisplayValues(finalValues.displayValues);

  delay(LOOP_DELAY_MS);
}
