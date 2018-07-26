#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>
BnrOneA one;

#define SSPIN 2

int thresh;
int adc[8];
int i;

char lineUI[16];

void setup() {
  // put your setup code here, to run once:

  Serial.begin(57600);
  one.spiConnect(SSPIN);
  one.stop();

  thresh = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  adc[0] = one.readAdc0();
  adc[1] = one.readAdc1();
  adc[2] = one.readAdc2();
  adc[3] = one.readAdc3();
  adc[4] = one.readAdc4();
  adc[5] = one.readAdc5();
  adc[6] = one.readAdc6();
  adc[7] = one.readAdc7();

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
  for(i = 0; i < 8; i++) {
    if(adc[i] > thresh)
    {
      lineUI[i * 2] = '*';
      lineUI[i * 2 + 1] = '*';
    }
    if(adc[i] < thresh)
    {
      lineUI[i * 2] = '-';
      lineUI[i * 2 + 1] = '-';
    }
  }
  lineUI[16] = 0;
  one.lcd1(lineUI);
  one.lcd2(thresh);
}
