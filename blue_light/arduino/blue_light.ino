#include <ArduinoBLE.h>

// UUIDs for the LED service and characteristic
const char* ledServiceUUID = "38f2bcc1-ac2f-4db3-9cce-0ac61b88580e";
const char* ledCharacteristicUUID = "ff21fa2b-1253-4def-bb3b-047e786d149c";

// Create a BLE service and characteristic for controlling the LED
BLEService ledService(ledServiceUUID);
BLEBoolCharacteristic ledCharacteristic(ledCharacteristicUUID, BLERead | BLEWrite);

// Define the LED pin (usually the built-in LED)
const int ledPin = LED_BUILTIN;

// Variables to store the LED state and connection status
bool ledState = false;
bool connected = false;

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud rate
  
  pinMode(ledPin, OUTPUT);  // Set LED pin as an output
  digitalWrite(ledPin, LOW);  // Ensure LED is off initially
  
  // Initialize BLE and check if it started successfully
  if (!BLE.begin()) {
    Serial.println("Bluetooth not available");
    while (1);  // Stop if BLE failed to initialize
  }
  
  // Set BLE device name and add service and characteristic
  BLE.setLocalName("LEDController");
  BLE.setAdvertisedService(ledService);
  ledService.addCharacteristic(ledCharacteristic);
  BLE.addService(ledService);

  // Set initial LED state as off in the BLE characteristic
  ledCharacteristic.writeValue(ledState);

  // Start advertising the BLE service
  BLE.advertise();
  Serial.println("Waiting for Bluetooth connections...");
}

void loop() {
  // Check if a central device has connected
  BLEDevice central = BLE.central();

  if (central) {
    // When a new central device connects
    if (!connected) {
      Serial.print("Connected to: ");
      Serial.println(central.address());
      connected = true;
    }
    
    // Check if the LED characteristic has been written to by the central device
    if (ledCharacteristic.written()) {
      ledState = ledCharacteristic.value();  // Get the new value (on or off)
      digitalWrite(ledPin, ledState ? HIGH : LOW);  // Set LED accordingly
      Serial.print("LED state: ");
      Serial.println(ledState ? "On" : "Off");
    }

    // Update the characteristic with the current LED state for the central device
    ledCharacteristic.writeValue(ledState);
  } else if (connected) {
    // If no central is connected and we were previously connected
    Serial.println("Disconnected from central");
    connected = false;
  }
}
