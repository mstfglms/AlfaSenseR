#include <Arduino.h>
#include <DHT.h>
#include <max6675.h>

#include "NextionOutput.h"
#include "SensorConfig.h"
#include "SensorReader.h"

namespace {
MAX6675 thermocouple(pins::THERMO_CLK, pins::THERMO_CS, pins::THERMO_DO);
DHT dht(pins::DHT_PIN, DHT22);
}  // namespace

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  const SensorSnapshot snapshot = readSensorSnapshot(dht, thermocouple);

  sendDashboardValues(snapshot.dashboardValues);
  sendNextionText(F("t8.txt="), snapshot.coolantLevel);

  delay(LOOP_DELAY_MS);
}
