//Item.cpp
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <vector>
#include "Item.h"
using namespace std;

Item::Item(string name){
    itemName = name;

    //set cost and dmg to different values depending on the name of the item entered 

}

//returns the item name
string Item::getName(){
    return itemName;
}

//returns the item cost
int Item::getCost(){
    return cost;
}

//returns the damage of the item, 0 if it is not a weapon (implemented in the constructor)
int Item::getDMG(){
    return dmg;
}

//sets the cost of an item
void Item::setCost(int cost_){
    cost = cost_;
}

//sets the damage of an item
void Item::setDMG(int dmg_){
    dmg = dmg_;
}