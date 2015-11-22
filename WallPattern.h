#ifndef WallPattern_h
#define WallPattern_h

#include "LedPattern.h"

class WallPattern: public LedPattern
{
  public:
    WallPattern(int maxRunCount):LedPattern(maxRunCount){};
    virtual void adjustLeds()
    {
      for (int i = 0; i <= 5; i++)
      {
        for (int k = 0; k <= 16; k++)
        {
            if(wallNum >= k/(4.0))
              _leds[k][i]  = 1;
            else
              _leds[k][i] = 0;
        }
    }
    if(wallNum >= 4)
      wallNum = 0;
    else
      wallNum++;
  }

  virtual void reset()
    {
      wallNum = 1;
    }

  private:
    int wallNum = 1;
};
#endif
