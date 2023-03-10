
/*
ACS712ELCTR-05B-T jangkauan pengukuran = ±5 A, sensitivitas = 185 mV/A
ACS712ELCTR-20A-T jangkauan pengukuran = ±20 A, sensitivitas = 100 mV/A
ACS712ELCTR-30A-T jangkauan pengukuran = ±30 A, sensitivitas = 66 mv/A
 
--- www.nyebarilmu.com --- */
 
const int pinADC = A0;
int sensitivitas = 185; //tegantung sensor arus yang digunakan, yang ini 5A
int nilaiadc= 00;
int teganganoffset = 2500; //nilai pembacaan offset saat tidak ada arus yang lewat
double tegangan = 00;
double nilaiarus = 00;
 
void setup(){
Serial.begin(9600); //baud komunikasi serial monitor 9600bps
Serial.print("*MODULE ARUS*"); //menuliskan "Hello World"
Serial.print("*nyebarilmu.com*"); //menuliskan "nyebarilmu.com"
 
delay(2000);
}
 
void data_olah(){
  nilaiadc = analogRead(pinADC);
  tegangan = (nilaiadc / 1024.0) * 5000;
  nilaiarus = ((tegangan - teganganoffset) / sensitivitas);
}
 
void loop(){
   data_olah();
  Serial.print("Nilai ADC yang terbaca = " );
  Serial.print(nilaiadc);
 
  Serial.print("\t tegangan (mV) = ");
  Serial.print(tegangan,3);
 
  Serial.print("\t Arus = ");
  Serial.println(nilaiarus,3);
 
  delay(1000);
}
