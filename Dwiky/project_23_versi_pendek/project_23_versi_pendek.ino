#include <SPI.h>
#include <RFID.h>

RFID rfid(10,5);

byte card[5] = {0x90,0xC0,0x2C,0x20,0x5C};//{0x83, 0x36, 0x12, 0xB7, 0x10};

byte serNum[5];
byte data[5];

void setup(){
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  Serial.println("Arduino card reader");
  delay(1000);
}

void loop(){
  bool card_card = true;
  if (rfid.isCard()){
    if(rfid.readCardSerial()){
      delay(1000);
      data[0] = rfid.serNum[0];
      data[1] = rfid.serNum[1];
      data[2] = rfid.serNum[2];
      data[3] = rfid.serNum[3];
      data[4] = rfid.serNum[4];
    }   
    Serial.print("Card found - code: ");
    for(int i=0;i<5;i++){
      if (data[i] != card[i]) card_card = false;
    }
  
    Serial.println();
    if (card_card){
      Serial.println("Hello");
    }
    else{
      Serial.println("Card not recognized! Contact administrator!");
    }
  
    if (card_card){
      Serial.println("Access granted....... Welcome!");
    }
    Serial.println();
    delay(500);
    rfid.halt();
  }
}
