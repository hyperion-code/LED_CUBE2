#include "LedCubeBuzzer.h"
#include "AllOffPattern.h"

LedCubeBuzzer::LedCubeBuzzer(int pin, LedPattern::PatternSet* set)
{
  _pin = pin;
  expired = true;
  pinMode(pin, OUTPUT);
  _time = micros();
  _patterns = set;
}

void LedCubeBuzzer::setNote(Note* note)
{
  if (_patterns->set[patternIndex]->hasExpired())
  {
    if (patternIndex == (_patterns->_size - 1))
      patternIndex = 0;
    else
      patternIndex++;
  }
  _patterns->set[patternIndex]->queue();

  _note = note;
  _note->play_time = 0;
  expired = false;
  _time = micros();

  playNote();
}

void LedCubeBuzzer::playNote()
{
  if (_note->period != 0)
  {
    if (_sound)digitalWrite(_pin, HIGH);
    lightDelay(_note->period / 2);
    //delayMicroseconds(_note->period / 2);

    if (_sound) digitalWrite(_pin, LOW);
    //delayMicroseconds(_note->period / 2);
    lightDelay(_note->period / 2);
    expired = micros() - _time > _note->max_play_time;

  } else {
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
void LedCubeBuzzer::lightDelay(int targetdelay) {
  delayMicroseconds((targetdelay - (_patterns->set[patternIndex]->play())));
}
void LedCubeBuzzer::disableSound()
{
  _sound = false;
}
void LedCubeBuzzer::enableSound()
{
  _sound = true;  
}
void LedCubeBuzzer::stop()
{
  AllOffPattern* off = new AllOffPattern(1);
  off->play();
  patternIndex = 0;
}
LedCubeBuzzer::~LedCubeBuzzer()
{
  delete _patterns;
}

