#include <iostream>
#include "Item.h"
using namespace std;

Item::Item(string name){
    itemName = name;

    //set cost to different values depending on the name of the item entered 

}

//returns the item name
string Item::getName(){
    return itemName;
}

//returns the item cost
int Item::getCost(){
    return cost;
}