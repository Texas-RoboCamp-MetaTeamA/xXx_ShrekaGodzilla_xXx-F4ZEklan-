#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>
BnrOneA one;
#define SSPIN 2
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  one.spiConnect(SSPIN);
  one.stop();
}

void printAsterisks() {
  char lineUI[17];
  for(int i = 0; i < 16; i++) {
    lineUI[i] = '*';
  }
  lineUI[16] = 0;
  one.lcd1(lineUI);
}

void loop() {
  printAsterisks();
}
