#include  <SPI.h> 
#include "nRF24L01.h"
#include "RF24.h"     //Modül ile ilgili kütüphaneleri ekliyoruz

#define SwitchPin 3 

int Message[1];
RF24 radio(9,10); // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup()
{
  Serial.begin(9600);
  pinMode(SwitchPin, INPUT_PULLUP); 
  
  radio.begin(); // Start the NRF24L01
  radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit
}

void loop()
{
  if (digitalRead(SwitchPin) == LOW)    // If switch is pressed
  { 
  
    Message[0] = 123; 
    radio.write(Message, 1);   //mesaj değişkeni yollanıyor
    Serial.println(Message[0]);
   }
 delay(2);

}
