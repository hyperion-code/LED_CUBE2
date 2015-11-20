#ifndef SongBuzzer_h
#define SongBuzzer_h
 
#include "Arduino.h"
#include "WavePattern.h"
#include "ExplosionPattern.h"
#include "OpenWindows.h"
 
class SongBuzzer
{
 
public:
 
  struct Note
  {
    int num;
    int frequency;
    int period;
    int beat;
    long play_time = 0;
    long max_play_time = 0;
  };
 
  SongBuzzer(int pin);
  boolean hasExpired();
  void setNote(Note* note);
  void playNote();
  void lightDelay(int targetdelay);
  Note* getNote();
 
private:
  Note* _note;
  int _pin;
  boolean expired;
  long _time;
  WavePattern wavePattern;
  ExplosionPattern explosionPattern;
  OpenWindows openWindows;
  LedPattern * currentPattern;
  int patternIndex = 0;

};
 
#endif
