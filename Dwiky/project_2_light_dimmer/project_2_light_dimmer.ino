int potensioPin = A0;
int potensioValue = 0;
int led = 9;

void setup(){
  pinMode(led,OUTPUT);
}

void loop(){
  potensioValue = analogRead(potensioPin);

  analogWrite(led, potensioValue/4);

  delay(10);
}
