# Arduino Project: Blue Light

## Project Description

This Arduino project creates a Bluetooth Low Energy (BLE) controller for an LED. It allows you to turn the LED on and off remotely using a BLE-capable device. The project is designed to demonstrate the use of BLE communication in Arduino projects and how to control hardware wirelessly.

## Components Used

- Arduino UNO R4 Wifi

## How It Works

`setup()` **Function**

The `setup()` function is executed once when the Arduino is powered on or reset. In this function, the following actions take place:

1. **Serial Communication Initialization**: `Serial.begin(115200);` initializes serial communication for debugging purposes.
2. **LED Pin Configuration**: `pinMode(ledPin, OUTPUT);` sets the LED pin as an output.
3. **BLE Initialization**: The `BLE.begin()` method starts the Bluetooth Low Energy module. If BLE initialization fails, the program stops.
4. **BLE Configuration**: The device name is set using `BLE.setLocalName("LEDController");`, and the LED service and characteristic are added.
5. **Initial LED State**: The LED state is initialized to off (`LOW`), and this state is written to the BLE characteristic.
6. **BLE Advertising**: The device begins advertising its BLE services, making it discoverable by central devices.

`loop()` **Function**

The `loop()` function runs continuously after the `setup()` function completes. It performs the following tasks:

1. **BLE Central Connection Check**: The program checks if a central device (like a smartphone) is connected.
2. **Connection Handling**: If a new device connects, it updates the connection status and prints the device address.
3. **Characteristic Write Check**: The program checks if the LED characteristic has been modified by the connected central device. If so, it reads the new value and updates the LED state accordingly using `digitalWrite()`.
4. **State Update**: The current LED state is sent back to the central device, keeping it updated on the LED's status.
5. **Disconnection Handling**: If the central device disconnects, the program updates the connection status and prints a message to the serial monitor.

## Flutter Application

In addition to the Arduino setup, this project includes a Flutter application that serves as a user interface for controlling the LED. The app connects to the BLE LED controller, allowing users to toggle the LED state from their mobile devices.

### Flutter Application Features

- **Device Scanning**: The app automatically scans for the LED controller device when it starts. It looks for devices with the specified name and connects to the first one found.
- **State Monitoring**: The application listens for updates from the LED characteristic, reflecting the current state of the LED on the UI.
- **LED Control**: Users can toggle the LED state with a button in the app, which sends the new state to the Arduino device.
- **Connection Management**: The app provides options to reconnect to the device or disconnect, allowing users to manage the connection easily.

## Conclusion

This project serves as an introduction to Bluetooth Low Energy with Arduino. It demonstrates how to set up a BLE service and characteristic to control an LED wirelessly. You can extend this project by adding more features, such as adjusting brightness, changing colors with RGB LEDs, or incorporating sensors to respond to different inputs. This will deepen your understanding of both Arduino programming and wireless communication.