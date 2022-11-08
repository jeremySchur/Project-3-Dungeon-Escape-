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
        Player(string name);
        string getName();
        int getFullness();
        void setFullness(int fullness_);

};
#endif
