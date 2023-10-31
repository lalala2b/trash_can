#include "DHT.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,4,15,5,18,19);

char buff[20];
DHT dht(23, DHT11);

int Suhu_C, Suhu_F, Humidity;

void setup() {
  lcd.begin(20,4);
  dht.begin();

  Serial.begin(9600);
}

void loop() {
  Suhu_C = dht.readTemperature();
  Suhu_F = dht.readTemperature(true);
  Humidity = dht.readHumidity();

  lcd.setCursor(0,1); lcd.print("Data DHT11 Module");

  sprintf(buff,"Suhu = %02d C",Suhu_C);
  lcd.setCursor(0,2); lcd.print(buff);

  sprintf(buff,"Humidity = %02d %",Humidity);
  lcd.setCursor(0,3); lcd.print(buff);
}
