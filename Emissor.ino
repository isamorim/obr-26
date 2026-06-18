#include <Arduino.h>
#include <IRremote.hpp>

const int pinoEmissor = 3; // Pino do LED Emissor IR

void setup() {
  pinMode(13, OUTPUT);
  IrSender.begin(pinoEmissor); 
}

void loop() {
  digitalWrite(13, HIGH); // Pisca o LED indicador
  
  // MUDANÇA AQUI: Alterado para protocolo NEC
  // Endereço: 0x00 | Comando Hexadecimal: 0x5A | Repetições: 0
  IrSender.sendNEC(0x00, 0x5A, 0); 
  
  digitalWrite(13, LOW);
  delay(1000); // Envia a cada 1 segundo
}