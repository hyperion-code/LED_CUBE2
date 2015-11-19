#include "SongBuzzer.h"

int counter = 0;
  int row1 = 53;
  int row2 = 49;
  int row3 = 47;
  int row4 = 51;
  int lednum = 18;
  int leds[18][5];
  int del = 0;
  int del2 = 0;
  long timelength =1;

SongBuzzer::SongBuzzer(int pin)
{
  _pin = pin;
  expired = true;
  pinMode(pin, OUTPUT);
  _time = micros();
}
 
void SongBuzzer::setNote(Note* note)
{
  _note = note;
  _note->play_time= 0;
  expired = false;
  _time = micros();
 
  playNote();
}
 
void SongBuzzer::playNote()
{
  if(_note->period != 0)
  {
   digitalWrite(_pin,HIGH);
   lightDelay(_note->period / 2);
   //delayMicroseconds(_note->period / 2);
 
   digitalWrite(_pin, LOW);
   //delayMicroseconds(_note->period / 2);
   lightDelay(_note->period / 2);
   expired = micros() - _time > _note->max_play_time;

  }else {
    for (int j = 0; j < 100; j++) {
      //lightDelay(_note->play_time/800);
      delayMicroseconds(1000);  
    }
    expired = true;       
  }
}
 
 
boolean SongBuzzer::hasExpired()
{

  return expired;
}
SongBuzzer::Note* SongBuzzer::getNote()
{
  return _note;
}

void SongBuzzer::setCube() {
  counter++;
  long start = micros();
  switch(counter%2){
      case 0:
   digitalWrite(row1, HIGH);
  digitalWrite(row2, LOW);
  digitalWrite(row3, LOW);
  digitalWrite(row4, LOW);
  for (int i = 1; i < lednum; i++) {
    digitalWrite(i + 1, leds[i][1]);
  }
  delay(del);
  for (int i = 1; i < lednum; i++) {
    digitalWrite(i + 1, LOW);
  }
  delay(del2);
      digitalWrite(row1, LOW);
  digitalWrite(row2, HIGH);
  digitalWrite(row3, LOW);
  digitalWrite(row4, LOW);
  for (int i = 1; i < lednum; i++) {
    digitalWrite(i + 1, leds[i][2]);
  }
  delay(del);
  for (int i = 1; i < lednum; i++) {
    digitalWrite(i + 1, LOW);
  }
  delay(del2);
  break;

 case 1:
      digitalWrite(row1, LOW);
  digitalWrite(row2, LOW);
  digitalWrite(row3, HIGH);
  digitalWrite(row4, LOW);
  for (int i = 1; i < lednum; i++) {
    digitalWrite(i + 1, leds[i][3]);
  }
  delay(del);
  for (int i = 1; i < lednum; i++) {
    digitalWrite(i + 1, LOW);
  }
  delay(del2);
      digitalWrite(row1, LOW);
  digitalWrite(row2, LOW);
  digitalWrite(row3, LOW);
  digitalWrite(row4, HIGH);
  for (int i = 1; i < lednum; i++) {
    digitalWrite(i + 1, leds[i][4]);
  }
  delay(del);
  for (int i = 1; i < lednum; i++) {
    digitalWrite(i + 1, LOW);
  }
  delay(del2);
  break;

  default: break;
  
  }
  timelength=micros()-start; 
}

void SongBuzzer::setLeds(){
    for (int h = 1; h <= 5;h++) {
      for (int y = 1; y <= 17; y++) {
        leds[y][h] = 1;  
      }
    }  
}
void SongBuzzer::lightDelay(int targetdelay){
      setCube();
      delayMicroseconds(((targetdelay)-(624)));
     
}


