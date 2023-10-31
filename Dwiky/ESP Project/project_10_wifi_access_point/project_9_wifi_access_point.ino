#include <WiFi.h>

//Menghubungkan ke jaringan sekitar

const char* ssid = "2B";
const char* password = "00000000";

void setup(){
  Serial.begin(9600);
  delay(10);

  Serial.print("\n\nMengkonfigurasi ESP32 sebagai router dengan nama");
  Serial.println(ssid);

  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
}

void loop(){

}