# Lamp_Simple1Button
Animated Rainbow LED Lamp w/ WS2812b LED stripes, Arduino and 1 Button.

## Parts

* 1x Board: [WeMos D1 mini](https://wiki.wemos.cc/products:d1:d1_mini) with ESP8266 processor
* LED strip with 16 [WS2812b](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf) LEDs
* 1x mechanical push button
* 1x 10kOhm resistor as pull-up for the button
* Powered via MicroUSB (5V, 1A)
* 1x cardboard case
* 1x laminated paper as front screen


## Software

* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
* ESP8266 toolchain
  * Add in File -> Preferences -> Additional board manager URLs: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
  * Search in Tools -> Board -> Board Manager for "esp8266", then install
* Libraries
  * Sketch -> Include Library -> Manage Libraries -> Search for "Button" and "[FastLED](http://fastled.io/)", install them.


## Building more features

Potentially helpful libraries include:

* ESP8266WiFi (basic WiFi library for ESP8266, compatible with standard Arduino WiFi lib; included with board toolchain)
* WiFiManager (provides a captive portal to set up WiFi secrets; see Library Manager)
* ESPUI (provides a simple Web UI; see Library Manager)
