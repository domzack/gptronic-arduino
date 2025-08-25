/**
 * Envia menssagens para PAINEL GPTRONIC
 * utilizando SERIAL 232 / ARDUINO
 * Author: Rodrigo Daniel Zacarias ME
 */

void PrintLed(String message) {

  byte add = 0x00;
  byte ident = 0x96;
  byte modo = 0x03; //mensagem variavel
  int interval = 10; //tempo (millis) delay entre cada byte enviado

  message.replace("+", " "); //Altera todos char('+') por 'space'. Necessario quando utilizado interface ethernet;

  Serial2.write(add); delay(interval); Serial2.write(ident); delay(interval); Serial2.write(modo); delay(interval); //header
  Serial2.write(0xFF); delay(interval); Serial2.write(0XC0); delay(interval); Serial2.write(0XC0); delay(interval); //rolagem de text

  for (int i = 0; i < message.length(); i++) {
    Serial2.write(byte(message[i])); //envia byte a byte de <message>
    delay(interval);
  }
  Serial2.write(0x11); // commit

}