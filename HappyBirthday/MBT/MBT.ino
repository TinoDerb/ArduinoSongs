#include "pitches.h"
#define BUZZER_PIN_1 12           // define pin of first buzzer
#define BUZZER_PIN_2 7            // and second buzzer
int redPin = A0;                  // init redPin 
int greenPin = A2;                // init greenPin 
int bluePin = A4;                 // init bluePin 
int durations[] = {               // init duration of the beat, a bit faster
  4, 8, 
  4, 4, 4,
  2, 4, 8, 
  4, 4, 4,
  2, 4, 8,
  4, 4, 4, 
  4, 4, 4, 8,
  4, 4, 4,
  2
};
int melody[] = {                  // define each note
  NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_F4,
  NOTE_E4, NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_C4, NOTE_C4,
  NOTE_C5, NOTE_A4, NOTE_F4, 
  NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4,
  NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_F4
};

void setup() { // setup all the outputs to pinMode
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(BUZZER_PIN_1, OUTPUT);
  pinMode(BUZZER_PIN_2, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  int size = sizeof(durations) / sizeof(int); // get the size of the melody to loop over
  int randomLEDChoice = random(0, 3); // init a random choice for the LED for certain notes
  int randomSpeakerChoice = random(0, 2); // init a random choice for the speakers for certain notes
  for (int note = 0; note < size; note++) { // for every note
    int duration = 1000 / durations[note]; // get the duration
    if (duration == 500) { // if it is a full note
      // play all speakers and light up all LEDs
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, HIGH);
      digitalWrite(greenPin, HIGH);
      tone(BUZZER_PIN_1, melody[note], duration);
      tone(BUZZER_PIN_2, melody[note], duration);
    } else if(duration == 250){ // if it is a half note
      // Check note and do a specific pattern
      if (melody[note] == NOTE_C4){
        digitalWrite(redPin, HIGH);
        digitalWrite(bluePin, HIGH);
      tone(BUZZER_PIN_1, melody[note], duration);
      } else if (melody[note] == NOTE_D4){
        digitalWrite(greenPin, HIGH);
        digitalWrite(bluePin, HIGH);
      tone(BUZZER_PIN_2, melody[note], duration);
      } else if (melody[note] == NOTE_F4){
        digitalWrite(greenPin, HIGH);
        digitalWrite(redPin, HIGH);
      tone(BUZZER_PIN_1, melody[note], duration);
      } else if (melody[note] == NOTE_G4){
        digitalWrite(redPin, HIGH);
        tone(BUZZER_PIN_2, melody[note], duration);
      } else if (melody[note] == NOTE_C5){
        digitalWrite(bluePin, HIGH);
        tone(BUZZER_PIN_1, melody[note], duration);
        tone(BUZZER_PIN_2, melody[note], duration);
      } else if (melody[note] == NOTE_A4){
        digitalWrite(greenPin, HIGH);
        tone(BUZZER_PIN_2, melody[note], duration);
      } else{ // if a special note, choose randomly
          if (randomLEDChoice == 0){
            digitalWrite(redPin, HIGH);
        } else if (randomLEDChoice == 1){
            digitalWrite(greenPin, HIGH);
        } else{
            digitalWrite(bluePin, HIGH);
        }
        tone(BUZZER_PIN_1, melody[note], duration);
        tone(BUZZER_PIN_2, melody[note], duration);
      }
    } else{ // if it is a quarter note choose randomly
      if (randomLEDChoice == 0){
        digitalWrite(redPin, HIGH);
      } else if (randomLEDChoice == 1){
        digitalWrite(greenPin, HIGH);
      } else{
        digitalWrite(bluePin, HIGH);
      }
      if (randomSpeakerChoice == 0){
        tone(BUZZER_PIN_1, melody[note], duration);
      } else{
        tone(BUZZER_PIN_2, melody[note], duration);
      }
    }
    int pauseBetweenNotes = duration * 1.30; // Add pause between notes
    delay(pauseBetweenNotes);
    // Turn off everything
    noTone(BUZZER_PIN_1);
    noTone(BUZZER_PIN_2);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
}