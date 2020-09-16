#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();

  // Message #1
  lcd.setCursor(2,0);
  lcd.print("1:47 PM");

  // Message #2
  lcd.setCursor(0,1);
  lcd.print("09/16/2020");
}

void loop()
{
   // Message #1
   lcd.setCursor(16,1);
   lcd.print(" ");
   delay(250);

   // Message #2
   lcd.setCursor(16,2);
   lcd.print(" ");
   delay(250);
}
