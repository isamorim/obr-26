#include <Arduino.h>
#include <IRremote.hpp>

const int pinoReceptor = 2; // Pino do Receptor IR de 3 pinos

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(pinoReceptor, ENABLE_LED_FEEDBACK); 
  
  Serial.println("--- Sistema de Teste IR Pronto ---");
  Serial.println("Aguardando sinal do emissor...");
}

void loop() {
  if (IrReceiver.decode()) {
    
    uint16_t comandoRecebido = IrReceiver.decodedIRData.command;
    
    if (comandoRecebido != 0) {
      Serial.print("Sinal detectado! Comando (HEX): 0x");
      Serial.println(comandoRecebido, HEX);
      
      // MUDANÇA AQUI: Agora ele valida o novo código 0x5A
      if (comandoRecebido == 0x5A) {
        Serial.println(">> [SUCESSO] Novo sinal (0x5A) recebido do Emissor! <<");
      } else {
        Serial.println(">> [AVISO] Outro comando detectado. <<");
      }
      Serial.println("-------------------------------------------");
    }
    
    IrReceiver.resume(); 
  }
  delay(100);
}