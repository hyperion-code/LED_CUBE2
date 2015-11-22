#ifndef AllOnPattern_h
#define AllOnPattern_h

#include "LedPattern.h"

class AllOnPattern: public LedPattern
{
  public:
    AllOnPattern(int maxRunCount):LedPattern(maxRunCount){};
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
};
#endif
