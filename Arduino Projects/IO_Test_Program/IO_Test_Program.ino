/* ******************************************************
 *                                                      *
 *                    IO_Test_Program                   *
 *                                                      *
 *  This is a test program for IO of an Arduino UNO     *
 *  using a temp transistor LM35 and a load resistor.   *
 *                                                      *
 ********************************************************/

// Initialize variables
String evalTemp;
String evalVolt;
String evalCurr;


// Test # 1 Variables
float tempPin = A1;
float temp;
float tempC;
float Voltage;
float Res = 100.00;
double Current;


int ledF = 8;   // LED for FAILED
int ledP = 9;   // LED for PASS


void setup() {

  Serial.begin(9600);

  pinMode(tempPin, INPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledP, OUTPUT);

  Serial.println("/*********************************************************");
  Serial.println(" *                                                       *");
  Serial.println(" *                    IO_Test_Program                    *");
  Serial.println(" *                                                       *");
  Serial.println(" *  This is a test program for IO of an Arduino UNO      *");
  Serial.println(" *  using a temp transistor LM35 and a load resistor.    *");
  Serial.println(" *                                                       *");
  Serial.println(" *********************************************************/");
  Serial.println("");

}


void loop() {

  Serial.println("/**********************************************************/");
  Serial.println("TEST NO.\tP/F\tMIN\tVALUE\tMAX");
  
  /*  TEST # 1 -> 0001  */
  // TEMPERATURE TEST
  temp = analogRead(tempPin);   // Temp Raw Data
  tempC = temp * 0.48828125;
  if (tempC > -25.05 && tempC < 47.35) {
    evalTemp = " ";
  } else {
    evalTemp = "F";
  }
  
  // Show temp value
  Serial.print("0001");
  Serial.print("\t\t");
  Serial.print(evalTemp);
  Serial.print("\t-25.05\t");   // Lower limit
  Serial.print(tempC);          // Measured Value
  Serial.print("\t47.35\t");    // Upper limit
  Serial.println();
  delay(500);

  /*  TEST # 2 -> 0010  */
  // Calculate Voltage Supplied to the Transistor and Load Resistor
  Voltage = tempC * 0.015;  // Compute Voltage
  if (Voltage > 0.25 && Voltage < 0.75) {
    evalVolt = " ";
  } else {
    evalVolt = "F";
  }
  // Show Voltage value
  Serial.print("0010");
  Serial.print("\t\t");
  Serial.print(evalVolt);
  Serial.print("\t0.25\t");     // Lower limit
  Serial.print(Voltage);        // Measured Value
  Serial.print("\t0.75\t");     // Upper limit
  Serial.println();
  delay(500);
  
  /*  TEST # 3 -> 0011  */
  Current = Voltage/Res;  
  if (Current > 0.005 && Current < 0.25) {
    evalCurr = " ";
  } else {
    evalCurr = "F";
  }
  // Show Current value
  Serial.print("0011");
  Serial.print("\t\t");
  Serial.print(evalCurr);
  Serial.print("\t0.005\t");    // Lower limit
  Serial.print(Current);        // Measured Value
  Serial.print("\t0.25\t");     // Upper limit
  Serial.println();
  delay(500);


  // if all Test PASS
  if (evalTemp == " " && evalVolt == " " && evalCurr == " ") {
    Serial.println("/************************** PASS **************************/");
    digitalWrite(ledP, HIGH);
    digitalWrite(ledF, LOW);
  } else {
    Serial.println("/************************* FAILED *************************/");
    digitalWrite(ledP, LOW);
    digitalWrite(ledF, HIGH);
  }
  
  Serial.println();
  delay(1000);

}
