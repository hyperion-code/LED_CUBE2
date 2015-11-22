#include "LedCubeBuzzer.h"
#include "WavePattern.h"
#include "AllOnPattern.h"
#include "ClimbPattern.h"
#include "WallPattern.h"
#include "EEPROM.h"


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
int m10[] =     {R, 52, 52, 49, 51, 49, 51, 47, R, 52, 52, 49, 51, 49, 47, R, 44, 44, 47, 45, 44, 45, 52, 40, 42, 44, 44, 44, 44, 47, R, R, 52, 52, 49, 51, 49, 51, 47, R, 52, 52, 49, 51, 49, 47, R, 44, 44, 47, 45, 44, 45, 52, 40, 42, 44, 44, 44, 42, 40, R, 52, 54, 52, 51, 54, 52, 47, R, 52, 54, 52, 51, 54, 52, 52, 52, 54, 52, 51, 54, 56, 47, R, 47, 49, 49, 51, 52, 54, R, 52, 52, 49, 51, 49, 51, 47, R, 52, 52, 49, 51, 49, 47, R, 44, 44, 47, 45, 44, 45, 52, 40, 42, 44, 44, 44, 40, 44, 49, 49, 49, 44, 49, 52, 52, 52, 49, 52, 57, 57, 57, 54, 57, 49, 51, 52, 54, 56, 56, 56, 56, 59, 59, 59, -1};
int beats1[]  = {4, 4, 4, 4, 4, 2, 6, 4, 4, 4, 4, 4, 4, 2, 10, 4, 4, 4, 4, 4, 2, 4, 2, 2, 2, 4, 4, 2, 2, 4, 16, 4, 4, 4, 4, 4, 2, 6, 4, 4, 4, 4, 4, 4, 2, 10, 4, 4, 4, 4, 4, 2, 4, 2, 2, 2, 4, 2, 4, 2, 4, 12, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 2, 4, 4, 4, 4, 4, 4, 2, 6, 4, 4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 2, 4, 2, 2, 2, 4, 2, 4, 2, 4, 4, 2, 4, 2, 4, 4, 2, 4, 2, 4, 4, 2, 4, 2, 4, 8, 8, 8, 8, 8, 8, 8, 8, 16, 16, 16, -1};

int row1 = 53;
int row2 = 49;
int row3 = 47;
int row4 = 51;

int greenButtonPort = 22;
int redButtonPort = 24;
int blueButtonPort = 28;
int yellowButtonPort = 26;

int bpm = 128;
long tempo = (1000000 * 60) / bpm;

int noteIndex = -1;
LedCubeBuzzer::Note* notesAsPeriods[sizeof(m10) / 2];

void getPeriodNotes()
{
  for (int i = 0; i < sizeof(m10) / 2; i++)
  {
    LedCubeBuzzer::Note* note = new LedCubeBuzzer::Note();
    if (m10[i] == -1 || m10[i] == 0)
    {
      note->period = 0;
    }
    else
    {
      note->period = (1.0 / noteToFrequency(m10[i])) * 1000000;
    }
    note->max_play_time = (beats1[i] / 4.0) * tempo;
    notesAsPeriods[i] = note;
  }

}

void setup() {
  initLeds();
  initButtons();
  
  LedPattern::PatternSet* patterns = new LedPattern::PatternSet();
  //patterns->set[0] = new WavePattern(4);
  //patterns->set[1] = new ExplosionPattern(4);
 // patterns->set[0] = new OpenWindows(4);
 patterns->set[0] = new ClimbPattern(4);
 patterns->set[1] = new WallPattern(4);
  patterns->_size =  2;

  buzzer = new LedCubeBuzzer(21, patterns);
  getPeriodNotes();
}


//================LED CUBE SETUP===========================

void loop() {
  if (digitalRead(yellowButtonPort))
  {
    reset();
    exit(0);
  }
  if (digitalRead(blueButtonPort)) buzzer->enableSound();
  if (digitalRead(greenButtonPort)) {}

  if (buzzer->hasExpired())
  {
    noteIndex++;
    if (noteIndex >= sizeof(notesAsPeriods) / 2)
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
  return floor(pow(2, ((keyNum - 49) / 12.0)) * 440);
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
void reset()
{
  delete notesAsPeriods;
  delete buzzer;
  //digitalWrite(32, LOW);
}
void initButtons()
{
  pinMode(22, INPUT);
  pinMode(24, INPUT);
  pinMode(26, INPUT);
  pinMode(28, INPUT);
  pinMode(30, OUTPUT);
  
  digitalWrite(32, HIGH);

}
