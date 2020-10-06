#include <Keypad.h>
 
char keys[4][4]={
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}};
 
byte rowPin[4]={5,6,7,8};
byte colPin[4]={9,10,11,12};
 
Keypad keypad=Keypad(makeKeymap(keys),rowPin,colPin,4,4);
 
void setup() {
 
 Serial.begin(9600);

}
 
void loop() {
 
 char pressed=keypad.getKey();
 
 if(pressed) {
  Serial.println(pressed);
 }

}
