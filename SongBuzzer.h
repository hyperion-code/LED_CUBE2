#ifndef SongBuzzer_h
#define SongBuzzer_h
 
#include "Arduino.h"
 
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
  void lightdelay(int targetdelay);
  Note* getNote();
  void setcube();
  void setleds();
 
private:
  Note* _note;
  int _pin;
  boolean expired;
  long _time;

};
 
#endif
