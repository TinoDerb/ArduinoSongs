#include "pitches.h"
#define BUZZER_PIN_1 4

#define LED1_PIN A0
#define LED2_PIN A2
#define LED3_PIN A4
int eighth = 125; // 8
int quarter = 250; // 4
int half = 500; // 2
int whole = 750; // 1
int durations[] = {
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter, 
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter
};

int melody[] = {
  NOTE_G4, NOTE_F4, NOTE_G4, NOTE_AS4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_DS4,
  NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_G4, 0,
  NOTE_G4, NOTE_F4, NOTE_G4, NOTE_AS4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_DS4,
  0, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_DS4, NOTE_D4, NOTE_DS4, NOTE_F4,
  NOTE_D4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_DS4, NOTE_G4,
  NOTE_F4, NOTE_G4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_DS4, 0,
  NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_C4, 0
};

void setup() { // setup all the outputs to pinMode
  pinMode(BUZZER_PIN_1, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  int size = sizeof(durations) / sizeof(int);
  for (int note = 0; note < size; note++) {
    tone(BUZZER_PIN_1, melody[note], durations[note]);
    if (durations[note] == whole){
      analogWrite(LED1_PIN, 140);
      analogWrite(LED2_PIN, 140);
      analogWrite(LED3_PIN, 140);
    } else if (melody[note] == 0){
      analogWrite(LED1_PIN, 0);
      analogWrite(LED2_PIN, 0);
      analogWrite(LED3_PIN, 0);
    } else if (melody[note] == NOTE_AS2 || melody[note] == NOTE_AS1 || melody[note] == NOTE_A3 || melody[note] == NOTE_A4 || melody[note] == NOTE_CS3 || melody[note] == NOTE_F3){
        analogWrite(LED1_PIN, 140);
        analogWrite(LED3_PIN, 140);
    } else if (melody[note] == NOTE_C4){
        analogWrite(LED1_PIN, 140);
    } else if (melody[note] == NOTE_C5){
        analogWrite(LED3_PIN, 140);
    } else{
        analogWrite(LED2_PIN, 140);
    }
    int pauseBetweenNotes = durations[note]*1.2;
    delay(pauseBetweenNotes);
    noTone(BUZZER_PIN_1);
    analogWrite(LED1_PIN, 0);
    analogWrite(LED2_PIN, 0);
    analogWrite(LED3_PIN, 0);
  }
}
void loop() {
}