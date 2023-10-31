#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.print("HELLO WORLD");
  delay(1000);
}

void loop(){
  for (int i=0; i<13; i++){
    lcd.scrollDisplayLeft();
    delay(300);
  }
  for (int i=0; i<29; i++){
    lcd.scrollDisplayRight();
    delay(300);
  }
  for (int i=0; i<16; i++){
    lcd.scrollDisplayLeft();
    delay(300);
  }
  delay(1000);
}
