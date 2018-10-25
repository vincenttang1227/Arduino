
//////主程式
#include "music.h"

const int piezoPin = 8; //piezo
const int rPin = 5;  //red LED
const int gPin = 4;  //green LED
const int bPin = 3;  //yellow LED
const int pPin = 2;  //pushbutton

int ledState = 0;
int ledOn = false;

// notes
int melody[] = {
  NOTE_, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_G3, NOTE_,
  NOTE_, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_,
  
  NOTE_, NOTE_G3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_,
  NOTE_, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_,
  
  NOTE_, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_G3, NOTE_,
  NOTE_, NOTE_G3, NOTE_A3, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_,
  
  NOTE_, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4,
  NOTE_C4, NOTE_A3, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_,
  //
  NOTE_, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_A3, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_,
  NOTE_, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_G3, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_D4, NOTE_C4, NOTE_,
  
  NOTE_, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_,
  NOTE_, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_,
  
  NOTE_, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_A3, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_,
  NOTE_, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_G3, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_D4, NOTE_C4, NOTE_,
  
  NOTE_, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4,
  NOTE_G3, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_,
};

int noteDurations[] = {
  16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 8, 8,
  16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 8, 8,
  
  16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 8,
  16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 8, 8,
  
  16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 8, 8,
  16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 8, 8,
  
  16, 16, 16, 16, 16, 16, 16, 16, 8,
  16, 16, 16, 16, 16, 16, 8, 16, 4, 8,
  //
  16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 16, 4, 8,
  16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 16, 4, 8,
  
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 4, 8,
  16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 16, 8, 8,
  
  16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 16, 4, 8,
  16, 16, 16, 16, 16, 16, 8, 16, 16, 16, 16, 4, 8,
  
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 4, 
  16, 8, 16, 16, 16, 4, 8, 
};

// calculates the number of elements in the melody array.
int musicLength=sizeof(melody)/sizeof('NOTE_F5');

void setup() {  
  pinMode(pPin, INPUT);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  int pPinState=digitalRead(pPin);
  if(pPinState==HIGH) {
    ledState = 1;
  }
  if (pPinState==LOW and ledState ==1) {
    ledState = 2;
    ledOn = not ledOn;
  }
  if (ledOn && pPinState!=HIGH) {
    for (int thisNote = 0; thisNote < musicLength; thisNote++) {
      // blink the three LEDs in sequence
      if (thisNote%3==0){    
        digitalWrite(rPin, HIGH);
        digitalWrite(gPin, LOW);
        digitalWrite(bPin, LOW);
      }
      else if (thisNote%3==1){    
        digitalWrite(rPin, LOW);
        digitalWrite(gPin, HIGH);
        digitalWrite(bPin, LOW);
      }
      else if (thisNote%3==2){    
        digitalWrite(rPin, LOW);
        digitalWrite(gPin, LOW);
        digitalWrite(bPin, HIGH);
      }

      // calculate the note duration. change tempo by changing 2000 to other values
      int noteDuration = 2000/noteDurations[thisNote];
      tone(piezoPin, melody[thisNote],noteDuration);
      
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well
      float pauseBetweenNotes = noteDuration * 2;
      
      //split the delay into two parts and check to see
      //whether the pushbutton is pressed to turn off
      //the sound and light
      delay(pauseBetweenNotes/2);
      if(digitalRead(pPin)==HIGH) {
        break;      
      }
      delay(pauseBetweenNotes/2);
      if(digitalRead(pPin)==HIGH) {
        break;      
      }
    }
  }
  else if (not ledOn) {
    digitalWrite(rPin, LOW);
    digitalWrite(gPin, LOW);
    digitalWrite(bPin, LOW);
  }
}
