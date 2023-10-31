#define ledMerah 12
const byte ledKuning = 13;
const byte ledHijau = 14;

#define btn1 35
#define btn2 34

bool press1 = 0, press2 = 0;
byte putaran;

void setup(){
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);

  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop(){
  press1 = digitalRead(btn1);
  press2 = digitalRead(btn2);

  if (press1 == 0 && press2 == 0){
    for (putaran = ledMerah; putaran<=ledHijau; putaran++) digitalWrite(putaran, LOW);
  }

  if (press1 == 1 && press2 == 0){
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, HIGH);
  }
  if (press1 == 0 && press2 == 1){
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, HIGH);
    digitalWrite(ledHijau, LOW);
  }
  if (press1 == 1 && press2 == 1){
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledKuning, HIGH);
    digitalWrite(ledHijau, HIGH);
  }
  delay(1500);
}