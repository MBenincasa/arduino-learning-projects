# Arduino Project: Blinking Red LED

## Project Description

This Arduino project is a simple circuit that makes a red LED blink at one-second intervals.

## Components Used

- Arduino Uno
- Red LED
- Breadboard
- 220-ohm resistor
- Jumper wires

## Circuit Diagram

1. Connect the long leg of the LED (anode) to digital pin 8 on the Arduino through the 220-ohm resistor.
2. Connect the short leg of the LED (cathode) to GND (ground) on the Arduino.
3. Ensure stable connections using the breadboard and jumper wires.

![Circuit diagram](https://github.com/MBenincasa/arduino-learning-projects/blob/main/blinking_red_led/blinking_red_led_design.png)

## How It Works
`setup()` ***Function***

The setup() function runs once when the Arduino is powered on. In this function, digital pin 8 is configured as an output using the pinMode(8, OUTPUT); command.

`loop()` ***Function***

The loop() function contains the code that runs repeatedly. In this case, the LED is turned on and off at one-second intervals.

1. `digitalWrite(8, HIGH);`: Sets pin 8 to HIGH, turning on the LED.
2. `delay(1000);`: Waits for 1000 milliseconds (1 second).
3. `digitalWrite(8, LOW);`: Sets pin 8 to LOW, turning off the LED.
4. `delay(1000);`: Waits for 1000 milliseconds (1 second).

This cycle continues indefinitely, making the LED blink at one-second intervals.

## Conclusion

This project is a great starting point for anyone looking to learn how to use an Arduino and create simple circuits. You can expand this project by adding more components and functionalities as you become more familiar with programming and electronics.
