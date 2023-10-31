#include <IRremote.h>
const int RECV_PIN = 11;
IRrecv protokol(RECV_PIN);
decode_results hasil;

void setup(){
  Serial.begin(9600);
  protokol.enableIRIn();
  protokol.blink13(true);
}

void loop(){
  if (protokol.decode(&hasil)){
    Serial.println(hasil.value,HEX);
    protokol.resume();
  }
  delay(500);
}
