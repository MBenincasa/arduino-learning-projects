#define LED_PIN 8
#define BUTTON_PIN 7

bool ledState = false;  // Initial state of the LED (off)
bool lastButtonState = LOW;  // Previous state of the button (not pressed)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(LED_PIN, ledState);  // Set the initial state of the LED
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Check if the button has just been pressed
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    ledState = !ledState;  // Toggle the LED state
    digitalWrite(LED_PIN, ledState);  // Update the LED state
  }

  lastButtonState = currentButtonState;  // Update the previous button state
}