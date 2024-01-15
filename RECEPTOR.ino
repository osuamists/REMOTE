#include <IRLibRecvPCI.h>

IRrecvPCI myReceiver(2);

void setup () {
  Serial.begin(9600);
  myReceiver.enableIRIn();
  Serial.println("Preparado para receber sinais!");
  
}

void loop () {
  if (myReceiver.getResults()) {
    Serial.println(" \n\n-------------------");
    Serial.println("Sinal recebido");

    Serial.println(F("\n#define RAW_DATA_LEN"));
    Serial.println(recvGlobal.recvLength, DEC);

    Serial.println(F("uint16_t rawData[RAW_DATA_LEN]={\n"));
    for (bufIndex_t i = 1; i < recvGlobal.recvLength; i++ ) {
      Serial.println(recvGlobal.recvBuffer[i], DEC);
      Serial.println(F(","));

      if (( i % 8 ) == 0) {
        Serial.print(F("\n"));
      }
      
    }

    Serial.println(F("1000};"));
    Serial.println("-------------------");

    myReceiver.enableIRIn();
  }
}
