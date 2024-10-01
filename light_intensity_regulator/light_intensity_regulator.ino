// Define pins
const int potPin = A0;  // Pin for the potentiometer
const int ledPin = 11;  // Pin for the LED

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the potentiometer (0-1023)
  int potValue = analogRead(potPin);

  // Map the value from 0-1023 to 0-255 (for analogWrite)
  int ledBrightness = map(potValue, 0, 1023, 0, 255);

  // Write the mapped value to the LED pin to adjust brightness
  analogWrite(ledPin, ledBrightness);

  // Print the values for debugging (optional)
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" - LED Brightness: ");
  Serial.println(ledBrightness);

  // Add a small delay to stabilize the reading
  delay(100);
}
