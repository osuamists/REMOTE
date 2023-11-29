/*******************************************************************/
/* Aula 30 - Receptor IR e Controle Remoto */
/* */
/* Através deste programa você poderá realizar a leitura, através */
/*do Monitor Serial, o código hexadecimal emitido por 4 teclas de */
/*um controle remoto infravermelho. */
/*******************************************************************/
/* Inclui a biblioteca para o Módulo IR. */
#include <IRremote.h>
/* Define o pino do Arduino que receberá os dados do receptor IR. */
int Pino_receptor = 3;
void setup()
{
/* Inicializa a comunicação serial na velocidade 9600 bauds. */
Serial.begin(9600);
/* Inicializa o receptor IR no pino definido. */
IrReceiver.begin(Pino_receptor);
/* Mostra, no monitor serial, as instruções a serem seguidas. */
Serial.println("Pressione as teclas 1, 2, 3 e 4, nessa ordem, ");
Serial.println("caso cometa algum erro, feche e abra novamente ");
Serial.println("o monitor serial para reiniciar a operação.");
/* Pula uma linha. */
Serial.println("");
/* Repetirá a coleta do código 4 vezes (uma para cada tecla. */
for (int tecla = 1; tecla <= 4; tecla++) {
/* Aguarda uma tecla ser pressionada. */
while (!IrReceiver.decode()) {}
/* Imprime o código hexadecimal da tecla pressionada. */
Serial.print("Código hexadecimal da tecla ");
Serial.print(tecla);
Serial.print(": ");
Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
/* Pequena pausa. */
delay(600);
/* Lê o próximo valor */
IrReceiver.resume();
}
/* Envia a mensagem de FIM e orienta o próximo passo da aula. */
Serial.println("");
Serial.println("FIM...");
Serial.println("Insira os valores no próximo código-fonte ");
Serial.println("de programação.");
}
void loop () {}
