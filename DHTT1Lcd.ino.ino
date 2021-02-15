#include <DHT.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(3,4,5,6,7,8);

#define DHTPIN A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup(){
  lcd.begin(16, 2);
  dht.begin();
}

void loop(){
  int chk = dht.read(DHTPIN);
  lcd.setCursor(0,0); 
  String valTemp=String(int(dht.readTemperature(true)));
  lcd.print("Temp: ");
  lcd.print(valTemp);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("F");
  
  lcd.setCursor(0,1); 
  lcd.print("Hum: ");
  String valHum=String(int(dht.readHumidity()));
  lcd.print(valHum);
  lcd.print(" ");
  lcd.print("%");
  delay(2000);
}
