#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// DS18B20 data pin
#define ONE_WIRE_BUS 28

// I2C Pins definition
#define I2C_SDA 8  // Change to your desired SDA pin
#define I2C_SCL 9  // Change to your desired SCL pin

// Initialize objects
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  
  // Initialize I2C with custom pins
  Wire.setSDA(I2C_SDA);
  Wire.setSCL(I2C_SCL);
  Wire.begin();
  
  // Rest of your setup code...
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  // Initialize temperature sensor
  sensors.begin();
  
  // Initial display settings
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.display();
  
  // Check if sensor is connected
  if(sensors.getDeviceCount() == 0) {
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("No temp sensors!");
    display.display();
    delay(2000);
  }
}

void loop() {
  display.clearDisplay();
  
  // Request temperature reading
  sensors.requestTemperatures();
  
  // Get temperature in Celsius
  float tempC = sensors.getTempCByIndex(0);
  
  // Check if reading was successful
  if(tempC == DEVICE_DISCONNECTED_C) {
    display.setCursor(0,0);
    display.println("Sensor error!");
    display.display();
    return;
  }
  
  // Display temperature
  display.setCursor(0,0);
  display.println("Temperature:");
  
  display.setCursor(0,20);
  display.print(tempC, 1);  // One decimal place
  display.print(" C");
  
  
  display.display();
}