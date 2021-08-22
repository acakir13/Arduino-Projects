
#include <SPI.h>
#include "nRF24L01p.h"
#include "RF24.h" 

#define CE_PIN 9
#define CSN_PIN 10

nRF24L01p transmitter(CSN_PIN, CE_PIN);

String data = "HELLO AYBİK";

void setup() {
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  transmitter.channel(90);
  transmitter.TXaddress("tiny");
  transmitter.init();
  
  
}

void loop() {
  transmitter.txPL(data);
  transmitter.send(FAST);
  delay(500);
}
