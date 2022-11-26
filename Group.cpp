// Group.cpp
// CSCI 1300 Fall 2022
// Author: Jeremy Schur and Anthony Radke
// Recitation: 305/221 - Nikhith Sannidhi
#include "Group.h"
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// creates a group
Group::Group()
{
}

// adds a player to the players vector
bool Group::addPlayer(Player p)
{
    players.push_back(p);
}

Player Group::getPlayer(int index)
{
    return players.at(index);
}

void Group::setPlayerFullness(int index, int fullness)
{
    players.at(index).setFullness(fullness);
}

int Group::getSize()
{
    return players.size();
}

void Group::removePlayer(int index)
{
}

// returns the rooms cleared
int Group::getRoomsCleared()
{
    return rooms_cleared;
}

// returns the number of keys
int Group::getNumKeys()
{
    return num_keys;
}

// returns the anger level of the Sorcerer
int Group::getAngerLevel()
{
    return anger_level;
}

// returns the gold
int Group::getGold()
{
    return gold;
}

// returns the ingredients
int Group::getIngredients()
{
    return ingredients;
}

// returns the number of pots
int Group::getNumPots()
{
    return cookware[0];
}

// returns the number of pans
int Group::getNumPans()
{
    return cookware[1];
}

// returns the number of cauldrons
int Group::getNumCauldrons()
{
    return cookware[2];
}

// returns the number of clubs
int Group::getNumClubs()
{
    return weapons[0];
}

// returns the number of weapons
int Group::getNumSpears()
{
    return weapons[1];
}

// returns the number of rapiers
int Group::getNumRapiers()
{
    return weapons[2];
}

// returns the number of battle axes
int Group::getNumBattleAxes()
{
    return weapons[3];
}

// returns the number of long swords
int Group::getNumLongSwords()
{
    return weapons[4];
}

int Group::getNumArmor()
{
    return armor;
}

int Group::getNumRings()
{
    return treasures[0];
}
int Group::getNumNecklace()
{
    return treasures[1];
}
int Group::getNumBraclet()
{
    return treasures[2];
}
int Group::getNumCirclet()
{
    return treasures[3];
}
int Group::getNumGoblet()
{
    return treasures[4];
}
int Group::getTotalWeapons()
{
    return totalWeapons;
}

// sets the number of rooms cleared
void Group::setRoomsCleared(int rooms_cleared_)
{
    rooms_cleared = rooms_cleared_;
}

// sets the number of keys
void Group::setNumKeys(int num_keys_)
{
    num_keys = num_keys_;
}

// sets the anger level of the sorcerer
void Group::setAngerLevel(int anger_level_)
{
    anger_level = anger_level_;
}

// sets the gold
void Group::setGold(int gold_)
{
    gold = gold_;
}

// sets the ingredients
void Group::setIngredients(int ingredients_)
{
    ingredients = ingredients_;
}

// sets the number of pots
void Group::setNumPots(int num_pots)
{
    cookware[0] = num_pots;
}

// sets the number of pans
void Group::setNumPans(int num_pans)
{
    cookware[1] = num_pans;
}

// sets the number of cauldrons
void Group::setNumCauldrons(int num_cauldrons)
{
    cookware[2] = num_cauldrons;
}

// sets the number of clubs
bool Group::setNumClubs(int num_clubs)
{
    if (totalWeapons < 5)
    {
        weapons[0] = num_clubs;
        totalWeapons++;
        return true;
    }
    else
    {
        return false;
    }
}

// sets the number of spears
bool Group::setNumSpears(int num_spears)
{
    if (totalWeapons < 5)
    {
        weapons[1] = num_spears;
        totalWeapons++;
        return true;
    }
    else
    {
        return false;
    }
}

// sets the number of rapiers
bool Group::setNumRapiers(int num_rapiers)
{
    if (totalWeapons < 5)
    {
        weapons[2] = num_rapiers;
        totalWeapons++;
        return true;
    }
    else
    {
        return false;
    }
}

// sets the number of battle axes
bool Group::setNumBattleAxes(int num_battleAxes)
{
    if (totalWeapons < 5)
    {
        weapons[3] = num_battleAxes;
        totalWeapons++;
        return true;
    }
    else
    {
        return false;
    }
}

