# Lamp_Simple1Button

Animated Rainbow LED Lamp w/ WS2812b LED stripes, Arduino and 1 Button.

![Rainbow Lamp](img/Rainbow_lamp.jpg)

![Rainbow Lamp video](img/lamp_action.mp4)

## Parts

* 1x Board: [WeMos D1 mini](https://wiki.wemos.cc/products:d1:d1_mini) with ESP8266 processor
* LED strip with 16 [WS2812b](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf) LEDs
* 1x mechanical push button (long button pin: bottom-to-top=1.5cm)
* 1x 10kOhm resistor as pull-up for the button
* Powered via MicroUSB (5V, 1A)
* 1x cardboard case (half-circle, radius=8.5cm, inner thickness=1.5cm)
* 1x laminated paper as front screen (80g, half-circle, as big as your laminating pouch allows)


## Software

* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
* ESP8266 toolchain
  * Add in File -> Preferences -> Additional board manager URLs: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
  * Search in Tools -> Board -> Board Manager for "esp8266", then install version 2.4.1 (if you want the newest version, you need to heed the FastLED notes below)
    * Select "WeMos D1 R2 & mini" or "LOLIN(WeMos) D1 R2 & mini" in Tools -> Board menu
* Libraries
  * Sketch -> Include Library -> Manage Libraries -> Search for "Button" and "[FastLED](http://fastled.io/)", install them.
    * Alternatively, install newest board version, then [apply this patch to FastLED library](https://github.com/FastLED/FastLED/commit/6b6c9c1c35f235e846334d9cd8984b4b4399f471)
    * Alternatively, install newest board version, then install [FastLED master branch via git](https://github.com/FastLED/FastLED) 

## Troubleshooting

* Compile error: "D6/D3 was not declared in this scope": Select the right board (see above)
* Compile error: "conflicting declaration 'typedef uint8_t boolean'": Patch FastLED or use ESP8622 board definitions version 2.4.1

## Building more features

Potentially helpful libraries include:

* ESP8266WiFi (basic WiFi library for ESP8266, compatible with standard Arduino WiFi lib; included with board toolchain)
* WiFiManager (provides a captive portal to set up WiFi secrets; see Library Manager)
* ESPUI (provides a simple Web UI; see Library Manager)


## Implementation details

[Case cutout as SVG, suitable for laser cutting](img/papercutout.svg)
![Circuit](img/Circuit.jpg)
![Case measures](img/Case_cutout_measures.jpg)
![Case cutout_plan](img/Case_cutout_plan.jpg)
![Case overview 2](img/Case_overview_2.jpg)
![Case overview](img/Case_overview.jpg)
![Board side](img/Board_side_2.jpg)
![Board side](img/Board_side.jpg)
![Data Pins 2](img/Data_Pins_2.jpg)
![Data Pins](img/Data_Pins.jpg)
![Button](img/Button.jpg)
![R1](img/R1.jpg)
![Button plus R1](img/Button_plus_R1.jpg)
![Case back](img/Case_back.jpg)
![Case closed](img/Case_closed.jpg)
![Case lock](img/Case_lock.jpg)
![Rainbow_lamp](img/Rainbow_lamp.jpg)
![case holder](img/case_holder.jpg)
