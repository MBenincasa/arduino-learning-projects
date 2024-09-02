# Arduino Project: Photoresistor Light Trigger

## Project Description

In this Arduino project, we use a photoresistor to detect light levels and control an LED based on those levels. When the light intensity falls below a certain threshold, the LED turns on. If the light intensity is above the threshold, the LED turns off. This project demonstrates basic analog reading and digital output control with Arduino.

## Components Used

- Arduino Uno
- Photoresistor (Light Dependent Resistor, LDR)
- LED
- 220-ohm resistor (for the LED)
- 10,000-ohm resistor (for the photoresistor)
- Breadboard
- Jumper wires

## Circuit Diagram

1. Connect one terminal of the photoresistor to the analog pin A0 on the Arduino.
2. Connect the other terminal of the photoresistor to the 5V power rail on the breadboard.
3. Place a 10,000-ohm resistor between the analog pin A0 and the GND (ground) rail on the breadboard to form a voltage divider with the photoresistor.
4. Connect the anode (long leg) of the LED to digital pin 13 on the Arduino through a 220-ohm resistor.
5. Connect the cathode (short leg) of the LED to the GND (ground) rail on the breadboard.
6. Use the breadboard and jumper wires to establish stable connections.

![Circuit diagram](https://github.com/MBenincasa/arduino-learning-projects/blob/main/photoresistor_light_trigger/photoresistor_light_trigger_design.png)

## How It Works

`setup()` **Function**

The `setup()` function initializes the Arduino and sets up the necessary configurations:

- `Serial.begin(9600);`: Initializes serial communication at a baud rate of 9600 for monitoring the light level readings.
- `pinMode(LED_PIN, OUTPUT);`: Configures digital pin 13 as an output to control the LED.

`loop()` **Function**

The `loop()` function continuously reads the light level and controls the LED based on the reading:

1. `int value = analogRead(PHOTORESISTOR_PIN);`: Reads the analog value from the photoresistor, which ranges from 0 (low light) to 1023 (high light).
2. `Serial.println(value);`: Prints the light level value to the Serial Monitor for monitoring purposes.
3. The function compares the light level to a threshold value:
   - If the light level is below 400 (`if (value < 400)`), it indicates low light conditions, and the LED is turned on with `digitalWrite(LED_PIN, HIGH);`.
   - If the light level is 400 or higher, indicating sufficient light, the LED is turned off with `digitalWrite(LED_PIN, LOW);`.
4. `delay(200);`: Waits for 200 milliseconds before repeating the process, allowing for stable readings and control.

This setup allows the LED to act as an indicator of low light conditions detected by the photoresistor.

## Conclusion

The Photoresistor Light Trigger project illustrates how to use a photoresistor to control an LED based on light intensity. This simple yet effective setup provides insight into analog reading and digital control with Arduino. It serves as a foundation for more advanced projects involving light sensors and automated responses. You can enhance this project by adjusting the threshold value or adding more complex behavior based on light levels.