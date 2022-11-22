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
    Group players;
    Map gameMap = Map();
    char direction, userDecision;
    string name;
    bool open = true, running = true;
    int userInput;
    double multiplyer = 1.0;

    //gets input for the names of the players
    cout << "Welcome to Dungeon Escape." << endl;
    cout << "Please enter your name:" << endl;
    cin >> name;
    players.addPlayer(Player(name));
    cout << "Enter your first companion:" << endl;
    cin >> name;
    players.addPlayer(Player(name));
    cout << "Enter your second companion:" << endl;
    cin >> name;
    players.addPlayer(Player(name));
    cout << "Enter your thrid companion:" << endl;
    cin >> name;
    players.addPlayer(Player(name));
    cout << "Enter your fourth companion:" << endl;
    cin >> name;
    players.addPlayer(Player(name));

    //intro to merchant 
    cout << endl;
    cout << "Between the 5 of you, you have 100 gold pieces." << endl;
    cout << "You will need to spend the some of your money on the following items:" << endl;
    cout << endl;
    cout << "- INGREDIENTS. To make food, you have to cook raw ingredients." << endl;
    cout << "- COOKWARE. If you want to cook, you have to have cookware first." << endl;
    cout << "- WEAPONS. You'll want at least one weapon per party member to fend off monsters." << endl;
    cout << "- ARMOR. Armor increases the chances of surviving a monster attack." << endl;
    cout << endl;
    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. But beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price..." << endl;

    //running the merchant menu
    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl;
    cout << endl;
    while(open){
        cout << "+-------------+" << endl;
        cout << "| INVENTORY   |" << endl;
        cout << "+-------------+" << endl;
        cout << "| Gold        | " << players.getGold() << endl;
        cout << "| Ingredients | " << players.getIngredients() << " kg" << endl;
        cout << "| Cookware    | P: " << players.getNumPots() << " | F: " << players.getNumPans() << " | C: " << players.getNumCauldrons() << endl;
        cout << "| Weapons     | C: " << players.getNumClubs() << "| S: " << players.getNumSpears() << " | R: " << players.getNumRapiers() << " | B: " << players.getNumBattleAxes() << " | L: " << players.getNumLongSwords() << endl;
        cout << "| Armor       | " << players.getNumArmor() << endl;
        cout << "| Treasures   | R: " << players.getNumRings() << " | N: " << players.getNumNecklace() << " | B: " << players.getNumBraclet() << " | C: " << players.getNumCirclet() << " | G: " << players.getNumGoblet() << endl;
        cout << endl;

        cout << "Choose one of the following:" << endl;
        cout << " 1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << " 2. Cookware: You will need something to cook those ingredients." << endl;
        cout << " 3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << " 4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << " 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << " 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
        cin >> userInput;

        switch (userInput)
        {
        case 1:
            cout << "How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel) " << endl;
            cin >> userInput;
            while (userInput > players.getGold() || userInput%5 != 0){
                cout << "That is not a valid input. How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
                cin >> userInput;
            }
            if (userInput == 0){
                continue;
            }
            else{
                cout << "You want to buy " << userInput << " kg of ingredients for " << (1*multiplyer) * userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    players.setGold(players.getGold() - (1*multiplyer) * userInput);
                    players.setIngredients(players.getIngredients() + userInput);
                }
                cout << endl;
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
            cin >> userDecision;
            while (userDecision != 'y' && userDecision != 'n'){
                cout << "That is not a valid input. Please enter (y/n)." << endl;
                cin >> userDecision;
            }
            if (userDecision == 'y'){
                cout << "Stay safe out there! Goodbye!" << endl;
                open = false;
            }  
            cout << endl;        
            break;
        default:
            cout << "That is not a valid option." << endl;
            cout << endl;
            break;
        }
    }
    open = true;

    while (running){
        //displays what the current map looks like and gets user input to move the party
        gameMap.displayMap();
        cout << "What direction would you like to move (w,a,s,d)." << endl;
        cin >> direction;
        while (!gameMap.move(direction)){
            cout << "You are trying to move outside the bounds of the map (12x12). Please enter a different direction (w,a,s,d)." << endl;
            cin >> direction;
        }

        if (gameMap.isNPCLocation(gameMap.getPlayerRow(), gameMap.getPlayerCol())){
            gameMap.foundNPC(gameMap.getPlayerRow(), gameMap.getPlayerCol());
        }   
    }

    return 0;
}