#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Wire.h>


int slave = 0x50;
int order_data_f = 8;
int order_data_b = 5;
int order_data_r = 6;
int order_data_l = 4;
int order_data_d = 1;
int order_data_bekle = 3;

void setup() {
  Dabble.begin(9600);

  Serial.begin(9600);
  Serial.println("Port acildi...");

  Wire.begin();
  Serial.println("Wire has been stareted...");

}

void loop() {

  Dabble.processInput();  // This line is crucial in grabbing our data  
  
  if (GamePad.isUpPressed())       
  {
    Serial.println("**Forward**");
    Wire.beginTransmission(slave);
    Wire.write(order_data_f);
    Wire.endTransmission();
    delay(500);
  }

  else if (GamePad.isDownPressed())
  {
    Serial.println("**Back**");
    Wire.beginTransmission(slave);
    Wire.write(order_data_b);
    Wire.endTransmission();
    delay(500);
  }

  else if (GamePad.isLeftPressed())
  {
    Serial.println("**Left**");
    Wire.beginTransmission(slave);
    Wire.write(order_data_l);
    Wire.endTransmission();
    delay(500);
  }

  else if (GamePad.isRightPressed())
  {
    Serial.println("**Right**");
    Wire.beginTransmission(slave);
    Wire.write(order_data_r);
    Wire.endTransmission();
    delay(500);
  }

  else 
  {
    Serial.println("**Stop**");
    Wire.beginTransmission(slave);
    Wire.write(order_data_d);
    Wire.endTransmission();
    delay(500);
  }
 }
  
