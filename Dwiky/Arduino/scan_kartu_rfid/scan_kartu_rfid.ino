#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN,RST_PIN);

int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;

void setup(){
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
}

void loop(){
  if(rfid.isCard()){
    if(rfid.readCardSerial()){
      if(rfid.serNum[0] != serNum0
          && rfid.serNum[1] != serNum1
          && rfid.serNum[2] != serNum2
          && rfid.serNum[3] != serNum3
          && rfid.serNum[4] != serNum4){
        Serial.println(" ");
        Serial.println("Card found");
        serNum0 = rfid.serNum[0];
        serNum1 = rfid.serNum[1];
        serNum2 = rfid.serNum[2];
        serNum3 = rfid.serNum[3];
        serNum4 = rfid.serNum[4];

        Serial.println("Card number: ");
        Serial.print("Dec: ");
        for (int i=0;i<5;i++){
        Serial.print(rfid.serNum[i],DEC);
        Serial.print(", ");
        }
        Serial.println();
        Serial.print("Hex: ");
        for (int i=0;i<5;i++){
          Serial.print(rfid.serNum[i],HEX);
        Serial.print(", ");
        }
      }else{
        rfid.halt();
      }
    }
  }
  rfid.halt();
}
