#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t IrPin = 17; // ESP32 GPIO pin to use. Recommended: (D4).

IRsend irsend(IrPin);  // Set the GPIO to be used to sending the message.

uint16_t rawData[227] = {3760, 1768, 432, 1352, 432, 1348, 436, 360, 432, 360, 432, 360, 436, 1340, 440, 356, 436, 352, 440, 1344, 440, 1340, 440, 356, 436, 1344, 440, 352, 436, 356, 436, 1344, 440, 1340, 444, 348, 444, 1336, 444, 1340, 440, 356, 440, 348, 440, 1344, 436, 356, 436, 352, 440, 1340, 440, 356, 436, 352, 440, 352, 440, 352, 440, 352, 436, 352, 444, 348, 440, 352, 440, 352, 436, 360, 432, 356, 436, 352, 440, 352, 440, 352, 440, 352, 436, 352, 440, 352, 440, 352, 440, 352, 436, 356, 440, 1336, 444, 352, 440, 352, 436, 1344, 440, 1340, 444, 352, 436, 352, 444, 348, 440, 352, 440, 348, 444, 348, 440, 352, 440, 1340, 444, 1340, 440, 1340, 444, 352, 440, 348, 444, 348, 440, 352, 440, 352, 440, 348, 444, 348, 440, 1340, 444, 1340, 440, 1340, 444, 352, 440, 352, 440, 348, 444, 348, 440, 352, 440, 352, 440, 352, 440, 348, 440, 352, 440, 352, 440, 352, 440, 348, 440, 352, 440, 352, 440, 352, 440, 380, 412, 352, 436, 352, 440, 352, 440, 352, 440, 352, 436, 356, 436, 356, 436, 352, 440, 348, 444, 352, 436, 356, 436, 356, 436, 356, 436, 352, 440, 352, 436, 352, 440, 356, 436, 352, 440, 352, 440, 1340, 440, 1344, 440, 1340, 440, 1340, 444, 1340, 440, 1340, 444, 352, 440};

void setup() {
  irsend.begin();
#if ESP8266
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
#else  // ESP8266
  Serial.begin(115200, SERIAL_8N1);
#endif  // ESP8266
}

void loop() {
  Serial.println("a powerOn capture from IRrecvDumpV2");
  irsend.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), 38);  // Send a raw data capture at 38kHz.
  delay(2000);
}