// Include the library containing musical note frequencies
#include "pitches.h"

// Speaker/Buzzer is connected to Arduino Pin 8
#define BUZZER_PIN 8

// Push button pin connections
const uint8_t pianoButtonPins[] = {12, 11, 10, 9, 7, 6, 5, 4};

// Musical notes assigned to each button
const int pianoNotes[] = {
  NOTE_C4,  // Button 1
  NOTE_D4,  // Button 2
  NOTE_E4,  // Button 3
  NOTE_F4,  // Button 4
  NOTE_G4,  // Button 5
  NOTE_A4,  // Button 6
  NOTE_B4,  // Button 7
  NOTE_C5   // Button 8
};

// Total number of buttons
const int totalButtons = sizeof(pianoButtonPins) / sizeof(pianoButtonPins[0]);

void setup() {

  // Configure all button pins as INPUT_PULLUP
  // (Button is pressed when the pin reads LOW)
  for (uint8_t buttonIndex = 0; buttonIndex < totalButtons; buttonIndex++) {
    pinMode(pianoButtonPins[buttonIndex], INPUT_PULLUP);
  }

  // Configure buzzer pin as OUTPUT
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {

  // Variable to store the note that should be played
  int currentNote = 0;

  // Check every button
  for (uint8_t buttonIndex = 0; buttonIndex < totalButtons; buttonIndex++) {

    // If a button is pressed
    if (digitalRead(pianoButtonPins[buttonIndex]) == LOW) {

      // Select the corresponding musical note
      currentNote = pianoNotes[buttonIndex];
    }
  }

  // Play the selected note if any button is pressed
  if (currentNote > 0) {
    tone(BUZZER_PIN, currentNote);
  }
  // Otherwise stop playing any sound
  else {
    noTone(BUZZER_PIN);
  }
}
