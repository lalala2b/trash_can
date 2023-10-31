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
  putaran = ledHijau;
  while(1){
    digitalWrite(putaran, HIGH);
    delay(1000);
    putaran--;
    if(putaran<ledMerah) break;
  }

  putaran = ledHijau;
  while(1){
    digitalWrite(putaran,LOW);
    putaran--;
    if(putaran<ledMerah) break;
  }

  putaran = ledHijau;
  while(1){
    digitalWrite(putaran,HIGH);
    delay(1000);
    putaran--;
    digitalWrite(putaran+1, LOW);
    if(putaran<ledMerah) break;
  }

  while(putaran<=ledHijau){
    digitalWrite(ledHijau,HIGH);
    delay(1000);
    putaran++;
  }
}