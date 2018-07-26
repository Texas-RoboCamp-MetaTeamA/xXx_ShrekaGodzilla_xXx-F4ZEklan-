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
  for(int i = 0;i<8;i++)
  {
    Serial.print(one.readAdc(i));
  }
  Serial.println();
  
}

