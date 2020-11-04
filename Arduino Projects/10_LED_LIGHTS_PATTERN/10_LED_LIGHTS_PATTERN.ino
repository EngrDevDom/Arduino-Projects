// 10 LED LIGHTS PATTERN

void setup() {

 for (int i=2; i<=13; i++) {
  pinMode(i, OUTPUT);
 }

}

void loop() {

  for (int i=2; i<=13; i++) {
    digitalWrite(i, HIGH);
    delay(50);
  }

  for (int i=2; i<=13; i++) {
    digitalWrite(i, LOW);
    delay(50);
  }

  for (int i=13; i>=2; i--) {
    digitalWrite(i, HIGH);
    delay(50);
  }

  for (int i=13; i>=2; i--) {
    digitalWrite(i, LOW);
    delay(50);
  }

}
