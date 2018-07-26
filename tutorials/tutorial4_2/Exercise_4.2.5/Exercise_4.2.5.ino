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
  // one.obstacleEmitters(true);
}

void loop() {
  Serial.print("Hello World!");

  if(one.obstacleSensors() == 3)
  {
    one.lcd1("Both Sensors Activated");
  }
  else if(one.obstacleSensors() == 1)
  {
    one.lcd1("Left Sensor Activated");
  }
  else if(one.obstacleSensors() == 2)
  {
    one.lcd1("Right Sensor Activated");
  }
  else
    one.lcd1("No sensors activated");
}
