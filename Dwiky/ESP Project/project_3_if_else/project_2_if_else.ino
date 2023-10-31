#define ledMerah 12
const int ledKuning = 13;
const int ledHijau = 14;
#define swBtn 35

bool tekan = 0;

void setup(){
  pinMode(ledMerah,OUTPUT);
  pinMode(ledKuning,OUTPUT);
  pinMode(ledHijau,OUTPUT);

  pinMode(swBtn,INPUT);
}

void loop(){
  tekan = digitalRead(swBtn);
  if(tekan==0){
    digitalWrite(ledMerah,LOW);
    digitalWrite(ledKuning,LOW);
    digitalWrite(ledHijau,LOW);
  }
  if(tekan==1){
    digitalWrite(ledMerah,HIGH);
    digitalWrite(ledKuning,HIGH);
    digitalWrite(ledHijau,HIGH);
  }
}