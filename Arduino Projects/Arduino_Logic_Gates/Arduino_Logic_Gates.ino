/* Arduino Logic Gates */

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;
const int ledPin =  13;      // the number of the LED pin

// 7-Segment Pins
const int a = 4;
const int b = 5;
const int c = 6;
const int d = 7;
const int e = 8;
const int f = 9;
const int g = 10;

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  // iniatialize 7-Segment Pins as output:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // AND GATE   -> buttonState1 == HIGH && buttonState2 == HIGH
  // OR GATE    -> buttonState1 == HIGH || buttonState2 == HIGH
  // NAND GATE  -> buttonState1 == LOW && buttonState2 == LOW

  if (buttonState1 == LOW && buttonState2 == LOW || buttonState1 == HIGH && buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);

    // Output 1
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);

    // Output 0
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  delay(500);
}
