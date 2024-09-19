// Pin definitions
const int tiltSwitchPin = 2;  // Pin connected to the tilt switch
const int ledPin = 13;        // Pin connected to the LED
const int buzzerPin = 8;      // Pin connected to the buzzer

void setup() {
  pinMode(tiltSwitchPin, INPUT);  // Configure the pin with an external pull-down resistor
  pinMode(ledPin, OUTPUT);        // Configure the LED pin as output
  pinMode(buzzerPin, OUTPUT);     // Configure the buzzer pin as output
  
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  // Read the state of the tilt switch
  int tiltState = digitalRead(tiltSwitchPin);

  if (tiltState == LOW) {  // If LOW, the sensor is tilted
    // Turn on LED and buzzer because it is tilted
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Tilt detected!");  // Detection message
  } else {
    // If the tilt switch is not active (not tilted), turn off LED and buzzer
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("No tilt detected.");  // Message for monitoring
  }

  delay(100);  // Small pause for stability
}