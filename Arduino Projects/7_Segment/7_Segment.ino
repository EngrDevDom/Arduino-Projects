void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  for(int i=2; i<9; i++) {
    digitalWrite(i, HIGH);
    delay(250);
  }
  for(int i=2; i<9; i++) {
    digitalWrite(i, LOW);
    delay(250);
  }
}
