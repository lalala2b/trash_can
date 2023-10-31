const int ledMerah = 26;
const int ledKuning = 19;
const int ledHijau = 18;

const int swBtn = 34;

void setup() {

  pinMode(ledMerah,OUTPUT);
  pinMode(ledKuning,OUTPUT);
  pinMode(ledHijau,OUTPUT);

  pinMode(swBtn,INPUT);

}

void loop() {

  byte value = digitalRead(swBtn);
  digitalWrite(ledMerah,value);

  digitalWrite(ledKuning,HIGH);
  delay(1000);
  digitalWrite(ledKuning,LOW);
  digitalWrite(ledHijau,HIGH);
  delay(1000);
  digitalWrite(ledHijau,LOW);
}
