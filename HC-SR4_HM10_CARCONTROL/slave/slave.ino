//nano
#include <Wire.h>

const int  MOTORR1 = 4; // sağ ön
const int  MOTORR2 = 2; // sağ arka
const int  EN_A = 3; // ENA SAĞ
const int  MOTORL1 = 7; //sol ön 
const int  MOTORL2 = 6; //sol arka
const int  EN_B = 5; //ENB SOL

int getting_data;


void setup() {
  Serial.begin(9600);
  Serial.println("Seri port acildi...");
  Wire.begin(0x50);
  Serial.println("Wire has been stareted...");
  Wire.onReceive(getData);

  pinMode(MOTORR1, OUTPUT);
  pinMode(MOTORR2, OUTPUT);
  pinMode(MOTORL1, OUTPUT);
  pinMode(MOTORL2, OUTPUT);
  pinMode(EN_A, OUTPUT);
  pinMode(EN_B, OUTPUT);
}

void loop() {
  if(getting_data == 8)
    forward();
  if(getting_data == 5)
    back();
   if(getting_data == 6)
    right();
   if(getting_data == 4)
    left();
   if(getting_data == 1)
    dur();
   if(getting_data == 3)
    dur();
 
  
}
void forward(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.
 analogWrite(EN_A, 150); // SAĞ motorun hızı 150
 digitalWrite(MOTORR1, HIGH); // SAĞ motorun ileri hareketi aktif
 digitalWrite(MOTORR2, LOW); // SAĞ motorun geri hareketi pasif
 
    
 analogWrite(EN_B, 150); // SOL motorun hızı 150
 digitalWrite(MOTORL1, HIGH); // SOL motorun ileri hareketi aktif
 digitalWrite(MOTORL2, LOW); // SOL motorun geri hareketi pasif
 Serial.println("Forward");
  
}
void right(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.
 analogWrite(EN_A, 150); // SOL motorun hızı 150
 digitalWrite(MOTORR1, LOW); // SOL motorun ileri hareketi aktif
 digitalWrite(MOTORR2, HIGH); // SOL motorun geri hareketi pasif
    
 analogWrite(EN_B, 150); // SAĞ motorun hızı 150
 digitalWrite(MOTORL1, HIGH); // SAĞ motorun ileri hareketi aktif
 digitalWrite(MOTORL2, LOW); // SAĞ motorun geri hareketi pasif
 Serial.println("Right");
}
void back(){ // Robotun geri yönde hareketi için fonksiyon tanımlıyoruz.
  analogWrite(EN_A, 150); // SOL motorun hızı 150
  digitalWrite(MOTORR1, LOW); // SOL motorun ileri hareketi pasif
  digitalWrite(MOTORR2, HIGH); // SOL motorun geri hareketi aktif
  
  analogWrite(EN_B, 150); // SAĞ motorun hızı 150
  digitalWrite(MOTORL1, LOW); // SAĞ motorun ileri hareketi pasif
  digitalWrite(MOTORL2, HIGH); // SAĞ motorun geri hareketi aktif
  Serial.println("back");
}
void left(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.
 analogWrite(EN_A, 150); // SOL motorun hızı 150
 digitalWrite(MOTORR1, HIGH); // SOL motorun ileri hareketi aktif
 digitalWrite(MOTORR2, LOW); // SOL motorun geri hareketi pasif
    
 analogWrite(EN_B, 150); // SAĞ motorun hızı 150
 digitalWrite(MOTORL1, LOW); // SAĞ motorun ileri hareketi aktif
 digitalWrite(MOTORL2, HIGH); // SAĞ motorun geri hareketi pasif
 Serial.println("left");
}
void dur(){
 analogWrite(EN_A, 0); // SAĞ motorun hızı 150 
 analogWrite(EN_B, 0); // SOL motorun hızı 150
 Serial.println("Stop");
}

void getData(){
  if(Wire.available() >= 0)
  {
    getting_data = Wire.read();
    Serial.println(getting_data);
    
  }
}
