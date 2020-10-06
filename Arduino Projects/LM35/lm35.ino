// LM35 temperature interface by KUNAL GOKHE
float temp;
int tempPin = A1; // analog input pin
int sampleTime = 1000; // 1 second dafault 

void setup()
{
  Serial.begin(9600);
}

void loop()
{ 
  Serial.print("LM35 temperature interface by KUNAL GOKHE ");
  Serial.println("Dont forgot to like, share and subscribe");
  //gets and prints the raw data from the lm35
  temp = analogRead(tempPin);
  Serial.print("RAW DATA: ");
  Serial.print (temp);
  Serial.println(" ");
  //converts raw data into degrees celsius and prints it out
  // 500mV/1024=.48828125
  temp = temp * 0.48828125;
  Serial.print("CELSIUS: ");
  Serial.print(temp);
  Serial.println("*C ");
  //converts celsius into fahrenheit 
  temp = temp *9 / 5;
  temp = temp + 32;
  Serial.print("FAHRENHEIT: ");
  Serial.print(temp);
  Serial.println("*F");
  delay(sampleTime);

}
