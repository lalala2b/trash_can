#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

#define trigPin 12
#define echoPin 13
#define MAX_DISTANCE 500

LiquidCrystal_I2C lcd(0x27,20,4);

NewPing sonar(trigPin,echoPin,MAX_DISTANCE);
int greenLed = 2;
int redLed = 3;
int pos = 20;
const int tinggi = 180;
const int tg2 = 7 ;

void setup(){
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop(){
  int duration, distance, pos=0, i;
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2)/29.1;
  //int tb = tinggi-distance;
  int ta = tg2-distance;
  
  Serial.print(distance);
  Serial.println("cm");
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("jarak dari sensor");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");
/*
  lcd.setCursor(0,3);
  lcd.print("tinggi badan: ");
  lcd.print(tb);
  lcd.print("cm");
  */
  lcd.setCursor(0,3);
  lcd.print("tinggi air: ");
  lcd.print(ta);
  lcd.print("cm");
  
  delay(450);
}
