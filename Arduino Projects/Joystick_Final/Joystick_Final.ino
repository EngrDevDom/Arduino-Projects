int button = 2; 
int vrx = A1; 
int vry = A2;

 int xdata = 0; 
 int ydata = 0; 

int led1 = 8; //FORWARD
int led2 = 9; // RIGHT
int led3 = 10; //LEFT
int led4 = 11; //Reverse
int led5 = 13; // indicator

int flag = 0; 
int buttonf = 0; 


void setup() {

  Serial.begin(9600); 
  pinMode(vrx, INPUT); 
  pinMode(vry, INPUT); 

  pinMode(button, INPUT); 
  digitalWrite(button , HIGH); 

  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  //keep all the led's off by default
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  

}

void loop() {

control(); 

if( buttonf == 1 )
{
 joystick();  
}

if( buttonf == 0 )
{
 delay(100);    
}


}

void control()
{
if (( digitalRead(button) == LOW ) && (buttonf == 0))
{

   Serial.println(" Started");
   digitalWrite(led5, HIGH);  
  buttonf = 1; 
  delay(1000);

 
}

if (( digitalRead(button) == LOW ) && (buttonf == 1))
{
  digitalWrite(led5, LOW); 
  Serial.println("ended"); 
  buttonf = 0; 
  delay(1000); 
}
 digitalWrite(button , HIGH);
}


void joystick()
{

  xdata = analogRead(vrx); 
  ydata = analogRead(vry); 
  xdata = map(xdata,0,1023,0,10); 
  ydata = map(ydata,0,1023,0,10); 

/*
Serial.println(""); 
  Serial.print("xdata: "); 
  Serial.println(xdata); 
  Serial.print("ydata :"); 
  Serial.print(ydata);
delay(1000); 
*/

// stop 

if ( (xdata == 4) && (ydata ==4) && (flag == 0) )
{
  digitalWrite(led1, LOW); //FORWARD
  digitalWrite(led2, LOW); //RIGHT
  digitalWrite(led3, LOW); //LEFT
  digitalWrite(led4, LOW); //Reverse
  Serial.println("Stopped"); 
  flag = 1; 
  delay(100); 
}

//forward
if ( (xdata > 4) && (ydata >= 4) && ( flag == 1) )
{
  digitalWrite(led1, HIGH); //FORWARD
  digitalWrite(led2, LOW); //RIGHT
  digitalWrite(led3, LOW); //LEFT
  digitalWrite(led4, LOW); //Reverse
  Serial.println("Forward"); 
  flag = 0; 
  delay(100); 
}

//Right
if ( (xdata >= 4) && (ydata > 4) && ( flag == 1) )
{
  digitalWrite(led1, LOW); //FORWARD
  digitalWrite(led2, HIGH); //RIGHT
  digitalWrite(led3, LOW); //LEFT
  digitalWrite(led4, LOW); //Reverse
  Serial.println("Right"); 
  flag = 0; 
  delay(100); 
}


  //Left
if ( (xdata >= 4) && (ydata < 4) && ( flag == 1) )
{
  digitalWrite(led1, LOW); //FORWARD
  digitalWrite(led2, LOW); //RIGHT
  digitalWrite(led3, HIGH); //LEFT
  digitalWrite(led4, LOW); //Reverse
  Serial.println("Left"); 
  flag = 0; 
  delay(100); 
}


  //Backward
if ( (xdata < 4) && (ydata >= 4) && ( flag == 1) )
{
  digitalWrite(led1, LOW); //FORWARD
  digitalWrite(led2, LOW); //RIGHT
  digitalWrite(led3, LOW); //LEFT
  digitalWrite(led4, HIGH); //Reverse
  Serial.println("Reverse"); 
  flag = 0; 
  delay(100); 
}
  
}
