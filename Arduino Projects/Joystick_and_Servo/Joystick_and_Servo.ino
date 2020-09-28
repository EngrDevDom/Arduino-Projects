#include <Servo.h>
  
Servo servo;

int joyX = A0;
int joyY = A1;
int led = 8;
int servoVal;
  
void setup() {
  
  Serial.begin(9600);
  
  servo.attach(9);
  pinMode(led, OUTPUT);

}
  
void loop() {

  servoVal = analogRead(joyX);
  servoVal = map(servoVal, 0, 1023, 0, 180);
  servo.write(servoVal);
  Serial.println(servoVal);
  
  servoVal = analogRead(joyY);
  servoVal = map(servoVal, 0, 1023, 70, 180);
  servo.write(servoVal);
  Serial.println(servoVal);
  delay(15);

  if (servoVal == 0) {
      digitalWrite(led, HIGH);
  }
  else if (servoVal == 180) {
      digitalWrite(led, LOW);
  }

}
