#include "SongBuzzer.h"

SongBuzzer::SongBuzzer(int pin)
{
  _pin = pin;
  expired = true;
  pinMode(pin, OUTPUT);
  _time = micros();
}
 
void SongBuzzer::setNote(Note* note)
{
  wavePattern.adjustLeds();
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
   //digitalWrite(_pin,HIGH);
   lightDelay(_note->period / 2);
   //delayMicroseconds(_note->period / 2);
 
   //digitalWrite(_pin, LOW);
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
void SongBuzzer::lightDelay(int targetdelay){
     
      delayMicroseconds((targetdelay-(wavePattern.play())));
     
}


