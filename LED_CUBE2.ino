#include "SongBuzzer.h"
#include "WavePattern.h"


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
Melody* melodies[2];
SongBuzzer* buzzer;
int m10[] = {R,52,52,49,51,49,51,47,R,52,52,49,51,49,47,R,44,44,47,44,44,44,42,40,-1};
int beats1[]  = {4, 4, 4,  4,  4,  2, 6, 4, 4,4,4,4,4,2,10,4,4,4,4,4,2,4,2,2,2,4,4,4,4,4,2,6,4,4,4,4,4,4,2,10,4,4,4,4,4,2,4,2,4};

SongBuzzer::Note* m11[sizeof(m10)/2];


int MAX_COUNT = sizeof(melodies[0]->notes) / 2; // this will need changed
int row11 = 53;
int row22 = 49;
int row33 = 47;
int row44 = 51;
int bpm = 250;
int numOfBuzzers = 2;
long tempo = (1000000 * 60) / bpm;
int modcounter =0;
int octaveMultiplier = 1;

int noteIndex = -1;
SongBuzzer::Note* notesAsPeriods[sizeof(m10)/2];
void getPeriodNotes()
{
  for(int i =0; i < sizeof(m10)/2;i++)
  {
    SongBuzzer::Note* note = new SongBuzzer::Note();
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
  buzzer = new SongBuzzer(21);
  getPeriodNotes();
}


//================LED CUBE SETUP===========================


void loop() {
 
   if(buzzer->hasExpired())
   {
    noteIndex++;
    if(noteIndex>=sizeof(notesAsPeriods)/2)
      noteIndex=0;
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
  pinMode(row11, OUTPUT);
  pinMode(row22, OUTPUT);
  pinMode(row33, OUTPUT);
  pinMode(row44, OUTPUT);
  for (int y = 0; y <= 18; y++) {
  pinMode(y, OUTPUT);
  }  
  
}
