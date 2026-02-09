#pragma once

#include <Arduino.h>

namespace pins {
constexpr uint8_t OP = A0;
constexpr uint8_t FP = A2;
constexpr uint8_t MAP = A4;
constexpr uint8_t P4 = A6;

constexpr uint8_t OT = A1;
constexpr uint8_t ECT = A3;
constexpr uint8_t RIT = A5;
constexpr uint8_t ROT = A7;
constexpr uint8_t CHT = A9;
constexpr uint8_t IAT = A11;
constexpr uint8_t T7 = A13;
constexpr uint8_t T8 = A15;

constexpr uint8_t BATTERY_VOLTAGE = A8;
constexpr uint8_t DHT_PIN = 3;

constexpr uint8_t THERMO_DO = 46;
constexpr uint8_t THERMO_CS = 47;
constexpr uint8_t THERMO_CLK = 44;
}  // namespace pins

constexpr float VOLTAGE_DIVIDER_RATIO = 3.0715F;
constexpr uint32_t LOOP_DELAY_MS = 250;

struct SteinhartHart {
  float a;
  float b;
  float c;
};

enum SensorType : uint8_t {
  M12_NTC = 0,
  NPT_NTC,
  M10_NTC,
  ONE_K_NTC,
  SENSOR_TYPE_COUNT
};

constexpr SteinhartHart SENSOR_COEFFICIENTS[SENSOR_TYPE_COUNT] = {
    {1.304628145e-3F, 2.579888427e-4F, 1.794777602e-7F},
    {1.511129458e-3F, 2.497079116e-4F, -0.03967365606e-7F},
    {0.3293062200e-3F, 4.042042390e-4F, -6.802609499e-7F},
    {2.117408253e-3F, 1.233985992e-4F, 10.94780921e-7F},
};
