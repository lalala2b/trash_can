#include "RTClib.h"
#include <LiquidCrystal.h>

RTC_DS3231 rtc;
LiquidCrystal lcd(2,4,15,5,18,19);

char buff[20];
int Jam,Menit,Detik,Tanggal,Bulan,Tahun;

void setup(){
  lcd.begin(20,4);
  rtc.begin();

  if (rtc.lostPower()){
    rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  }
}

void loop(){
  DateTime now = rtc.now();

  Jam = now.hour();
  Menit = now.minute();
  Detik = now.second();
  Tanggal = now.day();
  Bulan = now.month();
  Tahun = now.year();

  lcd.setCursor(0,1);
  lcd.print("Data DS3231 Module");

  sprintf(buff,"%02d %02d %04d",Tanggal, Bulan, Tahun);
  lcd.setCursor(0,2); lcd.print(buff);

  sprintf(buff,"%02d:%02d:%02d",Jam,Menit,Detik);
  lcd.setCursor(0,3); lcd.print(buff);
}