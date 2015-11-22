#ifndef AllOffPattern_h
#define AllOffPattern_h

#include "LedPattern.h"

class AllOffPattern: public LedPattern
{
  public:
    AllOffPattern(int maxRunCount):LedPattern(maxRunCount){};
    virtual void adjustLeds()
    {
      for (int i = 0; i <= 5; i++)
      {
        for (int k = 0; k <= 16; k++)
        {
          _leds[k][i] = 1;
        }
    }
  }
  virtual void reset(){}
};
#endif
