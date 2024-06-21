#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>

 LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7);
#define Type DHT11
 int dhtPin = 2;
 DHT HT(dhtPin, Type);
 int humidity;
 float tempC;
 float tempF;
 int dt (500);
 int rojo = 4;
 int verde = 6;

void setup() {
  Serial.begin(9600);
  HT.begin();
  pinMode(rojo,OUTPUT);
  pinMode(verde,OUTPUT);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.begin(16, 2);
  lcd.clear();

}

void loop() {
 lcd.clear();
 humidity = HT.readHumidity();
 tempC = HT.readTemperature();
 lcd.setCursor(0, 0);
 lcd.print("Humedad: ");
 lcd.print(humidity);
 lcd.print("%");
 lcd.setCursor(0,1);
 lcd.print("Temp: ");
 lcd.print(tempC);
 lcd.print(" C");
 delay(dt);
 if(HT.readTemperature()>12){
  digitalWrite(verde,HIGH);
  digitalWrite(rojo,LOW);
 }
 if(HT.readTemperature()<=12){
  digitalWrite(rojo,HIGH);
  digitalWrite(verde,LOW);
 }
}
