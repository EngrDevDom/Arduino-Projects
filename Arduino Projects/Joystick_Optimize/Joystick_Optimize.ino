/*
  Joystick Smoothing

  modified on 21 Jul 2019
  by Saeed Hosseini @ Electropeak
  https://electropeak.com/learn
  This code is based on https://www.arduino.cc/en/Tutorial/Smoothing
*/

const int X = 0;
const int Y = 1;

const int MaxReadings = 10;

int Xreadings[MaxReadings];
int XreadIndex = 0;
int Xtotal = 0;
int X_Pos = 0;

int Yreadings[MaxReadings];
int YreadIndex = 0;
int Ytotal = 0;
int Y_Pos = 0;

int led = 13;

void Smoother(int x_pin, int y_pin)
{
  Xtotal = Xtotal - Xreadings[XreadIndex];
  Ytotal = Ytotal - Yreadings[YreadIndex];
  delay(1);
  Xreadings[XreadIndex] = analogRead(x_pin);
  Yreadings[YreadIndex] = analogRead(y_pin);
  delay(1);
  Xtotal = Xtotal + Xreadings[XreadIndex];
  Ytotal = Ytotal + Yreadings[YreadIndex];
  delay(1);
  XreadIndex = XreadIndex + 1;
  YreadIndex = YreadIndex + 1;
  if (XreadIndex >= MaxReadings) XreadIndex = 0;
  if (YreadIndex >= MaxReadings) YreadIndex = 0;
  delay(1);
  X_Pos = Xtotal / MaxReadings;
  Y_Pos = Ytotal / MaxReadings;

}
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < MaxReadings; i++) {
    Xreadings[i] = 0;
    Yreadings[i] = 0;
  }
  pinMode(led, OUTPUT);
}
void loop() {
  Smoother(X,Y);
  Serial.print("VRx: ");
  Serial.print(X_Pos);
  Serial.print("\t\t");
  Serial.print("VRy: ");
  Serial.println(Y_Pos);
  Serial.println("____________________________________________________________");
  delay(100);

  if (X_Pos == 0 || X_Pos == 1023) {
    digitalWrite(led, HIGH);
  }
  else if (Y_Pos == 0 || Y_Pos == 1023) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
