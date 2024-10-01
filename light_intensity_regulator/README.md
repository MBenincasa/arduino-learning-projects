# Arduino Project: Light Intensity Regulator

## Project Description

In this Arduino project, we create a simple but effective light intensity regulator using a potentiometer to control the brightness of an LED. The project demonstrates how to use analog inputs and PWM (Pulse Width Modulation) outputs on an Arduino to create smooth brightness control. By turning the potentiometer, the LED's brightness increases or decreases, offering a practical example of analog-to-digital conversion and variable output.

## Components Used

- Arduino Uno
- Potentiometer (10k ohms)
- LED (any color)
- 220-ohm resistor (for the LED)
- Breadboard
- Jumper wires

## Circuit Diagram

1. **Potentiometer Connections:**
   - Connect the middle pin of the potentiometer to the analog pin A0 on the Arduino.
   - Connect one side of the potentiometer to 5V on the Arduino.
   - Connect the other side of the potentiometer to GND on the Arduino.

2. **LED Connections:**
   - Connect the anode (long leg) of the LED to digital pin 11 on the Arduino through a 220-ohm resistor.
   - Connect the cathode (short leg) of the LED to GND (ground) on the Arduino.

![Circuit diagram](https://github.com/MBenincasa/arduino-learning-projects/blob/main/light_intensity_regulator/light_intensity_regulator_design.png)

## How It Works

`setup()` **Function**

The `setup()` function initializes the Arduino:

- `Serial.begin(9600);`: Sets up serial communication for debugging purposes.

`loop()` **Function**

The `loop()` function reads the potentiometer value and adjusts the LED brightness accordingly:

1. `int potValue = analogRead(potPin);`: Reads the analog value from the potentiometer, which returns a value between 0 and 1023.
2. `int ledBrightness = map(potValue, 0, 1023, 0, 255);`: Maps the potentiometer value to a range suitable for PWM output (0-255).
3. `analogWrite(ledPin, ledBrightness);`: Sets the brightness of the LED based on the mapped potentiometer value.
4. A small delay (`delay(100);`) ensures stable readings by avoiding too frequent updates.

## Conclusion

The **Light Intensity Regulator** project is a great starting point for learning how to interface analog sensors with an Arduino and control output devices using PWM. It introduces important concepts such as analog-to-digital conversion, variable PWM output, and the use of a potentiometer to interact with the Arduino. This project is easily expandable: you could add multiple LEDs, create fading effects, or even control other components such as motors. Experiment with these ideas to further develop your skills with Arduino!