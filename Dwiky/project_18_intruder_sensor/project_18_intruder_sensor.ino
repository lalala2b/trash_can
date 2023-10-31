#include <NewPing.h>
#include <Servo.h>

#define trigPin 12
#define echoPin 13
#define MAX_DISTANCE 500

NewPing sonar(trigPin,echoPin,MAX_DISTANCE);
int greenLed = 2;
int redLed = 3;
int pos = 20;
Servo servo;

void setup(){
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  servo.attach(9);
}

void loop(){
  int duration, distance, pos=0, i;
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.println("cm");

  if (distance<=15){
    digitalWrite(greenLed,LOW);
    digitalWrite(redLed,HIGH);
    servo.write(180);
    delay(450);

    digitalWrite(redLed,LOW);
    servo.write(90);
    delay(450);

    digitalWrite(redLed,HIGH);
    servo.write(0);
    delay(450);

    digitalWrite(greenLed,LOW);
    servo.write(90);
  }
  else{
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,HIGH);
    servo.write(90);
  }
  delay(450);
}
