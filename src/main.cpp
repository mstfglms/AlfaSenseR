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

  const float otTemperature = readTemperature(pins::OT, NPT_NTC);
  const float ectTemperature = readTemperature(pins::ECT, M12_NTC);
  const float ritTemperature = readTemperature(pins::RIT, M12_NTC);
  const float rotTemperature = readTemperature(pins::ROT, M12_NTC);
  const float chtTemperature = readTemperature(pins::CHT, M10_NTC);
  const float iatTemperature = readTemperature(pins::IAT, M12_NTC);
  const float t7Temperature = readTemperature(pins::T7, M12_NTC);
  const float t8Temperature = readTemperature(pins::T8, M12_NTC);

  const float egtTemperature = thermocouple.readCelsius();
  const float dhtTemperature = dht.readTemperature();
  const float dhtHumidity = dht.readHumidity();
  const float batteryVoltage = readVoltage(pins::BATTERY_VOLTAGE) * VOLTAGE_DIVIDER_RATIO;

  sendNextionNumber(F("n1.val="), otTemperature, 10.0F);
  sendNextionNumber(F("n2.val="), opPressure, 100.0F);
  sendNextionNumber(F("n3.val="), ritTemperature, 100.0F);
  sendNextionNumber(F("n4.val="), rotTemperature, 10.0F);
  sendNextionNumber(F("n5.val="), ectTemperature, 10.0F);
  sendNextionNumber(F("n6.val="), chtTemperature, 10.0F);
  sendNextionNumber(F("n7.val="), fpPressure, 100.0F);

  sendNextionText(F("t8.txt="), coolantLevel);

  sendNextionNumber(F("n9.val="), batteryVoltage, 10.0F);
  sendNextionNumber(F("n10.val="), egtTemperature, 10.0F);
  sendNextionNumber(F("n11.val="), dhtTemperature, 100.0F);
  sendNextionNumber(F("n12.val="), dhtHumidity, 100.0F);
  sendNextionNumber(F("n13.val="), mapPressure, 100.0F);
  sendNextionNumber(F("n14.val="), iatTemperature, 100.0F);
  sendNextionNumber(F("n15.val="), t7Temperature, 100.0F);
  sendNextionNumber(F("n16.val="), t8Temperature, 100.0F);

  delay(LOOP_DELAY_MS);
}
