const int potensioPin = A0;
const int ledCount = 9;
int ledPins[] = {2,3,4,5,6,7,8,9,10};

void setup(){
  for (int curLed = 0; curLed < ledCount; curLed++){
    pinMode(ledPins[curLed],OUTPUT);
  }
}

void loop(){
  int sensor = analogRead(potensioPin);
  int ledLevel = map(sensor, 0, 1023, 0, ledCount);
  for (int curLed = 0; curLed < ledCount; curLed++){
    if (curLed < ledLevel){
      digitalWrite(ledPins[curLed],HIGH);
    }
    else{
      digitalWrite(ledPins[curLed],LOW);
    }
  }
}