// sets the number of longswords
bool Group::setNumLongSwords(int num_longSwords)
{
    if (totalWeapons < 5)
    {
        weapons[4] = num_longSwords;
        totalWeapons++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Group::setNumArmor(int num_armor)
{
    if (armor < 5)
    {
        armor++;
        return true;
    }
    else
    {
        return false;
    }
}
void Group::setNumRings(int num_rings)
{
    treasures[0] = num_rings;
}
void Group::setNumNecklace(int num_necklace)
{
    treasures[1] = num_necklace;
}
void Group::setNumBraclet(int num_braclet)
{
    treasures[2] = num_braclet;
}
void Group::setNumCirclet(int num_circlet)
{
    treasures[3] = num_circlet;
}
void Group::setNumGoblet(int num_goblet)
{
    treasures[4] = num_goblet;
}

void Group::statusUpdate()
{
    cout << endl;
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << rooms_cleared << " | Keys: " << num_keys << " | Anger Level: " << anger_level << endl;
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << gold << endl;
    cout << "| Ingredients | " << ingredients << " kg" << endl;
    cout << "| Cookware    | P: " << cookware[0] << " | F: " << cookware[1] << " | C: " << cookware[2] << endl;
    cout << "| Weapons     | C: " << weapons[0] << "| S: " << weapons[1] << " | R: " << weapons[2] << " | B: " << weapons[3] << " | L: " << weapons[4] << endl;
    cout << "| Armor       | " << armor << endl;
    cout << "| Treasures   | R: " << treasures[0] << " | N: " << treasures[1] << " | B: " << treasures[2] << " | C: " << treasures[3] << " | G: " << treasures[4] << endl;
    cout << "+-------------+" << endl;
    cout << "| PARTY       |" << endl;
    cout << "+-------------+" << endl;
    cout << "| " << players.at(0).getName() << " | Fullness: " << players.at(0).getFullness() << endl;
    cout << "| " << players.at(1).getName() << " | Fullness: " << players.at(1).getFullness() << endl;
    cout << "| " << players.at(2).getName() << " | Fullness: " << players.at(2).getFullness() << endl;
    cout << "| " << players.at(3).getName() << " | Fullness: " << players.at(3).getFullness() << endl;
    cout << "| " << players.at(4).getName() << " | Fullness: " << players.at(4).getFullness() << endl;
    cout << "+-------------+" << endl;
    cout << endl;
}

void Group::cookFood()
{
    int userInput;

    cout << "What cookware would you like to use? ";
    cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
    cout << endl;
    cout << "Choose one of the following:" << endl;
    cout << " 1. (25%) Ceramic Pot" << endl;
    cout << " 2. (10%) Frying Pan" << endl;
    cout << " 3. ( 2%) Cauldron" << endl;
    cout << " 4. Cancel" << endl;
    cin >> userInput;
    while (userInput < 1 || userInput > 4)
    {
        cout << "That is not a valid input. Choose one of the following:" << endl;
        cout << " 1. (25%) Ceramic Pot" << endl;
        cout << " 2. (10%) Frying Pan" << endl;
        cout << " 3. ( 2%) Cauldron" << endl;
        cout << " 4. Cancel" << endl;
        cin >> userInput;
    }
    if (userInput == 1)
    {
        if (cookware[0] == 0)
        {
            cout << "You do not have any ceramic pots to cook with." << endl;
            cout << endl;
        }
        else
        {
            cout << "How much ingredients would you like to cook? (Enter a positive multiple of 5)" << endl;
            cin >> userInput;
            while ((userInput % 5) != 0 || userInput > ingredients || userInput < 0)
            {
                cout << "That is not a valid input. Enter a postive multiple of 5 or reduce your ingredients." << endl;
                cin >> userInput;
            }
            ingredients -= userInput;
            if (rand() % 4 == 0)
            {
                cout << "Whoops. It looks like your Ceramic Pot has broken." << endl;
                cout << endl;
                cookware[0] -= 1;
            }
            else
            {
                cout << "Your meal was successfully cooked!" << endl;
                cout << endl;
                for (int i = 0; i < players.size(); i++)
                {
                    players.at(i).setFullness(players.at(i).getFullness() + userInput/5);
                }
            }
        }
    }
    else if (userInput == 2)
    {
        if (cookware[1] == 0)
        {
            cout << "You do not have any frying pans to cook with." << endl;
            cout << endl;
        }
        else
        {
            cout << "How much ingredients would you like to cook? (Enter a positive multiple of 5)" << endl;
            cin >> userInput;
            while ((userInput % 5) != 0 || userInput > ingredients || userInput < 0)
            {
                cout << "That is not a valid input. Enter a postive multiple of 5 or reduce/increase your ingredients." << endl;
                cin >> userInput;
            }
            ingredients -= userInput;
            if (rand() % 10 == 0)
            {
                cout << "Whoops. It looks like your Ceramic Pot has broken." << endl;
                cout << endl;
                cookware[1] -= 1;
            }
            else
            {
                cout << "Your meal was successfully cooked!" << endl;
                cout << endl;
                for (int i = 0; i < players.size(); i++)
                {
                    players.at(i).setFullness(players.at(i).getFullness() + userInput/5);
                }
            }
        }
    }
    else if (userInput == 3)
    {
        if (cookware[2] == 0)
        {
            cout << "You do not have any cauldrons to cook with." << endl;
            cout << endl;
        }
        else
        {
            cout << "How much ingredients would you like to cook? (Enter a positive multiple of 5)" << endl;
            cin >> userInput;
            while ((userInput % 5) != 0 || userInput > ingredients || userInput < 0)
            {
                cout << "That is not a valid input. Enter a postive multiple of 5 or reduce your ingredients." << endl;
                cin >> userInput;
            }
            ingredients -= userInput;
            if (rand() % 50 == 0)
            {
                cout << "Whoops. It looks like your Cauldron has broken." << endl;
                cout << endl;
                cookware[2] -= 1;
            }
            else
            {
                cout << "Your meal was successfully cooked!" << endl;
                cout << endl;
                for (int i = 0; i < players.size(); i++)
                {
                    players.at(i).setFullness(players.at(i).getFullness() + userInput/5);
                }
            }
        }
    }
}
