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
          
        }
      }
    }


    private:

    boolean inCurrentColorGroup(int i, int k)
    {
        
      
    }
    
    int red[16] = {}
    int blue[16] = {}
    int yellow[16] = {} 
    int green[16] = {}
};
#endif
