#ifndef OpenWindows_h
#define OpenWindows_h

#include "LedPattern.h"

class OpenWindows: public LedPattern
{
  public:
    OpenWindows(int maxRunCount):LedPattern(maxRunCount){};
    virtual void adjustLeds()
    {
      for (int i = 0; i <= 5; i++)
      {
        for (int k = 0; k <= 16; k++)
        {
          if (!opened)
          {
            if (isIn(i, k))
            {
              _leds[k][i] = 1;
            }
            else
            {
              _leds[k][i] = 0;  
            }
          }
          else
          {
            if (!isIn(i, k) && (k != 6 && k !=7 && k!=10 && k!=11))
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
      if(opened)
      opened = false;
      else
      opened = true;
    }
    protected:
    virtual void reset()
    {

    }
  private:
    boolean opened = false;

    boolean isIn(int i, int k)
    {
      for (int z = 0; z <= 7; z++)
        if (isOn[i-1][z] == k)
        {
          return true;
        }
      return false;
    }
    int isOn[4][8] = {
      {6, 7, 10, 11, -1, -1,-1,-1},
      {8, 9, 5, 12, 14, 15, 2, 3},
      {8, 9, 5, 12, 14, 15, 2, 3},
      {6, 7, 10, 11, -1, -1, -1, -1}
    };
};
#endif
