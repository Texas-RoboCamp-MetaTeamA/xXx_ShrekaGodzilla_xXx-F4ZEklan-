#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>
BnrOneA one;

#define SSPIN 2

int i;

char lineUI[16];

void setup() {
  // put your setup code here, to run once:

  Serial.begin(57600);
  one.spiConnect(SSPIN);
  one.stop();

  i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:

  printAsterisks();
}

void printAsterisks() {
  for(i = 0; i < 8; i++) {
    lineUI[i * 2] = '*';
    lineUI[i * 2 + 1] = '*';
  }
  lineUI[16] = 0;
  one.lcd1(lineUI);
}

