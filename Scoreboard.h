//Scoreboard.h
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include <fstream>
using namespace std;

class Scoreboard
{
    //private members
    private:
        string scoreboard[5][2];
        int currentScore;
    //public members
    public:
    Scoreboard();
    void printScoreBoard();
    bool addHighScore(string name, string score);
    int getCurrentScore();
    void setCurrentScore(int score);
    void sortScoreBoard();
   
};
#endif
