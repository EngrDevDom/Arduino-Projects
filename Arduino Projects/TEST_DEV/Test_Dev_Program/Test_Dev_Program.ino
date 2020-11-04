/********************************************************
 *                                                      *
 *                    Test_Dev_Program                  *
 *                                                      *
 *  This is a test program for IO of an Arduino UNO     *
 *  using sensors of Arduino UNO and a load resistors,  *
 *  with LED indicators.                                *                   
 *                                                      *
 ********************************************************/

// Initialize variables
String evalTemp;
String evalVolt;
String evalCurr;
String evalPow;


// Variables to Read Analog
int tempPin = A0;
int PotPin = A1;
int ResPin = A2;
int PhotoResPin = A3;


// Variables to be Calculated
float temp;
float tempC;

float PotM;
float PotMeas;

float Voltage = 0;
float Current = 0;
float Power = 0;


int ledF = 6;   // LED for FAILED
int ledP = 7;   // LED for PASS


String SWBin;
String HWBin;


// Variables to hold value of resistances
float Ra = 0;   // LM35
float Rb = 0;   // Potentiometer
float Rc = 0;   // Fixed Resistor
float Rd = 0;   // Photoresistor


// Variables to hold value of voltages
float Va = 0;   // LM35
float Vb = 0;   // Potentiometer
float Vc = 0;   // Fixed Resistor
float Vd = 0;   // Photoresistor


void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // ANALOG INPUT PINS
  pinMode(tempPin, INPUT);
  pinMode(PotPin, INPUT);
  pinMode(ResPin, INPUT);
  pinMode(PhotoResPin, INPUT);
  
  // DIGITAL OUTPUT PINS
  pinMode(ledF, OUTPUT);
  pinMode(ledP, OUTPUT);

  Serial.println();
  Serial.println("\t/*======================================================================*/");
  Serial.println("\t *                                                                      *");
  Serial.println("\t *                          IO_Test_Program                             *");
  Serial.println("\t *                                                                      *");
  Serial.println("\t *           This is a test program for IO of an Arduino UNO            *");
  Serial.println("\t *           using different sensors of Arduino UNO and a resitor.      *");
  Serial.println("\t *           This calculates the Temp, Voltage, Current  and            *");
  Serial.println("\t *           Power rating if it passes to the acceptable limits.        *");
  Serial.println("\t *                                                                      *");
  Serial.println("\t *                                                                      *");
  Serial.println("\t/*======================================================================*/");
  Serial.println("");


  // SHOW THE RESULTS

  Serial.println("\n\t/*======================================================================*/");
  Serial.print("\n\t\tSW Bin#:\t");
  Serial.print(SWBin);
  Serial.print("\n\t\tHW Bin#:\t");
  Serial.print(HWBin);
  Serial.print("\n\t\tTEST OPTION:\tROOM @25C\t");
  Serial.print("\n\n\t\tTEST#\tRESULT\tUNITS\tP/F\tLOWER\tUPPER\tTEST NAME");
  Serial.print("\n\t\t---------------------------------------------------------");

}


void loop() {

// ******************************************* START ************************************************

// RUN THE TESTS
// --------------------------------------------------------------------------------------------------
  /* TEST 0000 -> PINS CHECK */
  // Pin PULL-UP

  delay(500);
  
// -------------------------------------------------------------------------------------------------

  /*  TEST# 0001 -> TEMPERATURE TEST */
  
  temp = analogRead(tempPin);   // Temp Raw Data
  tempC = temp * 0.48828125;    // Measured Value
  delay(500);

  Serial.print("\n\t\t0001\t");
  Serial.print(tempC);
  Serial.print("\tC\t");
  Serial.print(evalTemp);
  
    // Temp Condition
    if (tempC > -25.05 && tempC < 30.25) {
      evalTemp = "P";
      digitalWrite(ledP, HIGH);
      digitalWrite(ledF, LOW); 
    } else {
      evalTemp = "F";
      digitalWrite(ledP, LOW);
      digitalWrite(ledF, HIGH);
    }
  
// -------------------------------------------------------------------------------------------------

  /*  TEST# 0010 -> RESISTANCE TEST */
  
  // A. Read analog value of Potentiometer (ohms)
  // B. Read analog value of Load Resistor (ohms)
  // C. Read analog value of Photoresistor (ohms)
  // Then convert the raw data to a corresponding equivalent.

  Ra = 1000;  // Set a constant value
  Rb = analogRead(PotPin);        // Read A1
  Serial.println(Rb);             // Show value
  Rc = analogRead(ResPin);        // Read A2
  Serial.println(Rc);             // Show value
  Rd = analogRead(PhotoResPin);   // Read A3
  Serial.println(Rd);             // Show value
  
// -------------------------------------------------------------------------------------------------

  /*  TEST# 0011 -> VOLTAGE TEST */
  
  // From the measured value of Temperature, convert it to an equivalent multiplied to a factor
  // to obtain a variable with mV/C ratio.
  // 5V supply to each components
  // (V)
  Va = tempC * 10.0;    // Voltage calculated based on specs sheet
  
// -------------------------------------------------------------------------------------------------
  
  /*  TEST# 0100 -> CURRENT TEST */
  
  // From 5V supply voltage
  // I1 + I2 + I3 + I4 = Itotal (mA)

  
// -------------------------------------------------------------------------------------------------

  /*  TEST# 0101 -> POWER RATING TEST */
  
  // Measure each components power rating.
  // P = IV (Watts)
  
// -------------------------------------------------------------------------------------------------

  // RESULTS CONDITION
  
  // if all tests is PASS; LedP = HIGH
  // SWBin#: 1
  // HWBin#: 1
  // else; LedF = HIGH
  // SWBin#: 8
  // HWBin#: 8
  
// -------------------------------------------------------------------------------------------------

  Serial.println(" ");
  
// ******************************************** END ***********************************************
  
}
