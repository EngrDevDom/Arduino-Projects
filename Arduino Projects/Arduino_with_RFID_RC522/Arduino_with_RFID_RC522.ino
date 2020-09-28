#include <Keyboard.h>
#include <SPI.h>
#include <MFRC522.h> // for this thing you need to download on the library (Step 3)

#define SS_PIN 10 // the SS is connect to pin 10
#define RST_PIN 9 // the Reset is connect to pin 9
#define KEY_RETURN 0xB0 //The hex value for the return key is 0xB0.

MFRC522 mfrc522 ( SS_PIN, RST_PIN ) ;
char Enter = KEY_RETURN; // Return key is declared as Enter
String readid;
String card1 ="32cee1b"; // the UID of your card1
String 1234 = "1234"; // the password for your Line account
String card2 = "c6506323"; // the UID of your card2
String 1234 = "1234"; // the password for your computer

void setup( ) 
{
   Serial.begin(9600);
   Keyboard.begin();
   SPI.begin();
   mfrc522.PCD_Init();
}

void temp(byte *buffer, byte bufferSize)
{
  readid="";
  for(byte i = 0;i<bufferSize; i++)
  {
    readid=readid+String(buffer[i], HEX);
  }
}
void loop( ) 
{
 if(!mfrc522.PICC_IsNewCardPresent()) 
 {
  return;
 }
 if(!mfrc522.PICC_ReadCardSerial()) 
 {
  return;
 }
 // RFID-RC522 is reading the Mifare Card
 temp(mfrc522.uid.uidByte, mfrc522.uid.size);
 
 if (readid == card1){  // if the RFID-RC522 read card1
  Keyboard.print("1234"); // it will print out the password "1234"            
 }
 Keyboard.releaseAll(); // the keyboard will release all the botton pieces
 delay(100); // wait for 0.1 second
 Keyboard.press(Enter); // it will press "Enter"
 Keyboard.releaseAll(); // the keyboard will release all the botton pieces
 delay(1000); // wait for 1 second

if (readid == card2){ // if the RFID-RC522 read card1 
  Keyboard.print("1234"); // it will print out the password "1234"
}

Keyboard.releaseAll(); // the keyboard will release all the botton pieces
delay(100); // wait for 0.1 second
Keyboard.press(Enter); // it will press "Enter"
Keyboard.releaseAll(); // the keyboard will release all the botton pieces
delay(1000); // wait for 1 second
   
}
