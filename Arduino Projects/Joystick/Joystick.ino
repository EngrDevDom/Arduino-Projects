const int VRyPin = A1;
const int SWPin  = 2;

int VRx = 0;        // value read from the horizontal pot
int VRy = 0;        // value read from the vertical pot
int SW = 0;         // value read from the switch

void setup() {
  Serial.begin(9600);
  pinMode(SWPin,INPUT_PULLUP);
}

void loop() {

  VRx = analogRead(VRxPin);
  VRy = analogRead(VRyPin);
  SW = digitalRead(SWPin);

  // print the results to the Serial Monitor:
  Serial.print("VRrx = ");
  Serial.print(VRx);
  Serial.print("\tVRry = ");
  Serial.print(VRy);
  Serial.print("\tSW = ");
  Serial.println(SW);

  delay(200);
}
