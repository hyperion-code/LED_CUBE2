#ifndef WavePattern_h
#define WavePattern_h

#include "LedPattern.h"

class WavePattern: public LedPattern
{
  public:
    WavePattern(){
      setMaxRunCount(4);
      };
    virtual void adjustLeds()
    {
      for (int i = 1; i <= 5; i++)
      {
        for (int k = 0; k <= 16; k++)
        {          
          if(match && inOn(k))
          {
            _leds[k][i] = 1; 
          }
          else if(!match && !inOn(k))
          {
            _leds[k][i] = 1; 
          }
          else
          {
            _leds[k][i] = 0;
          }           
        }
        } 
        if(match)
          match = false;
        else
          match = true;
      }
    private:
          boolean inOn(int k)
          {
            for(int z = 0; z < sizeof(on)/2; z++)
            {
             if(on[z] == k)
             {
              return true;
             }
            }
            return false;
          }  
            
          int on[8] = {2,4,5,7,10,12,13,15};
          boolean match = true;
          
          
};
#endif
