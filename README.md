# Arduino Piano 🎹

A simple embedded-systems project that uses eight push buttons and a passive buzzer to play musical notes on an Arduino Uno.

## Engineering focus

- Read eight digital inputs with internal pull-up resistors.
- Map button states to predefined musical note frequencies.
- Generate buzzer tones using the Arduino `tone()` API.
- Organize hardware pin mappings and a separate header for note definitions.

## Hardware listed for this project

- Arduino Uno
- Eight push buttons
- Passive buzzer
- Breadboard and jumper wires

## Pin mapping

| Arduino pin | Connection |
| --- | --- |
| D12 | C4 button |
| D11 | D4 button |
| D10 | E4 button |
| D9 | F4 button |
| D7 | G4 button |
| D6 | A4 button |
| D5 | B4 button |
| D4 | C5 button |
| D8 | Passive buzzer |

The firmware uses `INPUT_PULLUP`; buttons should connect the corresponding input to **GND when pressed**, rather than driving the input from an external 5 V signal.

## Code

- [Arduino_Piano.ino](Arduino_Piano.ino) — input scanning and sound generation
- [pitches.h](pitches.h) — note frequency definitions
- [Schematic diagram](Schematic_diagram_piano.png) — wiring reference

## Run

1. Inspect the schematic and verify that your board and buzzer match the listed hardware.
2. Open `Arduino_Piano.ino` in the Arduino IDE.
3. Select the Arduino Uno and the correct serial port.
4. Upload the sketch and press the buttons to play individual notes.

## Relevance to robotics

This project introduces embedded input polling, I/O pin configuration, and actuator output. The next step is to use similar patterns for robot sensors, motors, and control loops.

**Status:** Source code and schematic included. No automated hardware test results are published here.
