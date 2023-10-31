#include <LiquidCrystal_I2C. h>
#include "DHT.h"

#define DHTPIN 8
LiquidCrystal_I2C lcd(0x27,20,4);
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);

void setup(){
  dht.begin();
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  t = t*9/5+32;

  if (isnan(h) || isnan(t)){
    lcd.setCursor(0,0);
    lcd.print("failed to read");
    Serial.print("fail");
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.print("%");
    
    lcd.setCursor(0,1);
    lcd.print("Temperature: ");
    lcd.print(t);
    lcd.print("f");
  }
}
