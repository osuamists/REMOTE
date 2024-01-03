#include <IRLibRecvPCI.h>


IRrecvPCI myReceiver(2);


void setup () {
    Serial.begin(9600);
    delay(2000); while (!Serial);
    myReceiver.enableIRIn();  
    Serial.println(F("Pronto para receber sinais IR"));
    myReceiver.setFrameTimeout(100000);    
}

void loop(){
  if(myReceiver.getResults()){
    Serial.println(F("Recorte e cole as seguintes linhas no"));
    Serial.println(F("local designado em rawSend.ino"));
    Serial.println(F("\n#define RAW_DATA_LEN"));
    Serial.println(recvGlobal.recvLength,DEC);
    Serial.println(F("uint16_t rawData[RAW_DATA_LEN]={\n\t"));
     for(bufIndex_t i=1;i<recvGlobal.recvLength; i++) {
      Serial.println(recvGlobal.recvBuffer[i],DEC);
      Serial.print(F(", "));
       if ( (i % 8)==0) Serial.print(F("\n\t"));
    }
    Serial.println(F("1000};"));
    myReceiver.enableIRIn();
  }
}  
