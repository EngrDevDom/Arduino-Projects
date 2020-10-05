#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define led 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initialize global variables
int voltage, resistance;

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // Initialize LCD pin connections
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();

  // Initialize LED pin
  pinMode(led, OUTPUT);

}

void loop() {

  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);

  // calculate the value of Load Resistor
  resistance = voltage / (40e-3);
  
  // print out the value you read:
  Serial.println(voltage);
  Serial.println(resistance);

  // if resistance is higher than 75ohms the LED is ON else OFF
  if (resistance >= 75) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  
  // Prints the value of VOLTAGE in th LCD
  lcd.setCursor(0, 0);
  lcd.print("Voltage:");
  lcd.print(voltage);
  delay(10);
  
  // Prints the value of RESISTANCE in th LCD
  lcd.setCursor(0, 1);
  lcd.print("Resistance:");
  lcd.print(resistance);
  delay(10);

}
