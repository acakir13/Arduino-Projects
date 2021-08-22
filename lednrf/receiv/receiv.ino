#include "nRF24L01.h" // NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include <SPI.h>

#define LED_PIN 2

int Message[1]; // Used to store value received by the NRF24L01
RF24 radio(9,10); // NRF24L01 SPI pins. Pin 9 and 10 on the Nano

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup(void)
{
  Serial.begin(9600);
  radio.begin(); // Start the NRF24L01
  
  radio.openReadingPipe(1,pipe); // Get NRF24L01 ready to receive
  
  radio.startListening(); // Listen to see if information received
  
  pinMode(LED_PIN, OUTPUT); 
}

void loop(void)
{
  
  if (radio.available())
  Serial.println("haberlesme basladi...");
  {
    bool done = false;
    while(!done){
      done =  radio.read(Message, 1); // Read information from the NRF24L01
       if (Message[0] == 123){ // Indicates switch is pressed
        delay(10);
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Lamba yanıyor");
        Serial.println(Message[0]);
       }
       else{
        digitalWrite(LED_PIN, LOW);
        Serial.println("Lamba söndü");
        Serial.println(Message[0]);
       }
       delay(10);
    }
  }
}
    


   
