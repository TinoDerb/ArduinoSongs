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
  quarter, quarter, quarter, quarter, quarter, quarter, eighth,  eighth, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, eighth,  eighth, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, eighth,  eighth, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, eighth,  eighth, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, eighth,  eighth, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, eighth,  eighth, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, eighth,  eighth, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, eighth,  eighth, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, quarter,
  quarter, quarter, quarter, quarter, quarter, quarter, whole, quarter, whole
};
int melody[] = {
  NOTE_AS2, NOTE_DS3, NOTE_AS2, NOTE_DS3, NOTE_AS2, NOTE_DS3, NOTE_AS2, NOTE_AS2, 0,
  NOTE_AS2, NOTE_DS3, NOTE_AS2, NOTE_DS3, NOTE_AS2, NOTE_GS2, NOTE_GS2, 0,
  NOTE_AS2, NOTE_DS3, NOTE_AS2, NOTE_DS3, NOTE_AS2, NOTE_DS3, NOTE_AS2, NOTE_AS2, 0,
  NOTE_AS2, NOTE_DS3, NOTE_AS2, NOTE_DS3, NOTE_AS2, NOTE_A3,  NOTE_A3,  0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_AS1, 0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_GS1, NOTE_GS1, 0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_AS1, 0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_A2,  NOTE_A2,  0,
  NOTE_A3,  NOTE_B3,  NOTE_C4,  NOTE_B3,  NOTE_A3,  NOTE_B3,  NOTE_A3,  0,
  NOTE_A3,  NOTE_B3,  NOTE_C4,  NOTE_B3,  NOTE_A3,  NOTE_D4,  NOTE_D4,  0,
  NOTE_A4,  NOTE_B4,  NOTE_C5,  NOTE_B4,  NOTE_A4,  NOTE_B4,  NOTE_A4,  0,
  NOTE_A4,  NOTE_B4,  NOTE_C5,  NOTE_B4,  NOTE_A4,  NOTE_D5,  NOTE_D5,  0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_AS1, 0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_GS1, NOTE_GS1, 0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_AS1, 0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_A2,  NOTE_A2,  0,
  NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_F3,  NOTE_DS3, NOTE_CS3, NOTE_CS3, 0,
  NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_F3,  NOTE_DS3, NOTE_CS3, NOTE_DS3, 0,
  NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_F3,  NOTE_DS3, NOTE_CS3, NOTE_CS3, 0,
  NOTE_DS3, NOTE_CS3, NOTE_DS3, NOTE_F3,  NOTE_DS3, NOTE_A3,  NOTE_A3,  0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_AS1, 0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_GS1, NOTE_GS1, 0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_AS1, 0,
  NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_DS2, NOTE_AS1, NOTE_A2,  NOTE_A2,  0,
  NOTE_AS1, NOTE_DS2, NOTE_A2,  NOTE_AS2, NOTE_F2,  NOTE_AS1, NOTE_C3,  0,
  NOTE_AS1, NOTE_DS2, NOTE_B2,  NOTE_C3,  NOTE_AS2, NOTE_DS3, 0,
  NOTE_AS1, NOTE_DS2, NOTE_GS2, NOTE_AS2, NOTE_F2,  NOTE_AS1, 0,
  NOTE_G2,  NOTE_F2,  NOTE_DS2, NOTE_AS1, NOTE_AS1, 0,        NOTE_B0,  0,         NOTE_B0
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
