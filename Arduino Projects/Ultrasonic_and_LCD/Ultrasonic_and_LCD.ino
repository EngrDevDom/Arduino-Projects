#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distanceCM, distanceInch;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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

}
