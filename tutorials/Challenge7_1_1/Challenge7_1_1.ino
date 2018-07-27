#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>
BnrOneA one;

#define SSPIN 2

boolean firstTime = true;
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

void obstacleAvoidance() {
  
  if(one.obstacleSensors()==0)
    one.move(100,100);
  else
  {
    one.brake(100,100);
    one.move(-100,-100);
    delay(150);
    one.brake(100,100);
    delay(500);
    one.move(100,-100);
    delay(1);
    one.brake(100,100);
  }
  
}

int printAsterisks() {
  int place = -1;
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
  lineUI[16] = 0;
  one.lcd1(lineUI);
  one.lcd2(thresh);
  if(place>3.5)
    return 1;
  return -1;
}

int lineRead() {
  // put your main code here, to run repeatedly:
  int max = 0;
  
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
    if(adc[i]-50>max)
    {
      max = adc[i]-50;
    }
  }
  
  thresh = max;
  return printAsterisks();
}

void moveTowardsCenter(int avg)
{
    if(avg>0)
    if(avg<0)
    else
    {
      
    }
  
}




void loop() {
  // put your main code here, to run repeatedly:
  //find line
  //read line
  //move to center
  //obstacle avoidance
  //stopping

  
  int num;
  
  if(firstTime == true)
  {
    firstTime = false;
  }
  
  num = lineRead();  
  

  moveTowardsCenter(num);

  obstacleAvoidance();
}
