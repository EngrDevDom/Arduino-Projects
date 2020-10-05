#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define Rled 2
#define Gled 3
#define Bled 4

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  // Initialize LCD pin connections
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();

  for (int i=2; i<=4; i++) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(0, 0);
  lcd.print("LED");

  lcd.setCursor(0, 1);
  // shows what LED is ON
  if (Rled == HIGH) {
    lcd.print("RED");
  }
  else if (Gled == HIGH) {
    lcd.print("GREEN");
  }
  else if (Bled == HIGH) {
    lcd.print("BLUE");
  }
  else {
    lcd.print("OFF");
  }

  digitalWrite(Rled, HIGH);
  delay(1000);
  digitalWrite(Rled, LOW);
  delay(1000);
  
  digitalWrite(Gled, HIGH);
  delay(1000);
  digitalWrite(Gled, LOW);
  delay(1000);
  
  digitalWrite(Bled, HIGH);
  delay(1000);
  digitalWrite(Bled, LOW);
  delay(1000);

}
