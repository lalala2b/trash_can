#define ledMerah 12
const byte ledKuning = 13;
const byte ledHijau = 14;

byte putaran;

void setup(){
  pinMode(ledMerah,OUTPUT);
  pinMode(ledKuning,OUTPUT);
  pinMode(ledHijau,OUTPUT);
}

void loop(){
  for(putaran=ledMerah;putaran<=ledHijau;putaran++){
    digitalWrite(putaran, HIGH);
    delay(1000);
  }
  for(putaran=ledHijau;putaran>=ledMerah;putaran--){
    digitalWrite(putaran,LOW);
    delay(1000);
  }
}