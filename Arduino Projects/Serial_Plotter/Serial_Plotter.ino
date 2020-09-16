void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int j=0; j<360; j++) {
    Serial.print(sin(j*(PI/180)));
    Serial.print("");
    Serial.print(sin(j+180)*(PI/180));
  }
}
