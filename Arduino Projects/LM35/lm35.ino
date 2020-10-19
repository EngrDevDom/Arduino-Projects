#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initialize variables
float temp;
float tempC;

int tempPin = A1; // analog input pin
int sampleTime = 500; // 1 second dafault 

int goodLED = 8;
int badLED = 9;

int buzz = 7;

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Initialize LCD pin connections
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  
  pinMode(goodLED, OUTPUT);
  pinMode(badLED, OUTPUT);

  pinMode(buzz, OUTPUT);

}

void loop() {
  
  temp = analogRead(tempPin);
  Serial.print("RAW DATA: ");
  Serial.print (temp);
  Serial.println(" ");

  
  //converts raw data into degrees celsius and prints it out
  // 500mV/1024=.48828125
  tempC = temp * 0.48828125;
  Serial.print("CELSIUS: ");
  Serial.print(tempC);
  Serial.println("*C ");
  delay(sampleTime);

  lcd.setCursor(0, 0);
  lcd.print("Amb Temp: ");
  lcd.print(tempC);


  lcd.setCursor(0, 1);
  lcd.print("Status: ");
  
  // Main functionality
  if (tempC <= 36.13) {
    digitalWrite(goodLED, HIGH);
    digitalWrite(badLED, LOW);
    digitalWrite(buzz, LOW);
    Serial.println("Status: GOOD!");
    lcd.print("GOOD!");
  }
  else if (tempC > 36.13) {
    digitalWrite(goodLED, LOW);
    digitalWrite(badLED, HIGH);
    digitalWrite(buzz, HIGH);
    delay(250);
    digitalWrite(buzz, LOW);
    delay(250);
    Serial.println("Status: BAD!");
    lcd.print("BAD!");
  }
  else {
    digitalWrite(goodLED, LOW);
    digitalWrite(badLED, LOW);
    digitalWrite(buzz, LOW);
  }

}
