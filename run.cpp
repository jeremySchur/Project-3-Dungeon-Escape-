//run.cpp
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <vector>
#include <ctime>
#include "Group.h"
#include "Player.h"
#include "Merchant.h"
#include "Item.h"
#include "Map.h"
#include "Monsters.h"
using namespace std;

//main for the entire game run
int main(){
    srand(time(0));
    Group players;
    Map gameMap = Map();
    Monsters monsters("monsters.txt");
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
    cout << endl;

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
                    players.setGold(players.getGold() - ((1*multiplyer) * userInput));
                    players.setIngredients(players.getIngredients() + userInput);
                }
                cout << endl;
            }
            break;
        case 2:
            cout << "I have a several types of cookware, which one would you like?" << endl;
            cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
            cout << endl;
            cout << "Choose one of the following:" << endl;
            cout << " 1. (25%) Ceramic Pot [2 Gold]" << endl;
            cout << " 2. (10%) Frying Pan [10 Gold]" << endl;
            cout << " 3. ( 2%) Cauldron [20 Gold]" << endl;
            cout << " 4. Cancel" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 4){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << endl;
                cout << " 1. (25%) Ceramic Pot [2 Gold]" << endl;
                cout << " 2. (10%) Frying Pan [10 Gold]" << endl;
                cout << " 3. ( 2%) Cauldron [20 Gold]" << endl;
                cout << " 4. Cancel" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while ((2*multiplyer) * userInput > players.getGold() || userInput < 0){
                    cout << "You are trying to buy an invalid amount. How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to buy " << userInput << " Ceramic Pot(s) for " << (2*multiplyer) * userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    cout << endl;
                    players.setNumPots(players.getNumPots() + userInput);
                    players.setGold(players.getGold() - ((2*multiplyer) * userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 2){
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while ((10*multiplyer) * userInput > players.getGold() || userInput < 0){
                    cout << "You are trying to buy an invalid amount. How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to buy " << userInput << " Frying Pan(s) for " << (10*multiplyer) * userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    cout << endl;
                    players.setNumPans(players.getNumPans() + userInput);
                    players.setGold(players.getGold() - ((10*multiplyer) * userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 3){
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while ((20*multiplyer) * userInput > players.getGold() || userInput < 0){
                    cout << "You are trying to buy an invalid amount. How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to buy " << userInput << " Cauldron(s) for " << (20*multiplyer) * userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    cout << endl;
                    players.setNumCauldrons(players.getNumCauldrons() + userInput);
                    players.setGold(players.getGold() - ((20*multiplyer) * userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 4){
                cout << "What can I get for you?" << endl;
                cout << endl;
            }
            break;
        case 3:
            cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
            cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
            cout << endl;
            cout << "Choose one of the following:" << endl;
            cout << " 1. Stone Club [2 Gold]" << endl;
            cout << " 2. Iron Spear [2 Gold]" << endl;
            cout << " 3. (+1) Mythril Rapier [5 Gold]" << endl;
            cout << " 4. (+2) Flaming Battle-Axe [15 Gold]" << endl;
            cout << " 5. (+3) Vorpal Longsword [50 Gold]" << endl;
            cout << " 6. Cancel" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 6){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "Choose one of the following:" << endl;
                cout << endl;
                cout << " 1. Stone Club [2 Gold]" << endl;
                cout << " 2. Iron Spear [2 Gold]" << endl;
                cout << " 3. (+1) Mythril Rapier [5 Gold]" << endl;
                cout << " 4. (+2) Flaming Battle-Axe [15 Gold]" << endl;
                cout << " 5. (+3) Vorpal Longsword [50 Gold]" << endl;
                cout << " 6. Cancel" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while ((2*multiplyer) * userInput > players.getGold() || userInput < 0){
                    cout << "You are trying to buy an invalid amount. How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to buy " << userInput << " Stone Club(s) for " << (2*multiplyer) * userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    cout << endl;
                    players.setNumClubs(players.getNumClubs() + userInput);
                    players.setGold(players.getGold() - ((2*multiplyer) * userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 2){
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while ((2*multiplyer) * userInput > players.getGold() || userInput < 0){
                    cout << "You are trying to buy an invalid amount. How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to buy " << userInput << " Iron Spear(s) for " << (2*multiplyer) * userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    cout << endl;
                    players.setNumSpears(players.getNumSpears() + userInput);
                    players.setGold(players.getGold() - ((2*multiplyer) * userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 3){
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while ((5*multiplyer) * userInput > players.getGold() || userInput < 0){
                    cout << "You are trying to buy an invalid amount. How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to buy " << userInput << " (+1) Mythril Rapier(s) for " << (5*multiplyer) * userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    cout << endl;
                    players.setNumRapiers(players.getNumRapiers() + userInput);
                    players.setGold(players.getGold() - ((5*multiplyer) * userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 4){
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while ((15*multiplyer) * userInput > players.getGold() || userInput < 0){
                    cout << "You are trying to buy an invalid amount. How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to buy " << userInput << " (+2) Flaming Battle-Axe(s) for " << (15*multiplyer) * userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    cout << endl;
                    players.setNumBattleAxes(players.getNumBattleAxes() + userInput);
                    players.setGold(players.getGold() - ((15*multiplyer) * userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 5){
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while ((50*multiplyer) * userInput > players.getGold() || userInput < 0){
                    cout << "You are trying to buy an invalid amount. How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to buy " << userInput << " (+3) Vorpal Longsword(s) for " << (50*multiplyer) * userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    cout << endl;
                    players.setNumLongSwords(players.getNumLongSwords() + userInput);
                    players.setGold(players.getGold() - ((50*multiplyer) * userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 6){
                cout << "What can I get for you?" << endl;
                cout << endl;
            }
            break;
        case 4:
            cout << "How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> userInput;
            while ((5*multiplyer) * userInput > players.getGold() || userInput < 0){
                cout << "You are trying to buy an invalid amount. How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
            }
            cout << "You want to buy " << userInput << " suit(s) of armor for " << (5*multiplyer) * userInput << " Gold? (y/n)" << endl;
            cin >> userDecision;
            while (userDecision != 'y' && userDecision != 'n'){
                cout << "That is not a valid input. Please enter (y/n)." << endl;
                cin >> userDecision;
            }
            if (userDecision == 'y'){
                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                cout << endl;
                players.setNumArmor(players.getNumArmor() + userInput);
                players.setGold(players.getGold() - ((5*multiplyer) * userInput));
            }
            else{
                cout << "What can I get for you?" << endl;
                cout << endl;
            }
            break;
        case 5:
            cout << "I am more than happy to take some treasure off your hands. What can I buy from you?" << endl;
            cout << endl;
            cout << "Choose one of the following:" << endl;
            cout << " 1. Silver Ring" << endl;
            cout << " 2. Ruby Necklace" << endl;
            cout << " 3. Emerald Braclet" << endl;
            cout << " 4. Diamond Circlet" << endl;
            cout << " 5. Gem-Encrusted Diamond" << endl;
            cout << " 6. Cancel" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 6){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << " 1. Silver Ring" << endl;
                cout << " 2. Ruby Necklace" << endl;
                cout << " 3. Emerald Braclet" << endl;
                cout << " 4. Diamond Circlet" << endl;
                cout << " 5. Gem-Encrusted Diamond" << endl;
                cout << " 6. Cancel" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
                cout << "How many can I buy from you? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while (userInput > players.getNumRings() || userInput < 0){
                    cout << "You are trying to sell an invalid amount. How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to sell " << userInput << " Silver Ring(s) for " << 10*userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What can I get for you?" << endl;
                    cout << endl;
                    players.setNumRings(players.getNumRings() - userInput);
                    players.setGold(players.getGold() + (10*userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 2){
                cout << "How many can I buy from you? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while (userInput > players.getNumNecklace() || userInput < 0){
                    cout << "You are trying to sell an invalid amount. How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to sell " << userInput << " Ruby Necklace(s) for " << 20*userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What can I get for you?" << endl;
                    cout << endl;
                    players.setNumNecklace(players.getNumNecklace() - userInput);
                    players.setGold(players.getGold() + (20*userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 3){
                cout << "How many can I buy from you? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while (userInput > players.getNumBraclet() || userInput < 0){
                    cout << "You are trying to sell an invalid amount. How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to sell " << userInput << " Emerald Braclet(s) for " << 30*userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What can I get for you?" << endl;
                    cout << endl;
                    players.setNumBraclet(players.getNumBraclet() - userInput);
                    players.setGold(players.getGold() + (30*userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 4){
                cout << "How many can I buy from you? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while (userInput > players.getNumCirclet() || userInput < 0){
                    cout << "You are trying to sell an invalid amount. How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to sell " << userInput << " Diamond Circlet(s) for " << 40*userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What can I get for you?" << endl;
                    cout << endl;
                    players.setNumCirclet(players.getNumCirclet() - userInput);
                    players.setGold(players.getGold() + (40*userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 5){
                cout << "How many can I buy from you? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> userInput;
                while (userInput > players.getNumGoblet() || userInput < 0){
                    cout << "You are trying to sell an invalid amount. How many would you like to sell? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> userInput;
                }
                cout << "You want to sell " << userInput << " Gen-Encrusted Goblet(s) for " << 50*userInput << " Gold? (y/n)" << endl;
                cin >> userDecision;
                while (userDecision != 'y' && userDecision != 'n'){
                    cout << "That is not a valid input. Please enter (y/n)." << endl;
                    cin >> userDecision;
                }
                if (userDecision == 'y'){
                    cout << "Thank you for your patronage! What can I get for you?" << endl;
                    cout << endl;
                    players.setNumGoblet(players.getNumGoblet() - userInput);
                    players.setGold(players.getGold() + (50*userInput));
                }
                else{
                    cout << "What can I get for you?" << endl;
                    cout << endl;
                }
            }
            else if (userInput == 6){
                cout << "What can I get for you?" << endl;
                cout << endl;
            }
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
            else{
                cout << "What can I get for you?" << endl;
                cout << endl;
            } 
            cout << endl;        
            break;
        default:
            cout << "That is not a valid option." << endl;
            cout << endl;
            break;
        }
    }

    while (running){
        if (gameMap.isFreeSpace(gameMap.getPlayerRow(), gameMap.getPlayerCol())){
            cout << "+-------------+" << endl;
            cout << "| STATUS      |" << endl;
            cout << "+-------------+" << endl;
            cout << "| Rooms Cleared: " << players.getRoomsCleared() << " | Keys: " << players.getNumKeys() << " | Anger Level: " << players.getAngerLevel() << endl;
            cout << "+-------------+" << endl;
            cout << "| INVENTORY   |" << endl;
            cout << "+-------------+" << endl;
            cout << "| Gold        | " << players.getGold() << endl;
            cout << "| Ingredients | " << players.getIngredients() << " kg" << endl;
            cout << "| Cookware    | P: " << players.getNumPots() << " | F: " << players.getNumPans() << " | C: " << players.getNumCauldrons() << endl;
            cout << "| Weapons     | C: " << players.getNumClubs() << "| S: " << players.getNumSpears() << " | R: " << players.getNumRapiers() << " | B: " << players.getNumBattleAxes() << " | L: " << players.getNumLongSwords() << endl;
            cout << "| Armor       | " << players.getNumArmor() << endl;
            cout << "| Treasures   | R: " << players.getNumRings() << " | N: " << players.getNumNecklace() << " | B: " << players.getNumBraclet() << " | C: " << players.getNumCirclet() << " | G: " << players.getNumGoblet() << endl;
            cout << "+-------------+" << endl;
            cout << "| PARTY       |" << endl;
            cout << "+-------------+" << endl;
            cout << "| " << players.getPlayer(0).getName() << " | Fullness: " << players.getPlayer(0).getFullness() << endl;
            cout << "| " << players.getPlayer(1).getName() << " | Fullness: " << players.getPlayer(1).getFullness() << endl;
            cout << "| " << players.getPlayer(2).getName() << " | Fullness: " << players.getPlayer(2).getFullness() << endl;
            cout << "| " << players.getPlayer(3).getName() << " | Fullness: " << players.getPlayer(3).getFullness() << endl;
            cout << "| " << players.getPlayer(4).getName() << " | Fullness: " << players.getPlayer(4).getFullness() << endl;
            cout << "+-------------+" << endl;
            cout << endl;
            gameMap.displayMap();

            cout << "Select one:" << endl;
            cout << "1. Move" << endl;
            cout << "2. Investigate" << endl;
            cout << "3. Pick a Fight" << endl;
            cout << "4. Cook and Eat" << endl;
            cout << "5. Give up" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 5){
                cout << "That is not a valid input. Select one:" << endl;
                cout << "1. Move" << endl;
                cout << "2. Investigate" << endl;
                cout << "3. Pick a Fight" << endl;
                cout << "4. Cook and Eat" << endl;
                cout << "5. Give up" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
                cout << "What direction would you like to move (w,a,s,d)." << endl;
                cin >> direction;
                while (!gameMap.move(direction)){
                    cout << "You are trying to move outside the bounds of the map (12x12). Please enter a different direction (w,a,s,d)." << endl;
                    cin >> direction;
                }
                for (int i = 0; i < players.getSize(); i++){
                    if (rand() % 5 == 0){
                        players.setPlayerFullness(i, players.getPlayer(i).getFullness() - 1);
                    }
                }
            }
            else if (userInput == 2){

            }
            else if (userInput == 3){
                if (monsters.fightMonster(players)){
                    players.setGold(players.getGold() + 10*(players.getRoomsCleared()+1));
                    players.setIngredients(players.getIngredients() + 5*(players.getRoomsCleared()+1));
                    if (rand()%10 == 0){
                        players.setNumKeys(players.getNumKeys()+1);
                    }
                }
                else{
                    players.setGold(int(players.getGold()*.75));
                    players.setIngredients(players.getIngredients() - rand()%31);
                    for (int i = 1; i < players.getNumArmor(); i++){
                        if (rand()%20 == 0){
                            cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl;
                            players.setNumArmor(players.getNumArmor()-1);
                            players.removePlayer(i);
                        }
                    }
                    for (int i = players.getNumArmor(); i < players.getSize(); i++){
                        if (rand()%10 == 0){
                            cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl;
                            players.removePlayer(i);
                        }
                    }
                }
            }
            else if (userInput == 4){
                cout << "What cookware would you like to use? ";
                cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
                cout << endl;
                cout << "Choose one of the following:" << endl;
                cout << " 1. (25%) Ceramic Pot" << endl;
                cout << " 2. (10%) Frying Pan" << endl;
                cout << " 3. ( 2%) Cauldron" << endl;
                cout << " 4. Cancel" << endl;
                cin >> userInput;
                while (userInput < 1 || userInput > 4){
                    cout << "That is not a valid input. Choose one of the following:" << endl;
                    cout << " 1. (25%) Ceramic Pot" << endl;
                    cout << " 2. (10%) Frying Pan" << endl;
                    cout << " 3. ( 2%) Cauldron" << endl;
                    cout << " 4. Cancel" << endl;
                    cin >> userInput;
                }
                if (userInput == 1){
                    if (players.getNumPots() == 0){
                        cout << "You do not have any ceramic pots to cook with." << endl;
                        cout << endl;
                    }
                    else{
                        cout << "How much ingredients would you like to cook? (Enter a positive multiple of 5)" << endl;
                        cin >> userInput;
                        while ((userInput%5) != 0 || userInput > players.getIngredients() || userInput < 0){
                            cout << "That is not a valid input. Enter a postive multiple of 5 or reduce/increase your ingredients." << endl;
                            cin >> userInput;
                        }
                        players.setIngredients(players.getIngredients() - userInput);
                        if (rand()%4 == 0){
                            cout << "Whoops. It looks like your Ceramic Pot has broken." << endl;
                            cout << endl;
                            players.setNumPots(players.getNumPots() - 1);
                        }
                        else{
                            cout << "Your meal was successfully cooked!" << endl;
                            cout << endl;
                            for (int i = 0; i < players.getSize(); i++){
                                players.setPlayerFullness(i, players.getPlayer(i).getFullness() + userInput/5);
                            }
                        }
                    }
                }
                else if (userInput == 2){
                    if (players.getNumPans() == 0){
                        cout << "You do not have any frying pans to cook with." << endl;
                        cout << endl;
                    }
                    else{
                        cout << "How much ingredients would you like to cook? (Enter a positive multiple of 5)" << endl;
                        cin >> userInput;
                        while ((userInput%5) != 0 || userInput > players.getIngredients() || userInput < 0){
                            cout << "That is not a valid input. Enter a postive multiple of 5 or reduce/increase your ingredients." << endl;
                            cin >> userInput;
                        }
                        players.setIngredients(players.getIngredients() - userInput);
                        if (rand()%10 == 0){
                            cout << "Whoops. It looks like your Ceramic Pot has broken." << endl;
                            cout << endl;
                            players.setNumPans(players.getNumPans() - 1);
                        }
                        else{
                            cout << "Your meal was successfully cooked!" << endl;
                            cout << endl;
                            for (int i = 0; i < players.getSize(); i++){
                                players.setPlayerFullness(i, players.getPlayer(i).getFullness() + userInput/5);
                            }
                        }
                    }  
                }
                else if (userInput == 3){
                    if (players.getNumPots() == 0){
                        cout << "You do not have any cauldrons to cook with." << endl;
                        cout << endl;
                    }
                    else{
                        cout << "How much ingredients would you like to cook? (Enter a positive multiple of 5)" << endl;
                        cin >> userInput;
                        while ((userInput%5) != 0 || userInput > players.getIngredients() || userInput < 0){
                            cout << "That is not a valid input. Enter a postive multiple of 5 or reduce/increase your ingredients." << endl;
                            cin >> userInput;
                        }
                        players.setIngredients(players.getIngredients() - userInput);
                        if (rand()%50 == 0){
                            cout << "Whoops. It looks like your Cauldron has broken." << endl;
                            cout << endl;
                            players.setNumCauldrons(players.getNumCauldrons() - 1);
                        }
                        else{
                            cout << "Your meal was successfully cooked!" << endl;
                            cout << endl;
                            for (int i = 0; i < players.getSize(); i++){
                                players.setPlayerFullness(i, players.getPlayer(i).getFullness() + userInput/5);
                            }
                        }
                    }
                }
                else if (userInput == 4){
                    cout << endl;
                }
            }
            else if (userInput == 5){
                cout << "Game over. You gave up." << endl;
                running = false;
            }
        }
        else if (){

        }
    }

    return 0;
}