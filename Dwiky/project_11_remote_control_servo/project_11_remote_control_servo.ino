//#include <Servo.h>
#include <IRremote.h>

unsigned long atas = 0x52120F2;
unsigned long bawah = 0xDE3AA631;
unsigned long kiri = 0x69893291;
unsigned long kanan = 0x8753BA5C;

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results hasil;

// untuk remote ke servo
Servo servo1;
Servo servo2;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();

  // untuk remote ke led
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  
  // untuk remote ke servo
  Serial.begin(9600);
  irrecv.enableIRIn();
  servo1.attach(10);
  servo2.attach(9);
}

void loop(){
  if(irrecv.decode(&hasil)){
    Serial.println(hasil.value, HEX);
    irrecv.resume();
  }

  // untuk remote ke led
  if(hasil.value == atas){
    digitalWrite(2,HIGH);
  }
  else if(hasil.value == bawah){
    digitalWrite(4,HIGH);
  }
  else if(hasil.value == kiri){
    digitalWrite(3,HIGH);
  }
  else if(hasil.value == kanan){
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  
  // untuk remote ke servo
  if(hasil.value == bawah){
    servo1.write(160);
  }
  else if(hasil.value == atas){
    servo1.write(70);
  }
  else if(hasil.value == kiri){
    servo2.write(70);
  }
  else if(hasil.value == kanan){
    servo2.write(160);
  }
}
