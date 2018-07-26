//4.1.1 AND 4.1.2



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

void loop() {
  one.lcd1("Hello World!");
  one.lcd2("Texas RoboCamp!");
  delay(2000);
  one.lcd1("Hook'em");
  one.lcd2("Horns!");
  delay(2000);
}

