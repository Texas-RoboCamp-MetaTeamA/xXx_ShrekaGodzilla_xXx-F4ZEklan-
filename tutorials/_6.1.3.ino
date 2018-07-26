#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>
//#include <iostream>
BnrOneA one;
int thresh;
#define SSPIN 2
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  one.spiConnect(SSPIN);
  one.stop();
}

void printAsterisks() {
  char lineUI[17];
  for(int i = 0; i < 7; i++) {
    lineUI[i] = '*';
    lineUI[i+1]=lineUI[i];;
    if(one.readButton()==1)
    {
      thresh=thresh+10;
      Serial.print(thresh);
    }
    if(one.readButton()==2)
    {
      thresh=thresh-10;
      Serial.print(thresh);
    }
  }
  lineUI[16] = 0;
  one.lcd1(lineUI);
}

void loop() {
  printAsterisks();
}
