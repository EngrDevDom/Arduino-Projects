int val;
int tempPin = 1;

void setup() {
  
  Serial.begin(9600);
  
}

void loop() {

  val = analogRead(tempPin);
  
  float mv = (val/1024.0)*5000;
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;

  /* Get temperature at degree Celsius */
  Serial.print("TEMPERATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(1000);

  /* Get temperature at degree Fahrenheit */
  Serial.print("TEMPERATURE = ");
  Serial.print(farh);
  Serial.print("*F");
  Serial.println();
  delay(1000);

}
