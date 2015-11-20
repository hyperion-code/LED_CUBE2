#include "LedCubeBuzzer.h"

LedCubeBuzzer::LedCubeBuzzer(int pin)
{
  _pin = pin;
  expired = true;
  pinMode(pin, OUTPUT);
  _time = micros();
  currentPattern = &wavePattern;
}
 
void LedCubeBuzzer::setNote(Note* note)
{
  if(currentPattern->hasExpired())
  {
    currentPattern = &openWindows;  
  }
  currentPattern->queue();

  _note = note;
  _note->play_time= 0;
  expired = false;
  _time = micros();
 
  playNote();
}
 
void LedCubeBuzzer::playNote()
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
 boolean LedCubeBuzzer::hasExpired()
{
  return expired;
}
LedCubeBuzzer::Note* LedCubeBuzzer::getNote()
{
  return _note;
}
void LedCubeBuzzer::lightDelay(int targetdelay){
      delayMicroseconds((targetdelay-(currentPattern->play())));
     
}


