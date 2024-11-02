import 'package:flutter/material.dart';
import 'package:flutter_blue_plus/flutter_blue_plus.dart';

void main() => runApp(MyApp());

// Main app widget that initializes the Bluetooth LED Controller
class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Bluetooth LED Controller',
      theme: ThemeData(primarySwatch: Colors.blue),
      home: BluetoothLedController(),
    );
  }
}

// Stateful widget for managing Bluetooth LED Controller functionalities
class BluetoothLedController extends StatefulWidget {
  @override
  _BluetoothLedControllerState createState() => _BluetoothLedControllerState();
}

class _BluetoothLedControllerState extends State<BluetoothLedController> {
  // Bluetooth device and characteristic objects
  BluetoothDevice? ledDevice;
  BluetoothCharacteristic? ledCharacteristic;
  bool ledState = false;  // Stores the LED state (on/off)
  bool isScanning = false;  // Flag to indicate if scanning is in progress

  // BLE UUIDs and device name
  final String serviceUUID = "38f2bcc1-ac2f-4db3-9cce-0ac61b88580e";
  final String characteristicUUID = "ff21fa2b-1253-4def-bb3b-047e786d149c";
  final String deviceName = "LEDController";

  @override
  void initState() {
    super.initState();
    scanForDevice();  // Begin scanning for the device as soon as the app starts
  }

  // Function to start scanning for the Bluetooth device
  void scanForDevice() {
    setState(() {
      isScanning = true;  // Indicate that scanning is in progress
    });

    // Start scanning for devices with a specified name and a timeout
    FlutterBluePlus.startScan(
      withNames: [deviceName],
      timeout: Duration(seconds: 4),
    );

    // Listen for scan results
    FlutterBluePlus.scanResults.listen((results) async {
      for (ScanResult result in results) {
        // Check if the found device matches the target device name
        if (result.device.name == deviceName) {
          FlutterBluePlus.stopScan();  // Stop scanning
          setState(() {
            ledDevice = result.device;
            isScanning = false;
          });
          await connectToDevice();  // Connect to the found device
          break;
        }
      }
    });
  }

  // Function to connect to the Bluetooth device
  Future<void> connectToDevice() async {
    if (ledDevice != null) {
      try {
        await ledDevice!.connect();  // Attempt to connect to the device
        await discoverServices();  // Discover services after connecting
      } catch (e) {
        print("Error connecting to device: $e");
      }
    }
  }

  // Function to discover services and characteristics on the device
  Future<void> discoverServices() async {
    if (ledDevice == null) return;

    try {
      List<BluetoothService> services = await ledDevice!.discoverServices();
      for (BluetoothService service in services) {
        // Find the service that matches the specified UUID
        if (service.uuid.toString() == serviceUUID) {
          // Find the characteristic that matches the specified UUID
          ledCharacteristic = service.characteristics.firstWhere(
            (characteristic) => characteristic.uuid.toString() == characteristicUUID,
          );
          monitorCharacteristic();  // Set up notifications for the characteristic
          break;
        }
      }
      setState(() {});  // Refresh the UI to reflect the discovered characteristic
    } catch (e) {
      print("Error discovering services: $e");
    }
  }

  // Function to enable notifications on the characteristic and listen for updates
  void monitorCharacteristic() {
    if (ledCharacteristic == null) return;

    ledCharacteristic!.setNotifyValue(true);
    ledCharacteristic!.value.listen((value) {
      if (value.isNotEmpty) {
        setState(() {
          ledState = value[0] == 1;  // Update ledState based on characteristic value
        });
      }
    });
  }

  // Function to toggle the LED state by writing to the characteristic
  void toggleLedState() async {
    if (ledCharacteristic != null) {
      ledState = !ledState;  // Toggle the LED state
      final value = [ledState ? 1 : 0];
      try {
        await ledCharacteristic!.write(value, withoutResponse: false);  // Write new state
        print("LED state changed to: ${ledState ? 'On' : 'Off'}");
      } catch (e) {
        print("Error writing to characteristic: $e");
      }
      setState(() {});  // Refresh UI with new LED state
    } else {
      print("LED characteristic not available");
    }
  }

  // Function to disconnect from the Bluetooth device
  void disconnectDevice() {
    if (ledDevice != null) {
      ledDevice!.disconnect();  // Disconnect from the device
    }
    setState(() {
      ledDevice = null;
      ledCharacteristic = null;
      ledState = false;  // Reset LED state
    });
  }

  // Build the UI for the Bluetooth LED Controller
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Bluetooth LED Controller"),
        actions: [
          IconButton(
            icon: Icon(Icons.refresh),
            onPressed: scanForDevice,  // Reconnect to the device
            tooltip: "Reconnect",
          ),
          IconButton(
            icon: Icon(Icons.stop),
            onPressed: disconnectDevice,  // Disconnect from the device
            tooltip: "Disconnect",
          ),
        ],
      ),
      body: Center(
        child: isScanning
            ? CircularProgressIndicator()  // Show a loading indicator while scanning
            : ledDevice == null
                ? Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Text(
                        "Searching for device...",
                        style: TextStyle(fontSize: 18),
                      ),
                      SizedBox(height: 20),
                      ElevatedButton(
                        onPressed: scanForDevice,
                        child: Text("Retry Connection"),  // Retry scanning
                      ),
                    ],
                  )
                : Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Text(
                        "LED Status: ${ledState ? "On" : "Off"}",  // Display current LED state
                        style: TextStyle(fontSize: 24),
                      ),
                      SizedBox(height: 20),
                      ElevatedButton(
                        onPressed: toggleLedState,
                        child: Text(ledState ? "Turn Off LED" : "Turn On LED"),  // Toggle LED state
                      ),
                      SizedBox(height: 20),
                      ElevatedButton(
                        onPressed: disconnectDevice,
                        child: Text("Disconnect"),  // Disconnect from the device
                        style: ElevatedButton.styleFrom(
                          backgroundColor: Colors.redAccent,
                        ),
                      ),
                    ],
                  ),
      ),
    );
  }

  @override
  void dispose() {
    disconnectDevice();  // Ensure disconnection on widget disposal
    super.dispose();
  }
}
