#include "pitches.h"
#define BUZZER_PIN_1 12           // define pin of first buzzer
int redPin = A0;                  // init redPin 
int whitePin = A2;                // init whitePin
int durations[] = {               // init duration of the beat, a bit faster

2, 2, 4, 1,
2, 2, 4, 1,
2, 2, 4, 2, 2, 4, 2, 8, 8, 2, 4, 1,
2, 2, 4, 1,
2, 2, 4, 1,
2, 2, 4, 2, 2, 4, 2, 2, 4, 1
};
int melody[] = {                  // define each note
NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4,
NOTE_G3, NOTE_D4, NOTE_B3, NOTE_C4,
NOTE_G3, NOTE_C4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_C4, NOTE_D4,
NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4,
NOTE_G3, NOTE_D4, NOTE_B3, NOTE_C4,
NOTE_G3, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_D4, NOTE_E4, NOTE_C4
};

void setup() { // setup all the outputs to pinMode
  pinMode(redPin, OUTPUT);
  pinMode(whitePin, OUTPUT);
  pinMode(BUZZER_PIN_1, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  int size = sizeof(durations) / sizeof(int); // get the size of the melody to loop over
  int randomLEDChoice = random(0, 2); // init a random choice for the LED for certain notes
  for (int note = 0; note < size; note++) { // for every note
    int duration = 1000 / durations[note]; // get the duration
    if (duration > 500) { // if it is a full note
      // play all speakers and light up all LEDs
      digitalWrite(redPin, HIGH);
      digitalWrite(whitePin, HIGH);
    } else {
      if (melody[note] == NOTE_G3 || melody[note] == NOTE_B3 || melody[note] == NOTE_A3) {
        digitalWrite(redPin, HIGH);
      }
      if (melody[note] == NOTE_C4 || melody[note] == NOTE_D4 || melody[note] == NOTE_F4 || melody[note] == NOTE_E4 || melody[note] == NOTE_G4) {
        digitalWrite(whitePin, HIGH);
      }
    }
    tone(BUZZER_PIN_1, melody[note], duration);
    int pauseBetweenNotes = duration * 1.30; // Add pause between notes
    delay(pauseBetweenNotes);
    // Turn off everything
    noTone(BUZZER_PIN_1);
    digitalWrite(redPin, LOW);
    digitalWrite(whitePin, LOW);
  }
}