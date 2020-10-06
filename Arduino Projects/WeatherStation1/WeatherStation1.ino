    /////////////////////////////////////////////////////////////////
   //            Arduino Weather Station #1             v1.02     //
  //       Get the latest version of the code here:              //
 //         http://educ8s.tv/arduino-weather-station-1/         //
/////////////////////////////////////////////////////////////////


#include "DHT.h"
#include <LiquidCrystal.h>


#define DHTPIN 22     // what pin we're connected to

#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(8,9,4,5,6,7); 

void setup(void) {
  lcd.begin(16, 2);
  lcd.print("Reading sensor");
  dht.begin();
}

void loop() {
  
  float temperature, humidity;

  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  delay(2000); 

 lcd.clear();

 char tempF[6]; 
 char humF[6];
 dtostrf(temperature, 5, 1, tempF);
 dtostrf(humidity, 2, 0, humF);

 lcd.print("T:"); 
 lcd.print(tempF);
 lcd.print((char)223);
 lcd.print("C ");
 lcd.print("H: ");
 lcd.print(humF);
 lcd.print("%");
}
