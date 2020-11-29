#define PinA 6
#define PinB 7

void setup() {
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
}

void loop() {
  digitalWrite(PinA, HIGH);
  digitalWrite(PinB, LOW);
}
