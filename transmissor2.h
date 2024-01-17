  #include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    IrSender.begin();
}

const uint8_t rawDataP[] PROGMEM = {180, 90, 11, 11, 11, 11, 11, 34, 11, 34, 11, 11, 11, 11, 11, 11, 11,
                                    11, 34, 11, 34, 11, 11, 11, 34, 11, 34, 11, 34, 11, 34, 11, 11,
                                    11, 11, 11, 11, 11, 34, 11, 34, 11, 34, 11, 11, 11, 34, 11, 34,
                                    11, 34, 11, 11, 11, 34, 11, 34, 11, 34, 11, 11, 11, 11, 11, 34, 11};

void loop() {
    const uint16_t rawData[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560,
                                560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690,
                                560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560,
                                560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560,
                                560, 1690};

    IrSender.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ);
    delay(1000);

    IrSender.sendRaw_P(rawDataP, sizeof(rawDataP) / sizeof(rawDataP[0]), NEC_KHZ);
    delay(1000);

    IrSender.sendNEC(0x0102, 0x34, 0);
    delay(3000);
}

