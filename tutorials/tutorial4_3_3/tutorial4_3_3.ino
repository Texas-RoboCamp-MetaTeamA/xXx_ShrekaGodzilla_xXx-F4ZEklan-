#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>
BnrOneA one;

#define SSPIN 2

boolean leftRight = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  one.spiConnect(SSPIN);
  one.stop();
}

void loop() {
  if(one.readButton()==3)
    if(leftRight == true)
      leftRight = false;
    else
      leftRight = true;

      
  if(leftRight == false)
    one.lcd1("left"); 
  if(leftRight == true)
    one.lcd1("right");
  
}

