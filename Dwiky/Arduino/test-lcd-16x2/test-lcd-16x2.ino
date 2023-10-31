#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HELL");
  lcd.setCursor(2,1);
  lcd.print("WORLD");
  delay(2000);

  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("DWIKY");
  lcd.setCursor(0,1);
  lcd.print("NUGRAHA");
  delay(2000);
}
