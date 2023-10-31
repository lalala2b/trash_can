#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 8
LiquidCrystal_I2C lcd(0x27,20,4);
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

void setup(){
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  t = t*9/5+32;

  if (isnan(t) || isnan(h)){
    Serial.begin(9600);
    lcd.setCursor(0,0);
    lcd.print("Failed to read from DHT");
    Serial.println("fail to read");
    delay(1000);
  }
  else {
    Serial.print("Humidity :");
    Serial.print(h);
    Serial.print("%");

    Serial.print("Temperature  :");
    Serial.print(t);
    Serial.print("f");
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.print("%");

    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print("f");
    
  }
}
