#define ledMerah 12
const byte ledKuning = 13;
const byte ledHijau = 14;

byte value = 0;
int total = 0;

void setup(){
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
}

void loop(){
  value = total % 3;

  switch (value){
    case 1:
      digitalWrite(ledHijau, HIGH);
      digitalWrite(ledKuning, LOW);
      digitalWrite(ledMerah, LOW);
      break;

    case 2:
      digitalWrite(ledKuning, HIGH);
      digitalWrite(ledMerah, HIGH);
      digitalWrite(ledHijau, LOW);
      break;
    
    default:
      digitalWrite(ledKuning, HIGH);
      digitalWrite(ledMerah, LOW);
      digitalWrite(ledHijau, LOW);
      break;
  }
  delay(1000);
  total = total+1;
}