int pinOut = 7;
int pinA = 8;
int pinB = 9;

void setup() {
  pinMode(pinOut, OUTPUT);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
}

void loop() {
  
  boolean pinAState = digitalRead(pinA);
  Serial.println(pinAState);

  boolean pinBState = digitalRead(pinB);
  Serial.println(pinBState);
  
  boolean pinOutState;
  Serial.println(pinOutState);

  // AND GATE
  pinOutState = pinAState & pinBState;
  digitalWrite(pinOut, pinOutState);
  Serial.println(pinOutState);

}
