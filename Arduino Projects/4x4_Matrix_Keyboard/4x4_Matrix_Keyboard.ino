int rowCounter =0; // row counter
int columnCounter =0; // column counter
int foundColumn = 0;

boolean foundCol = false;

int keyValue = 0;
int noKey = 0;

boolean readKey = false;

int debounce = 300; // set this to the lowest value that gives the best result

const int row1 = 2;
const int row2 = 3;
const int row3 = 4;
const int row4 = 5;
const int colA = 8;
const int colB = 9;
const int colC = 10;
const int colD = 11;
const int ledPin = 13; // onboard LED

void setup(){
  Serial.begin(9600);
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);
  pinMode(colA, INPUT_PULLUP);
  pinMode(colB, INPUT_PULLUP);
  pinMode(colC, INPUT_PULLUP);
  pinMode(colD, INPUT_PULLUP);

  //
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // turn LED off
}

void loop(){
  
  if(noKey == 16){ // no keys were pressed
  readKey = true; // keyboard is ready to accept a new keypress
  }

  noKey = 0;

  for(rowCounter=row1; rowCounter<(row4 +1); rowCounter++){
    scanRow(); // switch on one row at a time

    for(columnCounter = colA; columnCounter <colD +1; columnCounter++){
      readColumn(); // read the switch pressed

      if (foundCol== true){
        keyValue =(rowCounter-row1) +4*(columnCounter - colA);
      }
    }
  }

  if(readKey==true && noKey == 15){ // a key has been pressed
    Serial.println(keyValue); // used for debug
    if (keyValue == 13){
      digitalWrite(ledPin, !digitalRead(ledPin)); // toggles LED ON/OFF
    }
  else{
    digitalWrite(ledPin, LOW);
  }

    /********************************************************
    // call to part of the sketch that will use the key number
    */

    //*******************************************************
    readKey = false; // rest the flag
      delay(debounce); // debounce
  }
}

void scanRow(){
  for(int j =row1; j < (row4 +1); j++){
    digitalWrite(j, HIGH);
  }
  digitalWrite(rowCounter , LOW); // switch on one row
}

void readColumn(){
  foundColumn = digitalRead(columnCounter);
  if(foundColumn == 0){
    foundCol = true;
  }
  else{
    foundCol=false;
    noKey=noKey +1; // counter for number of empty columns
  }
}
