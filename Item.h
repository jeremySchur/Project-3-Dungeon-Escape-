#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class Item
{
    private:
        string itemName;
        int cost;
        int count = 0;
        
    public:
        Item(string name);
        string getName();
        int getCost();
    
};
#endif

