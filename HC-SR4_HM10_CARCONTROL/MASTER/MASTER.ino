#include <Servo.h>
#include <NewPing.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Wire.h>

#define USTrigger 9    //SONAR
#define USEcho 12

int max_distance = 100;
unsigned int distance;
unsigned int f_distance;
unsigned int b_distance;
unsigned int r_distance;
unsigned int l_distance;
int measure_time;

int slave = 0x50;
int order_data_f = 8;
int order_data_b = 5;
int order_data_r = 6;
int order_data_l = 4;
int order_data_d = 1;
int order_data_bekle = 3;

Servo servo; 
NewPing sonar(USTrigger, USEcho, max_distance);


void setup() {
  pinMode(USTrigger,OUTPUT);
  pinMode(USEcho, INPUT);

  servo.attach(10);

  Dabble.begin(9600);

  Serial.begin(9600);
  Serial.println("Port acildi...");

  Wire.begin();
  Serial.println("Wire has been stareted...");
}

void distance_measure()
{
  measure_time = sonar.ping();
  distance = measure_time / US_ROUNDTRIP_CM;
  Serial.print("Distance: ");
  Serial.println(distance);
}

void loop() 
{
  delay(100),
  distance_measure();
   if(distance > 50){ 
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
  else if (distance < 50)
   {
    servo.write(90);
    distance_measure();
    f_distance = distance;
    if(f_distance > 35 || f_distance == 0)
    {
      Serial.println("Forward...");
      Wire.beginTransmission(slave);
      Wire.write(order_data_f);
      Wire.endTransmission();
      delay(500);
    }
    else 
    {
      Wire.beginTransmission(slave);
      Wire.write(order_data_b);
      Wire.endTransmission();
      delay(500);
      Serial.println("Stop...");
    }

    servo.write(180);
    delay(500);
    distance_measure();
    l_distance = distance;

    servo.write(0);
    delay(500);
    distance_measure();
    r_distance = distance;

    Serial.print("Right Distance: ");
    Serial.println(r_distance);
    Serial.print("Left Distance: ");
    Serial.println(l_distance);

    if(r_distance < l_distance)
    {
      Wire.beginTransmission(slave);
      Wire.write(order_data_r);
      Wire.endTransmission();
      delay(200);
      Wire.beginTransmission(slave);
      Wire.write(order_data_f);
      Wire.endTransmission();
      delay(500);
      Serial.println("Saga Donus...");
    }

    else if(l_distance > r_distance)
    {
      Wire.beginTransmission(slave);
      Wire.write(order_data_l);
      Wire.endTransmission();
      Wire.beginTransmission(slave);
      Wire.write(order_data_d);
      Wire.endTransmission();
      delay(500);
      Serial.println("Sola Donus...");
    }
   
   delay(1000);
   
}

}
