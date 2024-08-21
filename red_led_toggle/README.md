# Arduino Project: Red LED Toggle

## Project Description

In this Arduino project, we create a practical and engaging circuit that allows you to control a red LED with a push button. Pressing the button toggles the LED on and off, simulating a simple switch mechanism.


## Components Used

- Arduino Uno
- Red LED
- Push Button
- 220-ohm resistor (for the LED)
- 10,000-ohm resistor (for the button)
- Breadboard
- Jumper wires

## Circuit Diagram

1. Connect the long leg of the LED (anode) to digital pin 8 on the Arduino through the 220-ohm resistor.
2. Connect the short leg of the LED (cathode) to GND (ground) on the Arduino.
3. Connect one side of the push button to digital pin 7 on the Arduino.
4. Connect the other side of the push button to GND on the Arduino through a 10,000-ohm resistor.
5. Connect the same side of the push button (connected to pin 7) to the 5V power rail on the breadboard.
6. Use the breadboard and jumper wires to establish stable connections.

![Circuit diagram](https://github.com/MBenincasa/arduino-learning-projects/blob/main/red_led_toggle/red_led_toggle.png)

## How It Works

### `setup()` ***Function***

The `setup()` function initializes the Arduino and configures the pins:

- `pinMode(LED_PIN, OUTPUT);`: Configures digital pin 8 as an output to control the LED.
- `pinMode(BUTTON_PIN, INPUT);`: Configures digital pin 7 as an input to read the button state.
- `digitalWrite(LED_PIN, ledState);`: Sets the initial state of the LED to off.

### `loop()` ***Function***

The `loop()` function repeatedly checks the button state and updates the LED:

1. `bool currentButtonState = digitalRead(BUTTON_PIN);`: Reads the current state of the push button.
2. The function checks if the button was pressed by comparing the current state to the previous state.
3. If a button press is detected (current state is HIGH and previous state was LOW):
   - `ledState = !ledState;`: Toggles the LED state.
   - `digitalWrite(LED_PIN, ledState);`: Applies the new LED state.
4. `lastButtonState = currentButtonState;`: Updates the previous button state for the next iteration.

This process allows the LED to be toggled on and off with each button press, mimicking a switch.

## Conclusion

The Red LED Toggle project demonstrates a fundamental technique for controlling an LED with a push button. This simple circuit is a great starting point for learning about digital inputs and outputs in Arduino. You can expand this project by adding more components or functionalities as you continue your exploration with Arduino.