const int ledCount = 9;
int ledPins[] = {2,3,4,5,6,7,8,9,10};

void setup(){
  for (int curLed = 0; curLed < ledCount; curLed++){
    // menginisialisasikan setiap pin yang digunakan (pin digital 2-10) sebagai output
    
    pinMode(ledPins[curLed],OUTPUT);
  }
}

void loop(){
  for (int curLed = 0; curLed < ledCount; curLed++){
    // lampu menyala secara berurutan sesuai urutan pin dari rendah ke tinggi dari pin 2-10
    
    digitalWrite(ledPins[curLed],HIGH);
    delay(500); 
    digitalWrite(ledPins[curLed],LOW);
  } 
  for (int curLed = 7; curLed > 0; curLed--){
    // lampu menyala secara berurutan sesuai urutan pin dari tinggi ke rendah mulai dari pin 9-3
    
    digitalWrite(ledPins[curLed],HIGH);
    delay(500);
    digitalWrite(ledPins[curLed],LOW);
  }
}
