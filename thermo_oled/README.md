# Arduino Project: ThermoOLED – Temperature & Humidity Display

## Project Description

**ThermoOLED** is an Arduino-based project that reads temperature and humidity data using a **DHT22 sensor** and displays the information on a **1.3-inch OLED screen** (SH1106, 128×64 pixels) via I2C communication.

This project is perfect for learning how to interface sensors and displays with Arduino, while organizing code into modular functions for better readability and scalability.

---

## Components Used

- Arduino Uno  
- DHT22 Temperature & Humidity Sensor  
- 1.3" OLED Display (SH1106, I2C, 128×64)  
- Breadboard  
- Jumper wires  

---

## Circuit Diagram

### OLED Display (SH1106 I2C):

| OLED Pin | Arduino Pin |
|----------|-------------|
| VCC      | 5V          |
| GND      | GND         |
| SCK      | A5          |
| SDA      | A4          |

### DHT22 Sensor:

| DHT22 Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 5V          |
| GND       | GND         |
| DATA      | D2          |

> **Note:** A 10k pull-up resistor between DATA and VCC is recommended for better signal stability.

---

## How It Works

### `setup()` Function  
Initializes the OLED display and the DHT22 sensor. A startup message (“Starting sensors...”) is briefly shown during boot.

### `loop()` Function  
Reads the current temperature and humidity once every second. If the values have changed since the last reading, the OLED is updated accordingly to reflect the new data.

### Functional Highlights

- `initDisplay()`: Initializes the SH1106 OLED and sets the font.  
- `showStartupMessage()`: Displays a brief boot message.  
- `updateDisplay(t, h)`: Clears the screen and writes temperature and humidity only if values have changed.

---

## Conclusion

**ThermoOLED** is a compact and modular project that introduces the fundamentals of sensor data acquisition and display output using Arduino.