# Arduino Learning Projects

Welcome to the Arduino Learning Projects repository! This collection is dedicated to showcasing my journey as I learn and experiment with Arduino.

## Projects List

1. **Blinking red LED**
    - **Description:** In this project, you'll learn how to make a red LED blink at regular intervals. This is a great starting point for anyone new to Arduino.
    - **Skills Learned:** Use of `digitalWrite()` and `delay()`, basic understanding of circuits.
2. **Red LED toggle**
    - **Description:** This project extends the previous one to allow toggling the red LED on and off with a button press. It's useful for learning how to handle digital inputs and outputs.
    - **Skills Learned:** Handling inputs and outputs, use of `digitalRead()` and `digitalWrite()`.
3. **LED RGB Color Changer**
    - **Description:** This project uses an RGB LED to change colors based on red, green, and blue values. It’s a great exercise to understand color mixing and analog signal control.
    - **Skills Learned:** Use of PWM pins and `analogWrite()`.
4. **Simple Melody Player**
    - **Description:** In this project, you’ll build a simple melody player using a piezo buzzer. You’ll learn how to generate sounds and melodies with Arduino.
    - **Skills Learned:** Using the `tone()` function to produce sounds, understanding note frequencies and durations.
5. **Photoresistor Light Trigger**
    - **Description:** This project involves using a photoresistor to detect light levels and control an LED based on those levels. When the light intensity falls below a specific threshold, the LED turns on, and it turns off when the light intensity is above the threshold. This project demonstrates how to read analog values and control a digital output based on those readings.
    - **Skills Learned:** Reading analog sensor values using `analogRead()`.
6. **Thermo Display**
    - **Description:** This project uses a thermistor to measure the ambient temperature and displays it on a seven-segment display. It involves creating a voltage divider circuit with the thermistor, calculating temperature using the Steinhart-Hart equation, and showing the temperature with a seven-segment display.
    - **Skills Learned:** Temperature calculation, working with seven-segment displays, and updating displays with `SevSeg` library.
7. **IncliAlert**
    - **Description:** This project uses a tilt switch to activate an LED and a buzzer. When the tilt switch is tilted, the LED lights up, and the buzzer sounds, demonstrating basic digital input and output control.
    - **Skills Learned:** Understanding how a tilt switch works.
8. **Light Intensity Regulator**
    - **Description:** This project uses a potentiometer to control the brightness of an LED. As the potentiometer is adjusted, the LED’s brightness changes, showing how to read analog input values and use PWM output to create a dimming effect.
    - **Skills Learned:** Understanding how a potentiometer works.

## Getting Started

1. **Install the Arduino IDE:** Download and install the Arduino IDE from the official [Arduino Software](https://www.arduino.cc/en/software) page.
2. **Connect the Arduino Board:** Follow the instructions to connect the Arduino to your computer via USB.
3. **Upload Sketches:** Open the `.ino` files related to the projects and upload them to your Arduino board using the IDE.

## Useful Resources

- **Arduino Documentation:** [Official Documentation](https://www.arduino.cc/en/Reference/HomePage)
- **Arduino Forum:** [Support Forum](https://forum.arduino.cc/)
- **Tutorials and Guides:** [Arduino Guide](https://www.arduino.cc/en/Tutorial/HomePage)