# pico-temp-read
Raspberry Pico W reads the data from a temperature sensor and displays the information on a display

# 📦Usage
DS18B20    ->  Pico W

VDD (Red)  ->  3.3V 

GND (Black)->  GND

Data (Yellow)-> GPIO 28 

4.7kΩ resistor between VDD and Data


OLED       ->  Pico

VCC        ->  3.3V

GND        ->  GND

SDA        ->  GPIO 8

SCL        ->  GPIO 9


Install the following packages via the Arduino IDE
- "OneWire" by Paul Stoffregen
- "DallasTemperature" by Miles Burton
- "Adafruit SSD1306" by Adafruit
- "Adafruit GFX Library" by Adafruit

Refer to this guide to push the code on the Raspberry:
https://randomnerdtutorials.com/programming-raspberry-pi-pico-w-arduino-ide/
