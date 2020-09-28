// Control LED with Joystick and a Switch

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

// Initialize led pins
int ledA = 8;
int ledB = 9;
int ledC = 10;
int ledD = 11;

void Smoother(int x_pin, int y_pin) {
  
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

  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);

  for (int i = 0; i < MaxReadings; i++) {
    Xreadings[i] = 0;
    Yreadings[i] = 0;
  }
  
}

void loop() {
  
  Smoother(X,Y);
  Serial.print("VRx: ");
  Serial.print(X_Pos);
  Serial.print("\t\t");
  Serial.print("VRy: ");
  Serial.println(Y_Pos);
  Serial.println("____________________________________________________________");
  delay(50);

  // Initiate led status
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, LOW);
  
  // Conditions
  if (X_Pos == 501 && Y_Pos == 981 || Y_Pos == 982) {
    digitalWrite(ledA, HIGH);
  }
  else if (X_Pos == 501 && Y_Pos == 0) {
    digitalWrite(ledC, HIGH);
  }
  else if (X_Pos == 0 && Y_Pos == 466) {
    digitalWrite(ledD, HIGH);
  }
  else if (X_Pos == 981 || X_Pos == 982 && Y_Pos == 466) {
    digitalWrite(ledB, HIGH);
  }

}
