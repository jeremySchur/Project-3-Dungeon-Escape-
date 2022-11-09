#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;

class Group
{
    private:
        vector<Player> players;
        int rooms_cleared = 0;
        int num_keys = 0;
        int anger_level = 0;
        int gold = 100;
        int ingredients = 0;
        int cookware[3] = {0,0,0};
        int weapons[5] = {0,0,0,0,0};
        int armor = 0;
        int treasures[5] = {0,0,0,0,0};
        
    public:
        Group();
        bool addPlayer(Player p);
        int getRoomsCleared();
        int getNumKeys();
        int getAngerLevel();
        int getGold();
        int getIngredients();
        int getNumPots();
        int getNumPans();
        int getNumCauldrons();
        int getNumClubs();
        int getNumSpears();
        int getNumRapiers();
        int getNumBattleAxes();
        int getNumLongSwords();
        void setRoomsCleared(int rooms_cleared_);
        void setNumKeys(int num_keys_);
        void setAngerLevel(int anger_level_);
        void setGold(int gold_);
        void setIngredients(int ingredients_);
        void setNumPots(int num_pots);
        void setNumPans(int num_pans);
        void setNumCauldrons(int num_cauldrons);
        void setNumClubs(int num_clubs);
        void setNumSpears(int num_spears);
        void setNumRapiers(int num_rapiers);
        void setNumBattleAxes(int num_battleAxes);
        void setNumLongSwords(int num_longSwords);

};
#endif
