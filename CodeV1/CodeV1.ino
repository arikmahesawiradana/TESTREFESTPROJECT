#include <WiFi.h>
#include <HTTPClient.h>

#define analogPin 35
#define pinADC 34

//parameter untuk http request
const char ssid[] = "YOUR_SSID";
const char password[] = "YOUR_PASSWORD";
String HOST_NAME = "http://192.168.10.7"; // REPLACE WITH YOUR PC's IP ADDRESS
String PHP_FILE_NAME   = "/insert_temperature.php";  //REPLACE WITH YOUR PHP FILE NAME
String temp;

//parameter untuk sensor Tegangan
float Vmodul = 0.0; 
float hasil = 0.0;
float R1 = 30000.0; //30k
float R2 = 7500.0; //7500 ohm resistor, 
int value = 0;

//parameter untuk sensor arus
int sensitivitas = 185; //tegantung sensor arus yang digunakan, yang ini 5A
int nilaiadc= 00;
int teganganoffset = 2500; //nilai pembacaan offset saat tidak ada arus yang lewat
double tegangan = 00;
double nilaiarus = 00;

//hasil parsaeter
float voltase;
float arusnya;

HTTPClient http;

float detectVoltage(int pin){
  value = analogRead(pin);
  Vmodul = (value * 5.0) / 1024.0;
  hasil = Vmodul / (R2/(R1+R2));
  return hasil;
}

float detectArus(int pin){
  nilaiadc = analogRead(pin);
  tegangan = (nilaiadc / 1024.0) * 5000;
  nilaiarus = ((tegangan - teganganoffset) / sensitivitas);
  return nilaiarus;
}

void uploadToServer(String volt, String Current){
  temp = "?volt=" + volt + "current=" + Current;
  String server = HOST_NAME + PHP_FILE_NAME + temp;
  http.begin(server); 
  int httpCode = http.GET();

  if(httpCode > 0) {
    if(httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.printf("HTTP GET... code: %d\n", httpCode);
    }
  } else {
    Serial.printf("HTTP GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}

void setup() {
  // put your setup code here, to run once:
   pinMode(analogPin, INPUT);
   pinMode(pinADC, INPUT);
   Serial.begin(115200);
   WiFi.begin(ssid, password);
   while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  voltase = detectVoltage(analogPin);
  arusnya = detectArus(pinADC);
  uploadToServer(String(voltase), String(arusnya));
  Serial.println(voltase);
  Serial.println(voltase);
}

void loop() {
  // put your main code here, to run repeatedly:

}
