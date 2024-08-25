# Arduino Project: LED RGB Color Changer

## Project Description

In this Arduino project, we create a fun and interactive circuit that controls an RGB LED's color using a push button. Each press of the button generates a new random color for the RGB LED, demonstrating the use of digital inputs and analog outputs to create dynamic light effects.

## Components Used

- Arduino Uno
- RGB LED
- Push Button
- 220-ohm resistors (for the LED)
- 10,000-ohm resistor (for the button)
- Breadboard
- Jumper wires

## Circuit Diagram

1. **RGB LED Connections:**
   - Connect the Red pin of the RGB LED to digital pin 11 on the Arduino through a 220-ohm resistor.
   - Connect the Green pin of the RGB LED to digital pin 10 on the Arduino through a 220-ohm resistor.
   - Connect the Blue pin of the RGB LED to digital pin 9 on the Arduino through a 220-ohm resistor.
   - Connect the common cathode of the RGB LED to GND (ground) on the Arduino.

2. **Push Button Connections:**
   - Connect one side of the push button to digital pin 7 on the Arduino.
   - Connect the other side of the push button to GND on the Arduino through a 10,000-ohm resistor.
   - Connect the same side of the push button (GND) to the 5V power rail on the breadboard.

![Circuit diagram](https://github.com/MBenincasa/arduino-learning-projects/blob/main/led_rgb_color_changer/led_rgb_color_changer_design.png)

## How It Works

`setup()` ***Function***

The `setup()` function initializes the Arduino and configures the pins:

- `setupLEDs();`: Configures the RGB LED pins (11, 10, and 9) as outputs.
- `pinMode(BUTTON_PIN, INPUT);`: Configures digital pin 7 as an input to read the button state.
- `initializeLEDs();`: Sets the initial color of the LED to blue.

`loop()` ***Function***

The `loop()` function continuously checks the state of the button and updates the LED color:

1. `bool currentButtonState = digitalRead(BUTTON_PIN);`: Reads the current state of the push button.
2. Checks if the button was pressed by comparing the current state to the previous state, while also implementing a debounce mechanism to avoid false triggers.
   - If the button press is detected (current state is HIGH and previous state was LOW) and debounce time has elapsed:
     - `updateLEDColors();`: Generates and applies a new random color to the RGB LED.
3. `lastButtonState = currentButtonState;`: Updates the previous button state for the next loop iteration.

### Helper Functions

- `setupLEDs()`: Configures the RGB LED pins as outputs.
- `initializeLEDs()`: Sets the initial color of the LED (blue) using `analogWrite()`.
- `isDebounceTimeElapsed()`: Checks if the debounce delay has elapsed since the last button press to ensure stable button state readings.
- `updateLEDColors()`: Generates random values for red, green, and blue components of the LED and updates the LED's color if the new values are different from the current ones.

## Conclusion

The RGB LED Color Changer project introduces a more advanced use of Arduino, combining random color generation with push button control. This project highlights concepts such as analog output, digital input, and debouncing, making it a great way to explore more sophisticated Arduino programming techniques. Feel free to experiment with different color effects or expand the project with additional features as you become more comfortable with Arduino.