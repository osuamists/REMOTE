#include <Arduino.h>

#include "PinDefinitionsAndMore.h" // Define macros for input and output pin, etc.

#if !defined(RAW_BUFFER_LENGTH)
#  if RAMEND <= 0x4FF || RAMSIZE < 0x4FF
#define RAW_BUFFER_LENGTH  180  // 750 (600 if we have only 2k RAM) é o valor para controles remotos de ar-condicionado. O padrão é 112 se DECODE_MAGIQUEST estiver habilitado; caso contrário, é 100.
#  elif RAMEND <= 0x8FF || RAMSIZE < 0x8FF
#define RAW_BUFFER_LENGTH  600  // 750 (600 if we have only 2k RAM) é o valor para controles remotos de ar-condicionado. O padrão é 112 se DECODE_MAGIQUEST estiver habilitado; caso contrário, é 100.
#  else
#define RAW_BUFFER_LENGTH  750  // 750 (600 if we have only 2k RAM) é o valor para controles remotos de ar-condicionado. O padrão é 112 se DECODE_MAGIQUEST estiver habilitado; caso contrário, é 100.
#  endif
#endif

#define MARK_EXCESS_MICROS    20    // Adapte para o módulo receptor IR utilizado. 20 é recomendado para os módulos baratos VS1838.

//#define RECORD_GAP_MICROS 12000 // O padrão é 5000. Ative para alguns protocolos de ar-condicionado LG.
//#define DEBUG // Ative isso para obter muita saída de depuração dos decodificadores.

#include <IRremote.hpp>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);   // A mensagem de status será enviada para o PC a 9600 bauds
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_PORT_USBVIRTUAL) || defined(SERIAL_USB) /*stm32duino*/|| defined(USBCON) /*STM32_stm32*/|| defined(SERIALUSB_PID) || defined(ARDUINO_attiny3217)
    delay(4000); // Para poder conectar o Monitor Serial após a reinicialização ou ligação e antes da primeira impressão. Não espere por um Monitor Serial conectado!
#endif
    // Apenas para saber qual programa está sendo executado no meu Arduino
    Serial.println(F("INÍCIO " __FILE__ " de " __DATE__ "\r\nUsando a versão da biblioteca " VERSION_IRREMOTE));

    // Inicia o receptor e, se não for especificado o terceiro parâmetro, utiliza o pino LED_BUILTIN das placas internas como LED de feedback padrão
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

    Serial.print(F("Pronto para receber sinais IR dos protocolos: "));
    printActiveIRProtocols(&Serial);
    Serial.println(F("no pino " STR(IR_RECEIVE_PIN)));

    // Informações para a recepção
    Serial.print(RECORD_GAP_MICROS);
    Serial.println(F(" us é o intervalo (mínimo), após o qual o início de um novo pacote IR é assumido"));
    Serial.print(MARK_EXCESS_MICROS);
    Serial.println();
    Serial.println(F("Devido à saída detalhada (>200 ms a 115200), as repetições provavelmente não são registradas corretamente!"));
    Serial.println();
}

//+=============================================================================
// A seção de repetição do código
//
void loop() {
    if (IrReceiver.decode()) {  // Captura um código IR
        // A 115200 bauds, a impressão leva 200 ms para o protocolo NEC e 70 ms para a repetição NEC
        Serial.println(); // linha em branco entre as entradas
        Serial.println(); // 2 linhas em branco entre as entradas
        IrReceiver.printIRResultShort(&Serial);
        // Verifica se o buffer transbordou
        if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_WAS_OVERFLOW) {
            Serial.println(F("Tente aumentar o valor de \"RAW_BUFFER_LENGTH\" para " STR(RAW_BUFFER_LENGTH) " em " __FILE__));
            // veja também https://github.com/Arduino-IRremote/Arduino-IRremote#compile-options--macros-for-this-library
        } else {
            if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
                Serial.println(F("Recebido ruído ou um protocolo desconhecido (ou ainda não habilitado)"));
            }
            Serial.println();
            IrReceiver.printIRSendUsage(&Serial);
            Serial.println();
            Serial.println(F("Resultado bruto em ticks internos (50 us) - com espaço inicial"));
            IrReceiver.printIRResultRawFormatted(&Serial, false); // Saída dos resultados em formato RAW
            Serial.println(F("Resultado bruto em microssegundos - com espaço inicial"));
            IrReceiver.printIRResultRawFormatted(&Serial, true);  // Saída dos resultados em formato RAW
            Serial.println();                               // linha em branco entre as entradas
            Serial.print(F("Resultado como array de ticks internos de 8 bits (50 us) - compensado com MARK_EXCESS_MICROS="));
            Serial.println(MARK_EXCESS_MICROS);
            IrReceiver.compensateAndPrintIRResultAsCArray(&Serial, false); // Saída dos resultados como array de código-fonte uint8_t de ticks
            Serial.print(F("Resultado como array de microssegundos - compensado com MARK_EXCESS_MICROS="));
            Serial.println(MARK_EXCESS_MICROS);
            IrReceiver.compensateAndPrintIRResultAsCArray(&Serial, true); // Saída dos resultados como array de código-fonte uint16_t de microssegundos
            IrReceiver.printIRResultAsCVariables(&Serial);  // Saída do endereço e dados como variáveis de código-fonte

            IrReceiver.compensateAndPrintIRResultAsPronto(&Serial);
        }
        IrReceiver.resume();                            // Preparação para o próximo valor
    }
}
