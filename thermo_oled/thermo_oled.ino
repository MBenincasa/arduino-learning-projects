#include <U8g2lib.h>
#include <Wire.h>
#include <DHT.h>

// OLED SH1106 via software I2C
U8G2_SH1106_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, A5, A4, U8X8_PIN_NONE);

// DHT22 sensor configuration
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  initDisplay();
  dht.begin();
  showStartupMessage();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  updateDisplay(temp, hum);
  delay(1000);
}

// Store last known values
float lastTemp = -1000;
float lastHum = -1000;

// Initialize OLED display
void initDisplay() {
  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB08_tr);
}

// Show startup message
void showStartupMessage() {
  u8g2.clearBuffer();
  u8g2.drawStr(0, 12, "Starting sensors...");
  u8g2.sendBuffer();
  delay(2000);
}

// Update display only if values changed
void updateDisplay(float temperature, float humidity) {
  if (!isnan(temperature) && !isnan(humidity) &&
      (temperature != lastTemp || humidity != lastHum)) {

    lastTemp = temperature;
    lastHum = humidity;

    char tempStr[20], humStr[20];
    snprintf(tempStr, sizeof(tempStr), "T: %.1f C", temperature);
    snprintf(humStr, sizeof(humStr), "H: %.1f %%", humidity);

    u8g2.clearBuffer();
    u8g2.drawStr(0, 12, "DHT22 - SH1106");
    u8g2.drawStr(0, 30, tempStr);
    u8g2.drawStr(0, 48, humStr);
    u8g2.sendBuffer();
  }
}