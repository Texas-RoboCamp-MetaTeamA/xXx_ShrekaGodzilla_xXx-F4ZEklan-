#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>
#include <FastLED.h>
#define NUM_LEDS 15
#define DATA_PIN 6
#define NEOPIXEL 4
CRGB leds[NUM_LEDS];

BnrOneA one;

#define SSPIN 2

CRGB led[16];
int r = rand()*257;
int g = rand()*257;
int b = rand()*257;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(57600);
  one.spiConnect(SSPIN);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  
  one.stop();

  
}

void loop() {
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot].setRGB( r, g, b);
            FastLED.show();
            // clear this led for the next time around the loop
            //leds[dot] = CRGB::Black;
            delay(500);
        }



}

