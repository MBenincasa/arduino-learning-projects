# Arduino Project: Simple Melody Player

## Project Description

This Arduino project plays a melody using a buzzer. The melody is defined as an array of notes and durations, which the code reads and plays sequentially. The project includes adjustments for dotted notes and rests.

## Components Used

- Arduino Uno
- Buzzer
- Breadboard
- Jumper wires

## Circuit Diagram

1. Connect the positive leg of the buzzer to digital pin 9 on the Arduino.
2. Connect the negative leg of the buzzer to GND (ground) on the Arduino.
3. Use the breadboard and jumper wires to establish stable connections.

![Circuit diagram](https://github.com/MBenincasa/arduino-learning-projects/blob/main/simple_melody_player/simple_melody_player_design.png)

## How It Works

`setup()` ***Function***

The `setup()` function initializes the Arduino:

- `pinMode(buzzer, OUTPUT);`: Configures digital pin 9 as an output to control the buzzer.

`loop()` ***Function***

The `loop()` function repeatedly plays the melody:

1. Iterates through the `melody` array, extracting each note and its duration.
2. Calculates the duration for each note.
3. Plays the note using the `tone()` function if it is not a REST.
4. Pauses for the note duration or REST.
5. Waits 5 seconds before repeating the melody.

This allows the buzzer to play the defined melody in a loop, creating a continuous audio output.

## Conclusion

The Simple Melody Player project demonstrates how to control a buzzer to play a sequence of notes using Arduino. It introduces concepts such as note duration and handling rests, providing a foundation for more complex audio projects. You can expand this project by modifying the melody or adding additional functionalities.