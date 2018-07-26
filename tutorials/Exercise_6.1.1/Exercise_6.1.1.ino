#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>
BnrOneA one;

#define SSPIN 2

int line;
int counter;
int i;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(57600);
  one.spiConnect(SSPIN);
  one.stop();

  i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:

  for(i = 0; i < 8; i++)
  {
    Serial.print(one.readAdc1());
    delay(1000);
  }
  Serial.println();
}
