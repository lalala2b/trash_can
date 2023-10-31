#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "BluetoothSerial.h"

String device_name = "2B";

#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
unsigned long delayTime;

// set the LCD number of columns and rows
int lcdColumns = 20;
int lcdRows = 4;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

String message;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();

  dht.begin();

  Serial.begin(115200);
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  
}
void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  // Check if any reads failed and exit early (to try again).
  
    
  SerialBT.print("Hum: ");
  SerialBT.print(dht.readHumidity());
  SerialBT.println(" %");
  
  SerialBT.print("Temp: ");
  SerialBT.print(dht.readTemperature());
  SerialBT.println(" C ");

  delay(2000);
  if (SerialBT.available()){
    lcd.clear();
    message = "";

    while(SerialBT.available()){
      char inCome = SerialBT.read();
      message += String(inCome);
    }

    Serial.println(message);
    lcd.setCursor(0, 0);
    lcd.print(message);
  }
}