#ifndef ClimbPattern_h
#define ClimbPattern_h

#include "LedPattern.h"

class ClimbPattern: public LedPattern
{
  public:
    ClimbPattern(int maxRunCount): LedPattern(maxRunCount) {};
    virtual void adjustLeds()
    {
      for (int i = 0; i <= 5; i++)
      {
        for (int k = 0; k <= 16; k++)
        {
          if (i == currentLayer)
          {
            _leds[k][i] = 1;
          }
          else
          {
            _leds[k][i] = 0;
          }
        }
      }
      if(currentLayer >=4 )
        currentLayer = 0;  
      else
        currentLayer++;
    }

  private:
    int currentLayer = 1;
};
#endif
