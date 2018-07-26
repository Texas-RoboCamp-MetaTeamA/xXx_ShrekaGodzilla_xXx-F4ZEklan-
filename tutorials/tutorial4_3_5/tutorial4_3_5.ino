#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>
BnrOneA one;

#define SSPIN 2

int leftVal = 0;
int rightVal = 0;

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


  if(leftRight == true)
  {
     if(one.readButton()==1)
     leftVal++;
     if(one.readButton()==2)
     rightVal++;
  }
  if(leftRight == false)
  {
     if(one.readButton()==1)
     leftVal--;
     if(one.readButton()==2)
     rightVal--;
  }

  if(leftVal>100)
    leftVal=100;
  if(leftVal<-100)
    leftVal=-100;
  if(rightVal>100)
    rightVal=100;
  if(rightVal<-100)
    rightVal=-100;
  one.lcd1(leftVal);
  one.lcd2(rightVal);
  
}

