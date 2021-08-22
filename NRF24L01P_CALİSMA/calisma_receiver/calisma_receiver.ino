#include <SPI.h>
#include "nRF24L01p.h"
#include "RF24.h" 

#define CE_PIN 9
#define CSN_PIN 10

String message;
nRF24L01p receiver(CSN_PIN, CE_PIN);



void setup() {
  delay(100);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  receiver.channel(90);
  receiver.RXaddress("tiny");
  receiver.init();
  Serial.begin(9600);
  }
  

void loop() {
  if (receiver.available())
  {
    receiver.read();
    receiver.rxPL(message);
    if(message != "")
    {
      Serial.println(message);
      message = "";
    }
  }
}
