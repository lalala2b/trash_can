#include <WiFi.h>

//Menghubungkan ke jaringan sekitar

const char* ssid = "lalala";
const char* password = "00000000";

void setup(){
  Serial.begin(9600);
  delay(10);

  Serial.print("\n\nMenghubungkan ke ");
  Serial.println(ssid);

  WiFi.begin(ssid,password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }

  Serial.println("");
  Serial.println("WiFi terkoneksi.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop(){

}