/*-----( Import needed libraries )-----*/
/*-----( Declare Constants and Pin Numbers )-----*/
#define led 13  // built-in LED

/*-----( Declare objects )-----*/
/*-----( Declare Variables )-----*/
int ByteReceived;

void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);  
  Serial.println("--- Start Serial Monitor SEND_RCVE ---");
  Serial.println(" Type in Box above, . ");
  Serial.println("(Decimal)(Hex)(Character)");  
  Serial.println(); 
}
//--(end setup )---

void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  if (Serial.available() > 0)
  {
    ByteReceived = Serial.read();
    Serial.print(ByteReceived);   
    Serial.print("        ");      
    Serial.print(ByteReceived, HEX);
    Serial.print("       ");     
    Serial.print(char(ByteReceived));
    
    if(ByteReceived == '1') // Single Quote! This is a character.
    {
      digitalWrite(led,HIGH);
      Serial.print(" LED ON ");
    }
    
    if(ByteReceived == '0')
    {
      digitalWrite(led,LOW);
      Serial.print(" LED OFF");
    }
    
    Serial.println();    // End the line

  // END Serial Available
  }
}

//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

/*********( THE END )***********/
