#define PHOTORESISTOR_PIN A0  // Define the analog pin connected to the photoresistor
#define LED_PIN 13            // Define the digital pin connected to the LED

void setup() {
  Serial.begin(9600);        // Initialize serial communication at 9600 baud rate
  pinMode(LED_PIN, OUTPUT);  // Set the LED pin as an output
}

void loop() {
  int value = analogRead(PHOTORESISTOR_PIN); // Read the value from the photoresistor
  Serial.println(value);                     // Print the value to the Serial Monitor

  if (value < 400) {                         // If the value is less than 400
    digitalWrite(LED_PIN, HIGH);             // Turn on the LED
  } else {
    digitalWrite(LED_PIN, LOW);              // Otherwise, turn off the LED
  }

  delay(200);                                // Wait for 200 milliseconds before the next loop iteration
}