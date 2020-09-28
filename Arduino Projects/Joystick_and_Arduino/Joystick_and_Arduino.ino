/*
  Joystick and Arduino

  modified on 21 Jul 2019
  by Saeed Hosseini @ Electropeak
  https://electropeak.com/learn
*/

const int SW = 2; // SW
const int X = 0; // VRx
const int Y = 1; // VRy
int led = 13;
int VRx = analogRead(X);
int VRy = analogRead(Y);

void setup() {
  
  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);
  pinMode(led, OUTPUT);

}

void loop() {

  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW));

    if (digitalRead(SW) == 1) {
      digitalWrite(led, LOW);
    }

    else if (digitalRead(SW) == 0) {
      digitalWrite(led, LOW);
    }
  
  Serial.print("\t\t");
  Serial.print("VRx: ");
  Serial.print(analogRead(X));
  Serial.print("\t\t");
  Serial.print("VRy: ");
  Serial.println(analogRead(Y));
  Serial.println("____________________________________________________________");
  delay(500);
  
}
