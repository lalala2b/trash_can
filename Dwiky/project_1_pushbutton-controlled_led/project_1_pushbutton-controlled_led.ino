const int button = 2;
const int led = 13;
int btnState = 0;

// menyimpan variabel

void setup() {
  pinMode(led,OUTPUT); //setup pin led / 13 sebagai output
  pinMode(button,INPUT); //setup pin button / 2 sebagai input
}

void loop() {
  btnState = digitalRead(button); // menyimpan variable input dari button kedalam btnState
  if(btnState == HIGH){ // jika button ditekan maka lampu menyala, jika button dilepas maka lampu akan mati
    digitalWrite(led,HIGH);
  }
  else {
    digitalWrite(led,LOW);
  }
}
