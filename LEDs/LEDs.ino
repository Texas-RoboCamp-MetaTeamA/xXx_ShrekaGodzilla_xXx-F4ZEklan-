#include <FastLED.h>
#define DATA_PIN 7

int NUM_LEDS = 14;

CRGB leds[14];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  leds[0].setRGB(0, 255, 0);
}
