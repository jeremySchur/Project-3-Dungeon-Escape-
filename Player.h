//Player.h
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player
{
    private:
        string name;
        int fullness;

    public:
        Player();
        Player(string name);
        string getName();
        int getFullness();
        void setFullness(int fullness_);

};
#endif
