#include <SPI.h>
#include "nRF24L01p.h"
#include "RF24.h" 
#include <I2Cdev.h>
#include "Wire.h"  
#include "MPU6050.h"  // MPU6050'nin ana kütüphanesi

#define CE_PIN 9
#define CSN_PIN 10
nRF24L01p transmitter(CSN_PIN, CE_PIN);
int data[2];

MPU6050 MPU;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup(void) {
  Serial.begin(9600);
  Serial.println("Port açildi...");
  
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  transmitter.channel(90);
  transmitter.TXaddress("tiny");
  transmitter.init();

  Wire.begin();
  MPU.initialize();  

}

void loop(void) {

  MPU.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  
  data[0] = map(ax, -17000, 17000, 300, 400 ); // X ekseni verilerini gönder
  Serial.print("x ekseni...");
  Serial.println(data[0]); 
  
  data[1] = map(ay, -17000, 17000, 100, 200); // Y ekseni verilerini gönder
  Serial.print("y ekseni...");
  Serial.println(data[1]);

  transmitter.txPL(data[0]);
  transmitter.txPL(data[1]);
  transmitter.send(FAST);
  delay(500);



}
