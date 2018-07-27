#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>
BnrOneA one;

#define SSPIN 2

char lineUI[16];

int m;
int c;
int x;
int mode;
int high;
int i;
int adc[8];

void setup() {
  // put your setup code here, to run once:

  Serial.begin(57600);
  one.spiConnect(SSPIN);
  one.stop();

  mode, m, c, x = 0;
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
  
  if(one.obstacleSensors() == 0)
  {
    one.move(c + (lineFind() * x), c - (lineFind() * x));
  }

  if(one.readButton() == 3)
  {
    if(mode == 0)
    {
      mode = 1;
    }
    else if(mode == 1)
    {
      mode = 0;
    }
  }
  if(one.readButton() == 1)
  {
    if(mode == 0)
    {
      c += 1;
    }
    if(mode == 1)
    {
      x += 1;
    }
  }
  if(one.readButton() == 2)
  {
    if(mode == 0)
    {
      c -= 1;
    }
    if(mode == 1)
    {
      x -= 1;
    }
  }

  one.lcd1(x, c, lineFind());
  if(mode == 0)
  {
    one.lcd2("c");
  }
  if(mode == 1)
  {
    one.lcd2("x");
  }
}

int lineFind()
{
  high = 0;
  for(i = 0; i < 8; i++)
  {
    if(adc[i] > adc[high])
    {
      high = i;
    }
  }
  if(high > 3.5)
  {
    return 1;
  }
  if(high < 3.5)
  {
    return -1;
  }
}
