// GLOBAL VARIABLES
int num = 0;

void setup() {
  for (int i=22; i<=36; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {

  // PATTERN #1 : Right to Left
  for (int i=22; i<=36; i++) {
    digitalWrite(i, LOW);
    delay(100);
  }
  for (int i=22; i<=36; i++) {
    digitalWrite(i, HIGH);
    delay(100);
  }

  // RESET
  for (int i=22; i<=36; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  
  // PATTERN #2 : Left to Right
  for (int i=36; i>=22; i--) {
    digitalWrite(i, LOW);
  }
  for (int i=36; i>=22; i--) {
    digitalWrite(i, HIGH);
    delay(100);
  }
  for (int i=36; i>=22; i--) {
    digitalWrite(i, LOW);
    delay(100);
  }

  // PATTERN #3 : Even and Odd
  for (int i=22; i<=36; i++) {
    num = i%2;
    if (num==0) {
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i, LOW);
    }
    else if (num != 0) {
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i, LOW);
    }
  }

}
