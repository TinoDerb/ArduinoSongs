#include "pitches.h"
#define BUZZER_PIN_1 12
int eighth = 125; // 8
int quarter = 250; // 4
int half = 500; // 2
int whole = 750; // 1
int durations[] = {
  quarter, eighth, 
  quarter, quarter, quarter,
  half, quarter, eighth, 
  quarter, quarter, quarter,
  half, quarter, eighth,
  quarter, quarter, quarter, 
  quarter, quarter, quarter, eighth,
  quarter, quarter, quarter,
  half
};
int melody[] = {
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
  pinMode(BUZZER_PIN_1, OUTPUT);
  int size = sizeof(durations) / sizeof(int);
  for (int note = 0; note < size; note++) {
    tone(BUZZER_PIN_1, melody[note], durations[note]);
    int pauseBetweenNotes = durations[note] * 1.30;
    delay(pauseBetweenNotes);
    noTone(BUZZER_PIN_1);
  }
}

void loop() {
}
