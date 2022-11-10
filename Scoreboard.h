#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include <fstream>
using namespace std;

class Scoreboard
{
private:
    string scoreboard[5][2];
    int currentScore;

public:
   Scoreboard();
   void printScoreBoard();
   bool addHighScore(string name, string score);
   int getCurrentScore();
   void setCurrentScore(int score);
   void sortScoreBoard();
   
};
#endif
