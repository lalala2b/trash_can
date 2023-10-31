#define led_data(x) digitalWrite(13,x);
#define led_clk(x) digitalWrite(12,1); delay(1); digitalWrite(12,0);
#define led_latch() digitalWrite(14,1); delay(1); digitalWrite(14,0);

int D1,D2,D3,D4,D5,D6,D7,D8;
int swp1,swp2;

void setup(){
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
}

void led595(){
  if (D7){led_data(0);} else{led_data(1);} led_clk();
  if (D8){led_data(0);} else{led_data(1);} led_clk();
  if (D6){led_data(0);} else{led_data(1);} led_clk();
  if (D2){led_data(0);} else{led_data(1);} led_clk();
  if (D1){led_data(0);} else{led_data(1);} led_clk();
  if (D4){led_data(0);} else{led_data(1);} led_clk();
  if (D3){led_data(0);} else{led_data(1);} led_clk();
  if (D5){led_data(0);} else{led_data(1);} led_clk();

  led_latch();
}

void loop(){
  swp1 = analogRead(25);
  swp2 = analogRead(26);

  if (swp1<4000){
    D5=1; led595(); delay(1000);
  }else {
    D1=0; D2=0; D3=0; D4=0; D5=0; D6=0; D7=0; D8=0; led595(); delay(1000);
  }
}