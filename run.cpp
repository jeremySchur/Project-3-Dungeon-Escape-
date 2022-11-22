//run.cpp
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <vector>
#include "Group.h"
#include "Player.h"
#include "Merchant.h"
#include "Item.h"
#include "Map.h"
using namespace std;

//main for the entire game run
int main(){
    Map gameMap = Map();
    char direction;

    while (true){
        gameMap.displayMap();
        cout << "What direction would you like to move (w,a,s,d)." << endl;
        cin >> direction;
        while (!gameMap.move(direction)){
            cout << "You are trying to move outside the bounds of the map (12x12). Please enter a different direction (w,a,s,d)." << endl;
            cin >> direction;
        }
    }

    return 0;
}