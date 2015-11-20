#ifndef ExplosionPattern_h
#define ExplosionPattern_h

#include "LedPattern.h"

class ExplosionPattern: public LedPattern
{
  public:
    ExplosionPattern() {};
    virtual void adjustLeds()
    {
      
      for (int i = 0; i <= 5; i++)
      {
        for (int k = 0; k <= 16; k++)
        {
          if (exploded)
          {
            if (i == 2 || i == 3)
            {
              if (isInCube(i, k))
              {
                _leds[k][i] = 0;
              }
              else
              {
                _leds[k][i] = 1;
              }
            }
            else
            {
              _leds[k][i] = 1;
            }
          }
          else
          {
            if (isInCube(i, k))
            {
              _leds[k][i] = 1;
            }
            else
            {
              _leds[k][i] = 0;
            }
          }
        }
      }
      if (exploded)
        exploded = false;
      else
        exploded = true;
    }
  private:
    boolean isInCube(int i, int k)
    {
      if ((i == 2) || (i == 3))
      {
        return (k == 6 || k == 7 || k == 10 || k == 11);
      }
      return false;
    }
    boolean exploded = true;
};
#endif
