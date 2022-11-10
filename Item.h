//Item.h
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class Item
{
    //private members
    private:
        string itemName;
        int cost, dmg;
    // public members
    public:
        Item(string name);

        //getters
        string getName();
        int getCost();
        int getDMG();

        // setters
        void setCost(int cost_);
        void setDMG(int dmg_);
    
};
#endif

