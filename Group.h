//Group.h
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi

#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;

class Group
{
    // private members
    private:
        vector<Player> players;
        int rooms_cleared = 0;
        int num_keys = 0;
        int anger_level = 0;
        int gold = 100;
        int ingredients = 0;
        int cookware[3] = {0,0,0};
        int weapons[5] = {0,0,0,0,0}; //MAX 5 TOTAL
        int totalWeapons = 0;
        int armor = 0;  //MAX 5
        int treasures[5] = {0,0,0,0,0};
    //public members
    public:
        Group();
        bool addPlayer(Player p);
        Player getPlayer(int index);
        void setPlayerFullness(int index, int fullness);
        int getSize();
        void removePlayer(int index);

        // getters
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
        int getNumArmor();
        int getNumRings();
        int getNumNecklace();
        int getNumBraclet();
        int getNumCirclet();
        int getNumGoblet();
        int getTotalWeapons();
        
        //setters
        void setRoomsCleared(int rooms_cleared_);
        void setNumKeys(int num_keys_);
        void setAngerLevel(int anger_level_);
        void setGold(int gold_);
        void setIngredients(int ingredients_);
        void setNumPots(int num_pots);
        void setNumPans(int num_pans);
        void setNumCauldrons(int num_cauldrons);
        bool setNumClubs(int num_clubs);
        bool setNumSpears(int num_spears);
        bool setNumRapiers(int num_rapiers);
        bool setNumBattleAxes(int num_battleAxes);
        bool setNumLongSwords(int num_longSwords);
        bool setNumArmor(int num_armor);
        void setNumRings(int num_rings);
        void setNumNecklace(int num_necklace);
        void setNumBraclet(int num_braclet);
        void setNumCirclet(int num_circlet);
        void setNumGoblet(int num_goblet);

        void statusUpdate();
        void cookFood();
        void saveStats();
        void misfortune(bool room);
};
#endif
