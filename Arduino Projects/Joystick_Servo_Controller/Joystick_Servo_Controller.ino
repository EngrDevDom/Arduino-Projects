#include <Servo.h>

Servo servo;
int x_axis;
int servo_val;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  servo.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  x_axis = analogRead(A0);
  servo_val = map(x_axis, 0, 1023, 0, 180);
  servo.write(servo_val);
  Serial.println(servo_val);
}
