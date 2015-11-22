#include "LedCubeBuzzer.h"
#include "WavePattern.h"
#include "AllOnPattern.h"
#include "ClimbPattern.h"


// 2 - 18 ROWS
// 47= SECOND TOP,49 = SECOND BOTTOM,51 = TOP,53 = BOTTOM COLUMNS

#define  R      0

struct Melody
{
  int notes[100];
  int beats[100];
  int noteIndex = 0;
};

Melody* m1;
LedCubeBuzzer* buzzer;
int m10[] =     {R,52,52,49,51,49,51,47,R,52,52,49,51,49,47,R,44,44,47,44,44,44,42,40,-1};
int beats1[]  = {4, 4, 4, 4, 4, 2, 6, 4,4, 4, 4, 4, 4, 2,10,4, 4, 4, 4, 4, 2, 4, 2, 2,-1};

int row1 = 53;
int row2 = 49;
int row3 = 47;
int row4 = 51;
int bpm = 128;
long tempo = (1000000 * 60) / bpm;

int noteIndex = -1;
LedCubeBuzzer::Note* notesAsPeriods[sizeof(m10)/2];

void getPeriodNotes()
{
  for(int i =0; i < sizeof(m10)/2;i++)
  {
    LedCubeBuzzer::Note* note = new LedCubeBuzzer::Note();
    if(m10[i] == -1 || m10[i] == 0)
      {
        note->period = 0;
      }
    else
      {
        note->period = (1.0/noteToFrequency(m10[i])) * 1000000;
      }
        note->max_play_time = (beats1[i]/4.0) * tempo;
        notesAsPeriods[i] = note;
  }

}

void setup() {
  initLeds();
  Serial.begin(9600);
  
  LedPattern::PatternSet* patterns = new LedPattern::PatternSet();
  /*patterns->set[0] = new WavePattern(3);
  patterns->set[1] = new ExplosionPattern(3);
  patterns->set[2] = new OpenWindows(3);*/
  patterns->set[3] = new AllOnPattern(1);
  //patterns->set[4] = new ClimbPattern(4);
  patterns->_size = 1;
  
  buzzer = new LedCubeBuzzer(21, patterns);
  getPeriodNotes();
}


//================LED CUBE SETUP===========================


void loop() {
   if(buzzer->hasExpired())
   {
    noteIndex++;
    if(noteIndex>=sizeof(notesAsPeriods)/2)
      exit(0);
      buzzer->setNote(notesAsPeriods[noteIndex]);
   }
   else
   {
    buzzer->playNote();
   }
}

int noteToFrequency(int keyNum)
{
  return floor(pow(2,((keyNum-49)/12.0)) * 440);
}
void initLeds()
{
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);
  for (int y = 0; y <= 18; y++) {
  pinMode(y, OUTPUT);
  }  
}
