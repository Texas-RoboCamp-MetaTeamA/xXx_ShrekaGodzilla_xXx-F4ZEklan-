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
  
  if(one.obstacleSensors()==0)
    one.move(100,100);
  else
  {
    one.brake(100,100);
    delay(500);
    one.move(100,-100);
    delay(250);
    one.brake(100,100);
  }
  
}
