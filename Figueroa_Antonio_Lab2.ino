
// Keeps track of the next millis() value at which we should run
unsigned long nextRun = 0;

// What is the current value of our scanner?
float currentVal = 0.01;
// Determines both direction and amount of change per cycle
float interval = 0.01;

// Constants
const int winLED = 3;      //Indicates a win
const int looseLED = 4;    //Indicates a loss

const int first = 12;
const int second = 11;
const int third = 10;
const int fourth = 9;
const int fifth = 8;
const int time = 75;

const int BUTTON = 2;     //Button Location

void setup() {

  pinMode(winLED,OUTPUT);
  pinMode(looseLED,OUTPUT);
  
  pinMode(first, OUTPUT);
  pinMode(second, OUTPUT);
  pinMode(third, OUTPUT);
  pinMode(fourth, OUTPUT);
  pinMode(fifth, OUTPUT);
  
  pinMode(BUTTON,INPUT);
  
}

void doStuff(){
  if (currentVal > 1 || currentVal <= 0){
    interval *= -1;
  }
   currentVal += interval;
   updateLarry(currentVal);
}


void updateLarry(float val){
  // a value of zero will light the first led
  // a value of 1 will light the last led
  // there iwll be stuff in between... 
  digitalWrite(first,(val > 0 && val <= 0.2)?HIGH:LOW);
  digitalWrite(second,(val >= 0.2 && val <= 0.4)?HIGH:LOW);
  digitalWrite(third,(val >= 0.4 && val <= 0.6)?HIGH:LOW);
  digitalWrite(fourth,(val >= 0.6 && val <= 0.8)?HIGH:LOW);
  digitalWrite(fifth,(val >= 0.8 && val <= 1.0)?HIGH:LOW);
  
  if (digitalRead(BUTTON) == HIGH){
    if (val >= 0.4 && val <= 0.6){
      digitalWrite(winLED,HIGH);
      digitalWrite(looseLED,LOW);
    }else{
      digitalWrite(looseLED,HIGH);
      digitalWrite(winLED,LOW);
    }
  }else{
    digitalWrite(winLED,LOW);
    digitalWrite(looseLED,LOW);
  }
  
}

void loop() {
  unsigned long currentTime = millis();
  if(currentTime >= nextRun){
    doStuff();
    nextRun = millis() + 7; 
  }
}
