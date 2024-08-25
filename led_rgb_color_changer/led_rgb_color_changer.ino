#define BUTTON_PIN 7
#define RED_LED_PIN 11
#define GREEN_LED_PIN 10
#define BLUE_LED_PIN 9

// Variables to hold the current color values
int currentRed = 0;
int currentGreen = 0;
int currentBlue = 255;

// Variable for previous state of the button (not pressed)
bool lastButtonState = LOW;

// Variables for debounce handling
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 100; // Debounce delay in milliseconds

void setup() {
  // Set LED pins as outputs
  setupLEDs();

  // Set the button pin as input
  pinMode(BUTTON_PIN, INPUT);

  // Initialize the LED with a starting color (Blue)
  initializeLEDs();
}

void loop() {
  // Read the current state of the button
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Check if the button is pressed
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    // Implement debounce
    if (isDebounceTimeElapsed()) {
      lastDebounceTime = millis(); // Update the last debounce time

      // Generate and update new random colors
      updateLEDColors();
    }
  }

  lastButtonState = currentButtonState;  // Update the previous button state
}

// Function to set LED pins as outputs
void setupLEDs() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

// Function to initialize the LEDs with the starting color
void initializeLEDs() {
  analogWrite(RED_LED_PIN, currentRed);
  analogWrite(GREEN_LED_PIN, currentGreen);
  analogWrite(BLUE_LED_PIN, currentBlue);
}

// Function to check if debounce time has elapsed
bool isDebounceTimeElapsed() {
  return (millis() - lastDebounceTime) > debounceDelay;
}

// Function to generate random colors and update LEDs
void updateLEDColors() {
  int redValue = random(0, 256);
  int greenValue = random(0, 256);
  int blueValue = random(0, 256);

  // Update the LED colors only if the new values are different
  if (redValue != currentRed) {
    analogWrite(RED_LED_PIN, redValue);
    currentRed = redValue; // Store the new red value
  }
  if (greenValue != currentGreen) {
    analogWrite(GREEN_LED_PIN, greenValue);
    currentGreen = greenValue; // Store the new green value
  }
  if (blueValue != currentBlue) {
    analogWrite(BLUE_LED_PIN, blueValue);
    currentBlue = blueValue; // Store the new blue value
  }
}
