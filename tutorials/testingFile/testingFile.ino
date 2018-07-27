#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>
BnrOneA one;

int thresh;
int adc[8];
int i;

char lineUI[16];

#define SSPIN 2
void setup() {
  // put your setup code here, to run once:

  Serial.begin(57600);
  one.spiConnect(SSPIN);
  one.stop();

  thresh = 350;
}
void loop() {
  int big = 0;
  // put your main code here, to run repeatedly:
  adc[0] = one.readAdc0();
  adc[1] = one.readAdc1();
  adc[2] = one.readAdc2();
  adc[3] = one.readAdc3();
  adc[4] = one.readAdc4();
  adc[5] = one.readAdc5();
  adc[6] = one.readAdc6();
  adc[7] = one.readAdc7();
  for(i = 0; i<8;i++)
  {
    if(adc[i]-50>big)
    {
      big = adc[i]-50;
    }
  }
  i = 0;

   thresh = big;
  
  if(one.readButton() == 2)
  {
    thresh -= 10;
  }
  if(one.readButton() == 1)
  {
    thresh += 10;
  }


  printAsterisks();
}

void printAsterisks() {
  int place = -1;
  String direction;
  for(i = 0; i < 8; i++) {
    if(adc[i] > thresh)
    {
      lineUI[i * 2] = '*';
      lineUI[i * 2 + 1] = '*';
      place = ((2*i)+1)/2;
    }
    if(adc[i] < thresh)
    {
      lineUI[i * 2] = '-';
      lineUI[i * 2 + 1] = '-';
    }
  }
  i = 0;
  if(place>3.5)
  {
    direction = "Move left";
  }
  else if(place<3.5)
  {
    direction = "Move Right";
  }
  else
    direction = "Centered";
  lineUI[16] = 0;
  one.lcd1(lineUI);
  one.lcd2(direction);
}
