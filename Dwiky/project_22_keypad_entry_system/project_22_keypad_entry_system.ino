#include <Password.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
Password password = Password("2468");

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup(){
  Serial.begin(9600);
  delay(200);
  keypad.addEventListener(keypadEvent);
  lcd.init();
  lcd.backlight();
}

void loop(){
  keypad.getKey();
}

void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
    Serial.print("Pressed: ");
    Serial.println(eKey);
    switch (eKey){
      case '*':
        checkPassword();
        password.reset();
        break;
      default: password.append(eKey);
    }
  }
}

void checkPassword(){
  lcd.clear();
  if(password.evaluate()){
    Serial.println("Success");
    lcd.setCursor(0,0);
    lcd.print("Pintu Terbuka");
  }else{
    Serial.println("Wrong");
    lcd.setCursor(0,0);
    lcd.print("Password Salah");
  }
}
