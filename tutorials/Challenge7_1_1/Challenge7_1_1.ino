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
  return place;
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
/*  if(one.readButton() == 2)
  {
    thresh -= 10;
  }
  if(one.readButton() == 1)
  {
    thresh += 10;
  }
*/
  thresh = max;
  return printAsterisks();
}

void moveTowardsCenter(int avg)
{
    //if the line is to the right
    if(avg>3.5)
    {
      one.move(1,0);
      delay(1000);
      one.move(1,1);
    }
    
    else if(avg<3.5)
    {
      one.move(0,1);
      delay(1000);
      one.move(1,1);
    }
    
    else
    {
      one.move(1,1);
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
