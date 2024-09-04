# Arduino Project: Thermo Display

## Project Description

In this Arduino project, a thermistor is used to measure the ambient temperature, which is then displayed on a seven-segment display. The thermistor is part of a voltage divider circuit, and the temperature is calculated using the Steinhart-Hart equation. This project demonstrates how to read analog inputs, perform calculations, and display the results using a seven-segment display.

## Components Used

- Arduino Uno
- 103 Thermistor (10kΩ NTC Thermistor)
- 10,000-ohm resistor (for the voltage divider)
- Seven-segment display (common anode)
- Breadboard
- Jumper wires

## Circuit Diagram

1. Connect the thermistor to the analog pin A0 and to the 5V power rail on the breadboard.
2. Connect a 10,000-ohm resistor between the analog pin A0 and the GND (ground) rail on the breadboard to form a voltage divider with the thermistor.
3. Connect the digit control pins of the seven-segment display to digital pins 2, 3, 4, and 5 on the Arduino.
4. Connect the segment control pins of the seven-segment display to digital pins 6, 7, 8, 9, 10, 11, 12, and 13 on the Arduino.
5. Ensure proper connections between the seven-segment display and the Arduino for stable operation.

### Seven-Segment Display Pin Layout

The seven-segment display used in this project has 12 pins arranged in two rows. The top row has 6 pins, and the bottom row has 6 pins. Below is the pin layout:

**Top Row:**
- Digit 1 (D1): Pin 2
- Segment A: Pin 6
- Segment F: Pin 11
- Digit 2 (D2): Pin 3
- Digit 3 (D3): Pin 4
- Segment B: Pin 7

**Bottom Row:**
- Segment E: Pin 10
- Segment D: Pin 9
- Decimal Point (DP): Pin 13
- Segment C: Pin 8
- Segment G: Pin 12
- Digit 4 (D4): Pin 5

## How It Works

`setup()` **Function**

The `setup()` function initializes the Arduino and the seven-segment display:

- `Serial.begin(9600);`: Initializes serial communication at a baud rate of 9600 for monitoring the temperature readings.
- `setupDisplay();`: Calls a function to configure the seven-segment display, including setting the brightness and defining the pins used for the digits and segments.

`loop()` **Function**

The `loop()` function continuously reads the temperature from the thermistor and updates the display:

1. A timer is used to update the display every 500 milliseconds, allowing for regular temperature readings without blocking the program execution.
2. `float temperature = readTemperature();`: Reads the current temperature in Celsius by calculating the resistance of the thermistor and applying the Steinhart-Hart equation.
3. `displayTemperature(temperature);`: Displays the temperature on the seven-segment display with two decimal places.
4. `sevseg.refreshDisplay();`: Ensures that the seven-segment display is refreshed continuously to show the latest temperature value.

`setupDisplay()` **Function**

This function configures the seven-segment display:

- Defines the number of digits and the pins connected to the display.
- Initializes the display with the appropriate settings, such as common anode configuration and brightness level.

`readTemperature()` **Function**

This function reads the analog value from the thermistor and calculates the temperature in Celsius:

- The thermistor's resistance is calculated using the voltage divider formula.
- The temperature in Kelvin is computed using the Steinhart-Hart equation, then converted to Celsius.
- The calculated temperature is returned for display and logging.

`displayTemperature(float temperature)` **Function**

This function handles the display of the temperature:

- The temperature is shown on the seven-segment display with two decimal points.
- The temperature is also logged to the serial monitor for monitoring.

## Conclusion

The Thermistor Temperature Display project showcases how to measure temperature with a thermistor and display the results on a seven-segment display. This project serves as a practical introduction to working with analog sensors, performing calculations, and outputting data in a user-friendly format. It can be expanded by incorporating additional sensors or different display methods to build more complex monitoring systems.