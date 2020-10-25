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
String evalPow;


// Test # 1 Variables
int tempPin = A1;
float temp;
float tempC;
float Voltage = 0;
float Current = 0;
float Power = 0;
float Res = 1000.00;    // 1k Resistor connected to GND


int ledF = 8;   // LED for FAILED
int ledP = 9;   // LED for PASS


void setup() {

  Serial.begin(9600);

  pinMode(tempPin, INPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledP, OUTPUT);

  Serial.println();
  Serial.println("/**********************************************************************************/");
  Serial.println(" *                                                                                *");
  Serial.println(" *                                 IO_Test_Program                                *");
  Serial.println(" *                                                                                *");
  Serial.println(" *                This is a test program for IO of an Arduino UNO                 *");
  Serial.println(" *                using a temp transistor LM35 and a load resistor.               *");
  Serial.println(" *                This calculates the Temp, Voltage, Current  and                 *");
  Serial.println(" *                Power rating if it passes to the acceptable limits.             *");
  Serial.println(" *                                                                                *");
  Serial.println(" *                                                                                *");
  Serial.println("/**********************************************************************************/");
  Serial.println("");

}


void loop() {

  // START
  
  Serial.println("/==================================================================================/");
  Serial.println("TEST NO.\tTEST NAME\tP/F\tMIN\t\tVALUE\t\tMAX");
  
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
  Serial.print("TEMPERATURE");
  Serial.print("\t");
  Serial.print(evalTemp);
  Serial.print("\t-55.0 C\t\t");        // Lower limit
  Serial.print(tempC);                  // Measured Value
  Serial.print(" C\t\t150.0 C");        // Upper limit
  Serial.println();
  delay(500);

  /*  TEST # 2 -> 0010  */
  // Calculate Voltage Supplied to the Transistor and Load Resistor
  Voltage = tempC * 10.0;               // Compute Voltage
  if (Voltage > -550.0 && Voltage < 1500.0) {
    evalVolt = " ";
  } else {
    evalVolt = "F";
  }
  // Show Voltage value
  Serial.print("0010");
  Serial.print("\t\t");
  Serial.print("VOLTAGE");
  Serial.print("\t\t");
  Serial.print(evalVolt);
  Serial.print("\t-550.0 mV\t");        // Lower limit
  Serial.print(Voltage);                // Measured Value
  Serial.print(" mV\t1500.0 mV");       // Upper limit
  Serial.println();
  delay(500);
  
  /*  TEST # 3 -> 0011  */
  Current = (Voltage / Res) * 1000;  
  if (Current > -550.0 && Current < 1500) {
    evalCurr = " ";
  } else {
    evalCurr = "F";
  }
  // Show Current value
  Serial.print("0011");
  Serial.print("\t\t");
  Serial.print("CURRENT");
  Serial.print("\t\t");
  Serial.print(evalCurr);
  Serial.print("\t-550.0 uA\t");         // Lower limit
  Serial.print(Current);                // Measured Value
  Serial.print(" uA\t1500 uA\t");     // Upper limit
  Serial.println();
  delay(500);


  /*  TEST # 4 -> 0100  */
  Power = (Voltage * Current) * 0.001;
  if (Power > -302.50 && Power < 2250.0) {
    evalPow = " ";
  } else {
    evalPow = "F";
  }
  // Show Current value
  Serial.print("0100");
  Serial.print("\t\t");
  Serial.print("POWER");
  Serial.print("\t\t");
  Serial.print(evalPow);
  Serial.print("\t-302.50 uW\t");          // Lower limit
  Serial.print(Power);                    // Measured Value
  Serial.print(" uW\t2250.0 uW\t");     // Upper limit
  Serial.println();
  delay(500);


  // IF PASSES ALL TESTS
  if (evalTemp == " " && evalVolt == " " && evalCurr == " " && evalPow == " ") {
    Serial.println("/====================================== PASS ======================================/");
    digitalWrite(ledP, HIGH);
    digitalWrite(ledF, LOW);
  } else {
    Serial.println("/====================================== FAILED ======================================/");
    digitalWrite(ledP, LOW);
    digitalWrite(ledF, HIGH);
  }

  Serial.println();
  delay(1000);
  // END

}
