const int led = 7;
const int onled = 5;
const int offled = 4;
int i = 0;

void setup(){
  pinMode(led,OUTPUT);
  pinMode(onled,INPUT_PULLUP);
  pinMode(offled,INPUT_PULLUP);
}

void loop(){
  if (digitalRead(onled)==0){ // jika button on ditekan akan menyimpan 1 kedalam i
    i=1;
  }else if (digitalRead(offled)==0){ // jika button off ditekan akan menyimpan 0 kedalam i
    i=0;
  }
  if (i==1){
    digitalWrite(led,HIGH);
  }else {
    digitalWrite(led,LOW);
  }
}
