#include <Arduino.h>
#include <DHT.h>
#include <max6675.h>

#include "NextionOutput.h"
#include "SensorConfig.h"
#include "SensorIO.h"

namespace {
MAX6675 thermocouple(pins::THERMO_CLK, pins::THERMO_CS, pins::THERMO_DO);
DHT dht(pins::DHT_PIN, DHT22);
String coolantLevel;
}  // namespace

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  const float opVoltage = readVoltage(pins::OP);
  const float fpVoltage = readVoltage(pins::FP);
  const float mapVoltage = readVoltage(pins::MAP);
  const float coolantVoltage = readVoltage(pins::P4);

  const float opPressure = 2.50F * (opVoltage - 0.5F);
  const float fpPressure = 1.25F * (fpVoltage - 0.5F);
  const float mapPressure = 1.25F * (mapVoltage - 0.5F);

  if (coolantVoltage < 1.0F) {
    coolantLevel = "NOK";
  } else if (coolantVoltage > 4.0F) {
    coolantLevel = "OK";
  } else {
    coolantLevel = "ERR";
  }

  DashboardValues dashboardValues = {
      readTemperature(pins::OT, NPT_NTC),
      opPressure,
      readTemperature(pins::RIT, M12_NTC),
      readTemperature(pins::ROT, M12_NTC),
      readTemperature(pins::ECT, M12_NTC),
      readTemperature(pins::CHT, M10_NTC),
      fpPressure,
      readVoltage(pins::BATTERY_VOLTAGE) * VOLTAGE_DIVIDER_RATIO,
      thermocouple.readCelsius(),
      dht.readTemperature(),
      dht.readHumidity(),
      mapPressure,
      readTemperature(pins::IAT, M12_NTC),
      readTemperature(pins::T7, M12_NTC),
      readTemperature(pins::T8, M12_NTC),
  };

  sendDashboardValues(dashboardValues);
  sendNextionText(F("t8.txt="), coolantLevel);

  delay(LOOP_DELAY_MS);
}
