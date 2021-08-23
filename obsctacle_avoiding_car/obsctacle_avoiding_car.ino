
#include <Servo.h>// servo motor kütüphanesi
#include <NewPing.h>

const int  MOTORR1 = 4; // sağ ön
const int  MOTORR2 = 2; // sağ arka
const int  EN_A = 3; // ENA SAĞ
const int  MOTORL1 = 7; //sol ön 
const int  MOTORL2 = 6; //sol arka
const int  EN_B = 5; //ENB SOL

#define USTrigger 11
#define USEcho 12
#define Maksimum_uzaklik 100

Servo servo; //servo motor tanımlama
NewPing sonar(USTrigger, USEcho, Maksimum_uzaklik);//ultrasonik sensör tanımlama

unsigned int uzaklik;
unsigned int on_uzaklik;
unsigned int sol_uzaklik;
unsigned int sag_uzaklik;
unsigned int zaman;

void setup() {
  pinMode(MOTORR1, OUTPUT);
  pinMode(MOTORR2, OUTPUT);
  pinMode(MOTORL1, OUTPUT);
  pinMode(MOTORL2, OUTPUT);
  pinMode(EN_A, OUTPUT);
  pinMode(EN_B, OUTPUT);
  servo.attach(10); //servo pin tanımı
}

/************************FORWARD**********************/
  void forward()
  {
    analogWrite(EN_A, 150); // SAĞ motorun hızı 150
    digitalWrite(MOTORR1, HIGH); // SAĞ motorun ileri hareketi aktif
    digitalWrite(MOTORR2, LOW); // SAĞ motorun geri hareketi pasif
    
    analogWrite(EN_B, 150); // SOL motorun hızı 150
    digitalWrite(MOTORL1, HIGH); // SOL motorun ileri hareketi aktif
    digitalWrite(MOTORR2, LOW); // SOL motorun geri hareketi pasif
  
  }
    
/************************BACK**********************/
  void back()
  {
    analogWrite(EN_A, 150); // SAĞ motorun hızı 150
    digitalWrite(MOTORR1, LOW); // SAĞ motorun ileri hareketi aktif
    digitalWrite(MOTORR2, HIGH); // SAĞ motorun geri hareketi pasif
    
    analogWrite(EN_B, 150); // SOL motorun hızı 150
    digitalWrite(MOTORL1, LOW); // SOL motorun ileri hareketi aktif
    digitalWrite(MOTORR2, HIGH); // SOL motorun geri hareketi pasif
  
  }
    
/************************RIGHT**********************/
  void right()
  {
    analogWrite(EN_A, 150); // SAĞ motorun hızı 150
    digitalWrite(MOTORR1, HIGH); // SAĞ motorun ileri hareketi aktif
    digitalWrite(MOTORR2, LOW); // SAĞ motorun geri hareketi pasif
    
    analogWrite(EN_B, 150); // SOL motorun hızı 150
    digitalWrite(MOTORL1, LOW); // SOL motorun ileri hareketi aktif
    digitalWrite(MOTORR2, HIGH); // SOL motorun geri hareketi pasif
  
  }
    
/************************FORWARD**********************/
  void left()
  {
    analogWrite(EN_A, 150); // SAĞ motorun hızı 150
    digitalWrite(MOTORR1, LOW); // SAĞ motorun ileri hareketi aktif
    digitalWrite(MOTORR2, HIGH); // SAĞ motorun geri hareketi pasif
    
    analogWrite(EN_B, 150); // SOL motorun hızı 150
    digitalWrite(MOTORL1, LOW); // SOL motorun ileri hareketi aktif
    digitalWrite(MOTORR2, HIGH); // SOL motorun geri hareketi pasif
  
  }
    
/************************FORWARD**********************/
  void stop()
  {
    analogWrite(EN_A, 0); // SAĞ motorun hızı 150
    
    analogWrite(EN_B, 0); // SOL motorun hızı 150
  }
  void sensor_olcum()
  { 
    delay(50);
    zaman = sonar.ping();
    uzaklik = zaman / US_ROUNDTRIP_CM;
    
  }

void loop() {
  
  delay(500);
  servo.write(90);
  sensor_olcum();
  on_uzaklik = uzaklik;
  if(uzaklik > 35 || uzaklik == 0)
    forward();
  else
    stop();
    
  servo.write(180);
  delay(500);
  sensor_olcum();
  sol_uzaklik = uzaklik;
  
  servo.write(0);
  delay(500);
  sensor_olcum();
  sag_uzaklik = uzaklik;
  
  servo.write(90);
  delay(300);
  
  if(sag_uzaklik > sol_uzaklik)
  {
    right();
    delay(200);
    forward(); 
  }
  else if(sol_uzaklik > sag_uzaklik)
  {
    left();
    delay(200);
    forward();
  }
   else
    back();

  

  
  
}
