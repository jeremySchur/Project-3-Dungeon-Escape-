#ifndef MONSTERS_H
#define MONSTERS_H
#include <iostream>
#include <vector>
#include "Group.h"
using namespace std;

class Monsters
{
private:
    vector<string> tier1, tier2, tier3, tier4, tier5, tier6;
public:
    Monsters(string fileName);
    bool fightMonster(Group players, int tier);
};
#endif
