#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 2;
const int echoPin = 3;

long duration;
int distanceCM, distanceInch;

int ledA = 8;
int ledB = 9;
int ledC = 10;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);

  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCM = duration*0.034/2;
  distanceInch = duration*0.0133/2;

  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distanceCM);
  lcd.print(" cm");
  delay(10);

  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" inch");
  delay(10);


  // Main functionality
  if (distanceCM == 11 || distanceInch == 4) {
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
  }
  else if (distanceCM > 11 || distanceInch > 4){
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
  }
  else {
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
  }

}
