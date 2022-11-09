#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class Item
{
    private:
        string itemName;
        int cost, dmg;
        
    public:
        Item(string name);
        string getName();
        int getCost();
        int getDMG();
        void setCost(int cost_);
        void setDMG(int dmg_);
    
};
#endif

