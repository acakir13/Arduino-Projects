#include <MPU6050.h>
#include <Wire.h>

MPU6050 ACC_GYR;

int16_t accx, accy, accz;
int16_t gyrx, gyry,gyrz;

int deger_x;
int deger_y;

int ledPin1 = 8;
int ledPin2 = 9;
int ledPin3 = 10;
int ledPin4 = 11;


void setup() {
  
  Serial.begin(9600);
  ACC_GYR.initialize();
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  ACC_GYR.getMotion6(&accx, &accy, &accz, &gyrx, &gyry, &gyrz);

  deger_x = map(accx, -17000, 17000, 0, 180);
  deger_y = map(accy, -17000, 17000, 0, 180);

  Serial.print("X:");
  Serial.print(deger_x);
  Serial.print(" Y:");
  Serial.println(deger_y);

  if(deger_x >= 0 and deger_x <= 60)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  }
  
  if(deger_x > 60 and deger_x < 120)
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }

  
  if(deger_x >= 120 and deger_x <= 180)
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
  }
  
  
  if(deger_y >= 0 and deger_y <=60)
  {
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
  }

  
  if(deger_y > 60 and deger_y < 120)
  {
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
  }

  
  if(deger_y >= 120 and deger_y <= 180)
  {
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH);
  }

  delay(100);

}



















  
  
