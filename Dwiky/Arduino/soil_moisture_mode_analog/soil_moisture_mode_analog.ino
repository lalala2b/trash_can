int pinSensor = A0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(pinSensor);
  float moisture = (100-((sensorValue/1023.00)*100));
  Serial.print("Soil Moisture = ");
  Serial.print(moisture);
  Serial.println(" %");
  Serial.println(sensorValue);
  delay(1000);

  if (moisture < 50){
    Serial.print("tanah kering");
    delay>
  }
}
