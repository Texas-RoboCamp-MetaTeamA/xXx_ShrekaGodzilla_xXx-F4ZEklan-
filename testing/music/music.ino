#include <BnrOneA.h>
#include <EEPROM.h>
#include <SPI.h>

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

BnrOneA one;

float bpm = 90.0;

int halfNote = ((1000.0 * 60.0) / bpm) * 2;
int quarterNote = (1000.0 * 60.0) / bpm;
int eighthNote = ((1000.0 * 60.0) / bpm) / 2.0;
int sixteenthNote = ((1000.0 * 60.0) / bpm) / 4.0;

#define SSPIN 2

void setup() {
  Serial.begin(57600);
  one.spiConnect(SSPIN);
  one.stop();
  
  one.obstacleEmitters(true);

  one.lcd1("ur family tree");
  one.lcd2("lgbtee");
}

void loop() {
  //c, d, f, g sharped
  for(int i = 0; i < 2; i++) //should repeat 4 times but honestly it gets annoying so nah just 2
  {
    one.lcd1("measure ", i);
    
    PlayTone(NOTE_A3, eighthNote + sixteenthNote);
    PlayTone(NOTE_A3, sixteenthNote);
    PlayTone(0, sixteenthNote);
    PlayTone(NOTE_A3, sixteenthNote);
    PlayTone(0, sixteenthNote);
    PlayTone(NOTE_A3, sixteenthNote);
    PlayTone(NOTE_A3, eighthNote);
    PlayTone(NOTE_GS3, eighthNote);
    PlayTone(NOTE_CS4, eighthNote);
    PlayTone(NOTE_FS5, sixteenthNote);
    PlayTone(NOTE_E5, sixteenthNote);
    
    PlayTone(NOTE_CS5, sixteenthNote);
    PlayTone(NOTE_B4, sixteenthNote);
    PlayTone(NOTE_CS5, sixteenthNote);
    PlayTone(NOTE_FS5, sixteenthNote);
    PlayTone(NOTE_FS5, sixteenthNote);
    PlayTone(NOTE_E5, sixteenthNote);
    PlayTone(NOTE_CS5, sixteenthNote);
    PlayTone(NOTE_E5, sixteenthNote);
    PlayTone(NOTE_FS5, sixteenthNote);
    PlayTone(NOTE_E5, sixteenthNote);
    PlayTone(NOTE_CS5, sixteenthNote);
    PlayTone(NOTE_B4, sixteenthNote);
    PlayTone(NOTE_CS5, sixteenthNote);
    PlayTone(NOTE_FS5, sixteenthNote);
    PlayTone(NOTE_E5, eighthNote);
  }

  one.lcd1("measure ", 3);
  PlayTone(0, sixteenthNote);
  PlayTone(NOTE_FS4, sixteenthNote);
  PlayTone(NOTE_FS4, sixteenthNote);
  PlayTone(NOTE_FS4, sixteenthNote);
  PlayTone(NOTE_FS4, eighthNote);
  PlayTone(NOTE_FS4, sixteenthNote);
  PlayTone(NOTE_FS4, eighthNote + sixteenthNote);
  PlayTone(NOTE_GS4, eighthNote);
  PlayTone(NOTE_AS4, sixteenthNote);
  //The final sixteenth note of this measure ties into the half note in the next measure. It is included in the next block.

  one.lcd1("measure ", 4);
  PlayTone(NOTE_B4, sixteenthNote + halfNote);
  PlayTone(NOTE_DS4, sixteenthNote);
  PlayTone(NOTE_DS4, eighthNote + sixteenthNote);
  PlayTone(NOTE_E4, eighthNote);
  PlayTone(NOTE_FS4, sixteenthNote);
  PlayTone(NOTE_FS4, sixteenthNote + sixteenthNote); //final sixteenth note ties into first sixteenth note of next measure

  one.lcd1("measure ", 5);
  PlayTone(NOTE_E4, eighthNote + sixteenthNote);
  PlayTone(NOTE_E4, eighthNote);
  PlayTone(NOTE_DS4, sixteenthNote);
  PlayTone(NOTE_CS4, sixteenthNote + quarterNote);
  PlayTone(NOTE_CS4, eighthNote);
  PlayTone(NOTE_B4, eighthNote);

  one.lcd1("measure ", 6);
  PlayTone(NOTE_DS4, quarterNote + sixteenthNote);
  PlayTone(NOTE_CS4, sixteenthNote);
  PlayTone(NOTE_B4, eighthNote);
  PlayTone(NOTE_A3, eighthNote + sixteenthNote);
  PlayTone(NOTE_A3, sixteenthNote);
  PlayTone(0, sixteenthNote);
  PlayTone(NOTE_A3, sixteenthNote);
  PlayTone(0, sixteenthNote);
  PlayTone(NOTE_A3, sixteenthNote);

  one.lcd1("measure ", 7);
  PlayTone(NOTE_A3, eighthNote);
  PlayTone(NOTE_GS3, eighthNote);
  PlayTone(NOTE_CS4, eighthNote);
  PlayTone(NOTE_B4, eighthNote);
  PlayTone(NOTE_FS4, sixteenthNote);
  PlayTone(NOTE_FS4, sixteenthNote);
  PlayTone(NOTE_FS4, sixteenthNote);
  PlayTone(NOTE_FS4, eighthNote + sixteenthNote + sixteenthNote); //ties into first 16th note of next measure

  one.lcd1("measure ", 8);
  PlayTone(NOTE_FS4, eighthNote + sixteenthNote);
  PlayTone(NOTE_GS4, eighthNote);
  PlayTone(NOTE_AS4, sixteenthNote);
  PlayTone(NOTE_B4, sixteenthNote + halfNote);
  
  one.lcd1("measure ", 9);
  PlayTone(NOTE_DS4, sixteenthNote);
  PlayTone(NOTE_DS4, eighthNote + sixteenthNote);
  PlayTone(NOTE_E4, eighthNote);
  PlayTone(NOTE_FS4, eighthNote);
  PlayTone(NOTE_FS4, eighthNote);
  PlayTone(NOTE_E4, sixteenthNote);
  PlayTone(NOTE_E4, eighthNote);
  PlayTone(NOTE_DS4, eighthNote);
  PlayTone(NOTE_CS4, sixteenthNote + quarterNote); //ties into first quarter note of next measure
  
  one.lcd1("measure ", 9);
  PlayTone(NOTE_CS4, eighthNote);
  PlayTone(NOTE_B4, eighthNote);
  PlayTone(NOTE_DS4, quarterNote + sixteenthNote);
  PlayTone(NOTE_CS4, sixteenthNote);
  PlayTone(NOTE_DS4, eighthNote);
  
  one.lcd1("measure ", 10);
  PlayTone(NOTE_A3, eighthNote + sixteenthNote);
  PlayTone(NOTE_A3, sixteenthNote);
  PlayTone(0, sixteenthNote);
  PlayTone(NOTE_A3, sixteenthNote);
  PlayTone(0, sixteenthNote);
  PlayTone(NOTE_A3, sixteenthNote);
  PlayTone(NOTE_A3, eighthNote);
  PlayTone(NOTE_GS3, eighthNote);
  PlayTone(NOTE_CS4, quarterNote);
}

void PlayTone(int frequency, int duration) {
  if(frequency != 0)
    tone(9, frequency, duration);
    one.move(50,-50);
    
  delay(duration);
}

