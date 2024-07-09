#include "pitches.h"
#define BUZZER_PIN_1 12
int eighth = 125; // 8
int quarter = 250; // 4
int half = 500; // 2
int whole = 750; // 1
int durations[] = {
  quarter, half, eighth, quarter, half, quarter, half, whole, quarter, eighth, quarter, half, quarter, whole,
  quarter, half, eighth, quarter, half, quarter, half, quarter, half, quarter, half, quarter, eighth, half, quarter, whole,
  quarter, half, quarter, half, quarter, half, quarter, half, quarter, half, eighth, quarter, half, quarter, whole,
  quarter, half, quarter, half, quarter, half, quarter, half, quarter, half, eighth, quarter, half, quarter, whole, whole
};
int melody[] = {
  NOTE_B3, NOTE_E4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_B4, NOTE_A4, NOTE_FS4, NOTE_E4, NOTE_G4, NOTE_FS4, NOTE_DS4, NOTE_F4, NOTE_B3,
  NOTE_B3, NOTE_E4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_C5, NOTE_B4, NOTE_AS4, NOTE_AS3, NOTE_G4, NOTE_E4,
  NOTE_G4, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_C5, NOTE_B4, NOTE_AS4, NOTE_FS4, NOTE_G4, NOTE_B4, NOTE_AS4, NOTE_AS3, NOTE_B3, NOTE_B4,
  NOTE_G4, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_D5, NOTE_CS5, NOTE_C5, NOTE_GS4, NOTE_C5, NOTE_B4, NOTE_AS4, NOTE_AS3, NOTE_B4, NOTE_E4, NOTE_E4
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