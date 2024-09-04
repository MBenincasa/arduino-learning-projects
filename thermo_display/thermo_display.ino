#include "SevSeg.h"

#define THERMISTOR_PIN A0 // Define the analog pin where the thermistor is connected

SevSeg sevseg; // Instantiate a seven-segment display controller object

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  setupDisplay();     // Setup the seven-segment display
}

void loop() {
  static unsigned long timer = millis(); // Initialize a timer for non-blocking delay

  // Update the display every 500 milliseconds
  if (millis() - timer >= 500) {
    timer += 500; // Reset the timer
    float temperature = readTemperature(); // Read the temperature in Celsius
    displayTemperature(temperature);       // Display the temperature on the seven-segment display
  }

  sevseg.refreshDisplay(); // Refresh the display to show the current value
}

// Setup the seven-segment display
void setupDisplay() {
  byte numDigits = 4; // Number of digits on the seven-segment display
  byte digitPins[] = {2, 3, 4, 5}; // Pins connected to the digits
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13}; // Pins connected to the segments

  bool resistorsOnSegments = false; // Set to true if resistors are connected to segments instead of digits
  byte hardwareConfig = COMMON_ANODE; // Type of seven-segment display: COMMON_ANODE or COMMON_CATHODE
  bool updateWithDelays = false; // Set to true if you want the display to update with delays (not recommended)
  bool leadingZeros = false; // Set to true if you want leading zeros to be displayed
  bool disableDecPoint = false; // Set to true if you want to disable the decimal point

  // Initialize the seven-segment display with the above settings
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90); // Set the brightness of the display (0-100)
}

// Read the temperature from the thermistor in Celsius
float readTemperature() {
  float R1 = 10000; // Known resistor value in the voltage divider (10kΩ)
  float logR2, R2, T, Tc; // Variables for calculations
  // Coefficients for the Steinhart-Hart equation for a 10k thermistor
  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

  int Vo = analogRead(THERMISTOR_PIN); // Read the analog value from the thermistor
  R2 = R1 * (1023.0 / (float)Vo - 1.0); // Calculate the resistance of the thermistor
  logR2 = log(R2); // Calculate the logarithm of the thermistor resistance
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)); // Calculate the temperature in Kelvin using the Steinhart-Hart equation
  Tc = T - 273.15; // Convert the temperature from Kelvin to Celsius

  return Tc; // Return the temperature in Celsius
}

// Display the temperature on the seven-segment display
void displayTemperature(float temperature) {
  Serial.println(temperature);
  sevseg.setNumberF(temperature, 2); // Display the temperature with 2 decimal places
}
