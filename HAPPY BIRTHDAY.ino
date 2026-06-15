#include "pitches.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define PAUSE 0

LiquidCrystal_I2C lcd(0x27,20,4);

int SPEAKER_PIN = 11;
int SPEAKER = SPEAKER_PIN;
#define NUM_OF_NOTES 28

int NOTE_SEQ[NUM_OF_NOTES] = {
      NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_F5, NOTE_E5, PAUSE,
      NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_F5, PAUSE,
      NOTE_C5, NOTE_C5, NOTE_C6, NOTE_A5, NOTE_F5, NOTE_E5, NOTE_D5, PAUSE,
      NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_F5 };

int NOTE_LEN[NUM_OF_NOTES] = {
      4,2,8,8,8,16,50,
      4,2,8,8,8,16,100,
      4,2,8,8,8,8,16,150,
      4,2,8,8,8,20 };

int TEMPO = 65;
unsigned long startTime;
bool messageShown = false;

void playNote(int pitch,int duration) {
    tone(SPEAKER, pitch);
    delay(duration);
    noTone(SPEAKER);
}

byte loveHeart[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, loveHeart);

  lcd.setCursor(0, 0);
  lcd.print(" Happy Birthday");
  lcd.setCursor(0, 1);
  lcd.print("[NAME]");
  lcd.write(0);

  startTime = millis();
}

void loop() {
   for (int i = 0; i < NUM_OF_NOTES; i++) {
        if (NOTE_SEQ[i] != PAUSE) {
            playNote(NOTE_SEQ[i], NOTE_LEN[i] * TEMPO);
            delay(TEMPO);
        } else {
            delay(NOTE_LEN[i]);
        }

        // Add custom birthday messages after 14 seconds
        if (!messageShown && millis() - startTime >= 14000) {

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("[MESSAGE 1]");
            lcd.setCursor(0, 1);
            lcd.print("[MESSAGE 2]");

            delay(4000);

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("[MESSAGE 3]");

            delay(4000);

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("[MESSAGE 4]");
            lcd.setCursor(0, 1);
            lcd.print("[MESSAGE 5]");

            delay(4000);

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("[MESSAGE 6]");
            lcd.setCursor(0, 1);
            lcd.print("[MESSAGE 7]");

            delay(4000);

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Thanks");
            lcd.setCursor(0, 1);
            lcd.print("from [NAME]");

            messageShown = true;
        }
   }
}
