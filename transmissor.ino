#include <IRremote.h>

#define IRledPin 1  // LED conectado a GPIO 1
#define LEDPin 4     // LED conectado ao GPIO 3

IRsend irsend(IRledPin);

// Códigos IR para ligar e desligar o ar condicionado
unsigned long codigoLigar = 0x12345678;  // Substitua pelo código correto
unsigned long codigoDesligar = 0x87654321; // Substitua pelo código correto

void setup() {
  pinMode(IRledPin, OUTPUT); //declaração do transmissão como saída 
  pinMode(LEDPin, OUTPUT);  // Configura o pino do LED como saída
  Serial.begin(9600);
}

void loop() {
  char comando = Serial.read();

  if (comando == 'l') {
    Serial.println("Enviando sinal para ligar o ar condicionado.");
    enviarCodigo(codigoLigar);
    acionarLED();  // Aciona o LED quando ligar o ar condicionado
    delay(500);
  } else if (comando == 'd') {
    Serial.println("Enviando sinal para desligar o ar condicionado.");
    enviarCodigo(codigoDesligar);
    acionarLED();  // Aciona o LED quando desligar o ar condicionado
    delay(500);
  }
}

void enviarCodigo(unsigned long codigo) {
  irsend.sendNEC(codigo, 32);
}

void acionarLED() {
  digitalWrite(LEDPin, HIGH);  // Liga o LED
  delay(1000);  // Mantém o LED ligado por 1 segundo (ajuste conforme necessário)
  digitalWrite(LEDPin, LOW);   // Desliga o LED
}
