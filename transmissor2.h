#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>

#define IR_SEND_PIN         3

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    IrSender.begin();
}

const uint16_t rawData[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560,
                            560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690,
                            560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560,
                            560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560,
                            560, 1690};

void loop() {
    IrSender.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), NEC_KHZ);
    delay(1000);
}
