  #include <I2Cdev.h>
#include "Wire.h"  
#include "MPU6050.h"  
#include <SPI.h>        
#include "RF24.h"       
#include "nRF24L01p.h"   

const int  MOTORR1 = 4; // sağ ön
const int  MOTORR2 = 2; // sağ arka
const int  EN_A = 3; // ENA SAĞ
const int  MOTORL1 = 7; //sol ön 
const int  MOTORL2 = 6; //sol arka
const int  EN_B = 5; //ENB SOL


#define CE_PIN 9
#define CSN_PIN 10
nRF24L01p receiver(CSN_PIN, CE_PIN);
int data[2];

MPU6050 MPU;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
  pinMode(MOTORR1, OUTPUT);
  pinMode(MOTORR2, OUTPUT);
  pinMode(MOTORL1, OUTPUT);
  pinMode(MOTORL2, OUTPUT);
  pinMode(EN_A, OUTPUT);
  pinMode(EN_B, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Port açildi...");
  delay(100);
  
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  receiver.channel(90);
  receiver.RXaddress("tiny");
  receiver.init();

  Wire.begin();
  MPU.initialize(); 
  
}

void loop() {

  if (receiver.available())
  {
    Serial.println("haberlesme basladi...");

    bool done = false;
    while(!done){
      int y = data[1];
      int x = data[0];
    
      receiver.read();
      receiver.rxPL(x);
      receiver.rxPL(y);
    
      Serial.println(x);
      Serial.println(y);

      if(x > 380){        //İLERİ
        analogWrite(EN_A, 150); // SAĞ motorun hızı 150
        digitalWrite(MOTORR1, HIGH); // SAĞ motorun ileri hareketi aktif
        digitalWrite(MOTORR2, LOW); // SAĞ motorun geri hareketi pasif
        
        analogWrite(EN_B, 150); // SOL motorun hızı 150
        digitalWrite(MOTORL1, HIGH); // SOL motorun ileri hareketi aktif
        digitalWrite(MOTORR2, LOW); // SOL motorun geri hareketi pasif
       Serial.println("FORWARD!");
      }

       else if(x < 310){        //GERİ
        analogWrite(EN_A, 150); // SOL motorun hızı 150
        digitalWrite(MOTORR1, LOW); // SOL motorun ileri hareketi pasif
        digitalWrite(MOTORR2, HIGH); // SOL motorun geri hareketi aktif
        
        analogWrite(EN_B, 150); // SAĞ motorun hızı 150
        digitalWrite(MOTORL1, LOW); // SAĞ motorun ileri hareketi pasif
        digitalWrite(MOTORL2, HIGH); // SAĞ motorun geri hareketi aktif
        Serial.println("BACK!");
      }

      if(y > 180){         //SOLA
      analogWrite(EN_A, 150); // SOL motorun hızı 150
      digitalWrite(MOTORR1, HIGH); // SOL motorun ileri hareketi aktif
      digitalWrite(MOTORR2, LOW); // SOL motorun geri hareketi pasif
      
      analogWrite(EN_B, 150); // SAĞ motorun hızı 150
      digitalWrite(MOTORL1, LOW); // SAĞ motorun ileri hareketi aktif
      digitalWrite(MOTORL2, HIGH); // SAĞ motorun geri hareketi pasif
        Serial.println("LEFT!");
    
      }
    
      else if(y < 110){         //SAĞA
        analogWrite(EN_A, 150); // SOL motorun hızı 150
        digitalWrite(MOTORR1, LOW); // SOL motorun ileri hareketi aktif
        digitalWrite(MOTORR2, HIGH); // SOL motorun geri hareketi pasif
        
        analogWrite(EN_B, 150); // SAĞ motorun hızı 150
        digitalWrite(MOTORL1, HIGH); // SAĞ motorun ileri hareketi aktif
        digitalWrite(MOTORL2, LOW); // SAĞ motorun geri hareketi pasif
        Serial.println("RIGHT!");
    
      }

      if(x > 330 && x < 360 && y > 130 && y < 160){
      //stop car
        analogWrite(EN_A, 0); // SOL motorun hızı 150
        analogWrite(EN_B, 0);
        Serial.println("Verici bulunamadı...");
        Serial.println("STOP!");
      } 
      delay(500);
    }
  }
}


      
