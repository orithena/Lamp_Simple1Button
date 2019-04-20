#define DEBUG

#include "FastLED.h"
#include <Button.h>
#include "ESP8266WiFi.h"

// How many leds are there in your strip?
#define NUM_LEDS 16

// Where is the LED data line connected?
#define LED_DATA D3

// Where is the brightness button connected?
#define BRIGHT_PIN D6

// Speed 0..8 (quadratic divisor of milliseconds)
// 0 = so fast that it's definitely not recommended for photosensitive people
// 4 = a nice pace, you could watch it all day
// 7 = so slow, you almost don't see it moving
// 8 and above = animation is stopped
#define SPEED_DIV 5

// button object checking the button pin (it makes sure we get exactly one event per button press) 
Button bright_btn(BRIGHT_PIN);

// state variable for brightness.
byte bright = 2;

// the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  // make sure the Wifi chip is off, we don't need it.
  WiFi.forceSleepBegin();

  // Initialize the LEDs
  pinMode(LED_DATA, OUTPUT); 
  FastLED.addLeds<WS2812B, LED_DATA, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(64);
  
  #ifdef DEBUG
  Serial.begin(230400);
  Serial.println("\n\n === Lamp_Simple1Button.ino ===\n\n");
  #endif
}

void loop() {
  // I usually save the current millisecond count per loop.
  uint32_t ms = millis();

  // button handling code
  if( bright_btn.pressed() ) {
    bright = (bright + 1) % 5;
    // our bright state variable counts from 0..4, but setBrightness wants 0..255
    byte real_bright = map(bright, 0, 4, 0, 255);
    // set brightness via FastLED library
    FastLED.setBrightness(real_bright);
    // debugging output via serial link
    #ifdef DEBUG
    Serial.printf("Brightness button pressed. New value: %d (%d)\n", bright, real_bright);
    #endif
  }

  EVERY_N_MILLISECONDS(10) {

    // fill the leds array with a rainbow, starting at a value determined by ms and SPEED_DIV
    fill_rainbow(leds, NUM_LEDS, (ms >> SPEED_DIV) & 0xFF, 255/NUM_LEDS);

    // push the leds array out to the LED strip
    FastLED.show();
  }
  // reset the watchdog (normally, the Wifi library does this, but we have disabled it).
  wdt_reset();
}

