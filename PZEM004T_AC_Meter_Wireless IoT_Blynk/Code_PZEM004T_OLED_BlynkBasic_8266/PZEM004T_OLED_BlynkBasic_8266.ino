/* Sketch by RBMK-5000
This sketch is ready to use, simply fill your WiFi SSID, Password & Blynk Token on line 21-23 below.
Use NodeMCU ESP8266 or Wemos D1 mini + Oled I2C 128x64 SSD1306.
I also provide Detailed Schematic and Blynk Project QR Code, refer elsewhere.
*/

#include <PZEM004Tv30.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DISPLAY_ADDRESS   0x3C // or 0x3D
#define DISPLAY_SCL_PIN   5
#define DISPLAY_SDA_PIN   4
#define DISPLAY_WIDTH     128 // OLED display width, in pixels
#define DISPLAY_HEIGHT    64  // OLED display height, in pixels
#define DISPLAY_RESET_PIN -1  // Reset pin # (or -1 if sharing with ESP8266 reset pin)

Adafruit_SSD1306 display(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, DISPLAY_RESET_PIN);

PZEM004Tv30 pzem1(14, 12); // GPIO14(D5) to Tx PZEM004; GPIO12(D6) to Rx PZEM004

char ssid[] = "WiFi NAME"; // WiFi Name
char pass[] = "WiFi PASSWORD"; // WiFi Password
char auth[] = "BLYNK AUTH TOKEN"; //Blynk Token

float voltage1, current1, power1, energy1, frequency1, pf1, va1, VAR1;

void setup() {
  Serial.begin(115200);
  setupDisplay();
  Blynk.begin(auth, ssid, pass, "iot.serangkota.go.id", 8080); // Change the Blynk Server and Port Number when required.
}

void setupDisplay() {
  Wire.begin(DISPLAY_SDA_PIN, DISPLAY_SCL_PIN);           // You can also set I2C SCL&SDA pins to other GPIOs
  display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_ADDRESS);

  display.clearDisplay();
  display.setCursor(10, 0);
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.println("PZEM-004T");
  display.setCursor(10, 36);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.println("Connecting Blynk..");
  display.display();
  delay(1000);
}

void loop() {
  voltage1 = pzem1.voltage();
  voltage1 = zeroIfNan(voltage1);
  current1 = pzem1.current();
  current1 = zeroIfNan(current1);
  power1 = pzem1.power();
  power1 = zeroIfNan(power1);
  energy1 = pzem1.energy() / 1000; //kwh
  energy1 = zeroIfNan(energy1);
  frequency1 = pzem1.frequency();
  frequency1 = zeroIfNan(frequency1);
  pf1 = pzem1.pf();
  pf1 = zeroIfNan(pf1);
  if (pf1 == 0) {
    va1 = 0;
  } else {
    va1 = power1 / pf1;
  }
  if (pf1 == 0) {
    VAR1 = 0;
  } else {
    VAR1 = power1 / pf1 * sqrt(1-sq(pf1));
  }
  delay(1000);

  Blynk.run();
  // Send to Blynk
  Blynk.virtualWrite(V1, voltage1);
  Blynk.virtualWrite(V2, current1);
  Blynk.virtualWrite(V3, power1);
  Blynk.virtualWrite(V4, energy1);
  Blynk.virtualWrite(V5, frequency1);
  Blynk.virtualWrite(V6, pf1);
  Blynk.virtualWrite(V7, va1);
  Blynk.virtualWrite(V8, VAR1);
  Blynk.virtualWrite(V9, (power1 / va1) * 100);

  Serial.println("");
  Serial.printf("Voltage        : %.2f\ V\n", voltage1);
  Serial.printf("Current        : %.2f\ A\n", current1);
  Serial.printf("Power Active   : %.2f\ W\n", power1);
  Serial.printf("Frequency      : %.2f\ Hz\n", frequency1);
  Serial.printf("Cosine Phi     : %.2f\ PF\n", pf1);
  Serial.printf("Energy         : %.2f\ kWh\n", energy1);
  Serial.printf("Apparent Power : %.2f\ VA\n", va1);
  Serial.printf("Reactive Power : %.2f\ VAR\n", VAR1);
  Serial.printf("---------- END ----------");
  Serial.println("");

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.printf("Voltage  : %.2f\ V\n", voltage1);
  display.printf("Current  : %.2f\ A\n", current1);
  display.printf("Power RMS: %.2f\ W\n", power1);
  display.printf("Cos Phi  : %.2f\ PF\n", pf1);
  display.printf("Apprn Pwr: %.1f\ VA\n", va1);
  display.printf("React Pwr: %.1f\ VAR\n", VAR1);
  display.printf("Frequency: %.1f\ Hz\n", frequency1);
  display.printf("Energy   : %.1f\ kWh\n", energy1);
  display.display();
  delay(2000);
}

void printValue(String label, float value) {
  if (value != NAN) {
    Serial.print(label); Serial.println(value);
  } else {
    Serial.println("Error reading");
  }
}

float zeroIfNan(float v) {
  if (isnan(v)) {
    v = 0;
  }
  return v;
}
