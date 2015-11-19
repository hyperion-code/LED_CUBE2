#ifndef LedPattern_h
#define LedPattern_h
#include "Arduino.h"

class LedPattern
{

  public:

    LedPattern()
      {
        for (int i = 1; i <= 5; i++){
          for (int k = 1; k <= 17; k++)
          {
            _leds[k][i] = 0;
          }
      }
    }
    
    virtual ~LedPattern(){};
    
    long play() {
      long start = micros();
      counter++;
      switch (counter % 2) {
        case 0:
          digitalWrite(row1, HIGH);
          digitalWrite(row2, LOW);
          digitalWrite(row3, LOW);
          digitalWrite(row4, LOW);
          for (int i = 1; i < lednum; i++) {
            digitalWrite(i + 1, _leds[i][1]);
          }
          delay(del0);
          for (int i = 1; i < lednum; i++) {
            digitalWrite(i + 1, LOW);
          }
          delay(del20);
          digitalWrite(row1, LOW);
          digitalWrite(row2, HIGH);
          digitalWrite(row3, LOW);
          digitalWrite(row4, LOW);
          for (int i = 1; i < lednum; i++) {
            digitalWrite(i + 1, _leds[i][2]);
          }
          delay(del0);
          for (int i = 1; i < lednum; i++) {
            digitalWrite(i + 1, LOW);
          }
          delay(del20);
          break;

        case 1:
          counter =1;
          digitalWrite(row1, LOW);
          digitalWrite(row2, LOW);
          digitalWrite(row3, HIGH);
          digitalWrite(row4, LOW);
          for (int i = 1; i < lednum; i++) {
            digitalWrite(i + 1, _leds[i][3]);
          }
          delay(del0);
          for (int i = 1; i < lednum; i++) {
            digitalWrite(i + 1, LOW);
          }
          delay(del20);
          digitalWrite(row1, LOW);
          digitalWrite(row2, LOW);
          digitalWrite(row3, LOW);
          digitalWrite(row4, HIGH);
          for (int i = 1; i < lednum; i++) {
            digitalWrite(i + 1, _leds[i][4]);
          }
          delay(del0);
          for (int i = 1; i < lednum; i++) {
            digitalWrite(i + 1, LOW);
          }
          delay(del20);
          break;

        default: break;

      }
      
      return 624;
    }
  protected:
    virtual void adjustLeds()=0;
    int _leds[18][5]; // first dimension = column, second dimension = row
    
  private:
    int counter = 0;
    int row1 = 53;
    int row2 = 49;
    int row3 = 47;
    int row4 = 51;
    int lednum = 18;
    int del0, del20 = 0;
};

#endif
