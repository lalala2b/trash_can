#include <LiquidCrystal.h>

LiquidCrystal lcd(2,4,15,5,18,19);

char buff[20];
int sw1,sw2;

void setup(){
  lcd.begin(20,4);

  pinMode(25,INPUT);
  pinMode(26,INPUT);

  Serial.begin(9600);
}

void loop(){
  sw1 = analogRead(25);
  sw2 = analogRead(26);

  lcd.setCursor(0,1); lcd.print("NILAI TOMBOL PANEL");

  sprintf(buff,"SW-PANEL-1=%04d",sw1);
  lcd.setCursor(0,2); lcd.print(buff);

  sprintf(buff,"SW-PANEL-2=%04d",sw2);
  lcd.setCursor(0,3); lcd.print(buff);
}