const int  MOTORR1 = 4; // sağ ön
const int  MOTORR2 = 2; // sağ arka
const int  EN_A = 3; // ENA SAĞ
const int  MOTORL1 = 7; //sol ön 
const int  MOTORL2 = 6; //sol arka
const int  EN_B = 5; //ENB SOL


void setup() {
  pinMode(MOTORR1, OUTPUT);
  pinMode(MOTORR2, OUTPUT);
  pinMode(MOTORL1, OUTPUT);
  pinMode(MOTORL2, OUTPUT);
  pinMode(EN_A, OUTPUT);
  pinMode(EN_B, OUTPUT);

}

void loop() {
 ileri();
 delay(1000);
 dur();
 delay(1000);
 geri();
 delay(1000);
 dur();
 delay(1000);
 sag();
 delay(1000);
 dur();
 delay(1000);

}
void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.
    analogWrite(EN_A, 150); // SAĞ motorun hızı 150
    digitalWrite(MOTORR1, HIGH); // SAĞ motorun ileri hareketi aktif
    digitalWrite(MOTORR2, LOW); // SAĞ motorun geri hareketi pasif
    
    analogWrite(EN_B, 150); // SOL motorun hızı 150
    digitalWrite(MOTORL1, HIGH); // SOL motorun ileri hareketi aktif
    digitalWrite(MOTORR2, LOW); // SOL motorun geri hareketi pasif
  
}
  void sag(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.
    analogWrite(EN_A, 150); // SOL motorun hızı 150
    digitalWrite(MOTORR1, LOW); // SOL motorun ileri hareketi aktif
    digitalWrite(MOTORR2, HIGH); // SOL motorun geri hareketi pasif
    
    analogWrite(EN_B, 150); // SAĞ motorun hızı 150
    digitalWrite(MOTORL1, HIGH); // SAĞ motorun ileri hareketi aktif
    digitalWrite(MOTORL2, LOW); // SAĞ motorun geri hareketi pasif
}
void geri(){ // Robotun geri yönde hareketi için fonksiyon tanımlıyoruz.
  analogWrite(EN_A, 150); // SOL motorun hızı 150
  digitalWrite(MOTORR1, LOW); // SOL motorun ileri hareketi pasif
  digitalWrite(MOTORR2, HIGH); // SOL motorun geri hareketi aktif
  
  analogWrite(EN_B, 150); // SAĞ motorun hızı 150
  digitalWrite(MOTORL1, LOW); // SAĞ motorun ileri hareketi pasif
  digitalWrite(MOTORL2, HIGH); // SAĞ motorun geri hareketi aktif
  
}
void dur(){ // Robotun geri yönde hareketi için fonksiyon tanımlıyoruz.
  analogWrite(EN_A, 0); // SOL motorun hızı 150
  analogWrite(EN_B, 0);
 
}
