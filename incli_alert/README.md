# Arduino Project: IncliAlert

## Project Description

In this Arduino project, titled **IncliAlert**, we create a simple yet effective circuit that uses a tilt switch to activate an LED and a buzzer. When the tilt switch is tilted, the LED lights up, and the buzzer sounds, demonstrating basic digital input and output control.

## Components Used

- Arduino Uno
- Tilt Switch (SW-520D)
- LED
- Buzzer
- 220-ohm resistor (for the LED)
- 10,000-ohm resistor (for the tilt switch)
- Breadboard
- Jumper wires

## Circuit Diagram

1. **Tilt Switch Connections:**
   - Connect one terminal of the tilt switch to **5V**.
   - Connect the other terminal of the tilt switch to digital pin **2** on the Arduino through a **10,000-ohm resistor** to **GND**.

2. **LED Connections:**
   - Connect the anode (longer pin) of the LED to digital pin **13** on the Arduino through a **220-ohm resistor**.
   - Connect the cathode (shorter pin) of the LED to **GND**.

3. **Buzzer Connections:**
   - Connect the positive terminal of the buzzer to digital pin **8** on the Arduino.
   - Connect the negative terminal of the buzzer to **GND**.

![Circuit diagram](https://github.com/MBenincasa/arduino-learning-projects/blob/main/incli_alert/incli_alert_design.png)

## How It Works

`setup()` **Function**

The `setup()` function initializes the Arduino and configures the pins:

- `pinMode(tiltSwitchPin, INPUT);`: Configures digital pin 2 as an input to read the state of the tilt switch.
- `pinMode(ledPin, OUTPUT);`: Configures digital pin 13 as an output for the LED.
- `pinMode(buzzerPin, OUTPUT);`: Configures digital pin 8 as an output for the buzzer.
- `Serial.begin(9600);`: Initializes serial communication for debugging purposes.

`loop()` **Function**

The `loop()` function continuously checks the state of the tilt switch and updates the LED and buzzer accordingly:

1. `int tiltState = digitalRead(tiltSwitchPin);`: Reads the current state of the tilt switch.
2. If the tilt switch is tilted (state is **LOW**):
   - `digitalWrite(ledPin, HIGH);`: Turns on the LED.
   - `digitalWrite(buzzerPin, HIGH);`: Activates the buzzer.
   - `Serial.println("Tilt detected!");`: Sends a message to the serial monitor for debugging.
3. If the tilt switch is not tilted (state is **HIGH**):
   - `digitalWrite(ledPin, LOW);`: Turns off the LED.
   - `digitalWrite(buzzerPin, LOW);`: Deactivates the buzzer.
   - `Serial.println("No tilt detected.");`: Sends a message to the serial monitor.

## Conclusion

The IncliAlert project demonstrates the basic functionality of digital input and output using an Arduino. It provides a practical application for a tilt switch, allowing you to control an LED and buzzer based on tilt detection. Feel free to modify the code and experiment with additional features or components to enhance your project!