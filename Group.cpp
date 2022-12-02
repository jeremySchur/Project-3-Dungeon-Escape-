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

//returns the player at index
Player Group::getPlayer(int index)
{
    return players.at(index);
}

//gets the size of the players vector
int Group::getSize()
{
    return players.size();
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

//sets the players fullness at index to fullness
void Group::setPlayerFullness(int index, int fullness)
{
    players.at(index).setFullness(fullness);
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

// sets the number of clubs if there is room available
bool Group::setNumClubs(int num_clubs)
{
    if (totalWeapons < players.size())
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

// sets the number of spears if there is room available 
bool Group::setNumSpears(int num_spears)
{
    if (totalWeapons < players.size())
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

// sets the number of rapiers if there is room available 
bool Group::setNumRapiers(int num_rapiers)
{
    if (totalWeapons < players.size())
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

// sets the number of battle axes if there is room available 
bool Group::setNumBattleAxes(int num_battleAxes)
{
    if (totalWeapons < players.size())
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

// sets the number of longswords if there is room available
bool Group::setNumLongSwords(int num_longSwords)
{
    if (totalWeapons < players.size())
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

//sets the number of armor if there is room availble
bool Group::setNumArmor(int num_armor)
{
    if (armor < players.size())
    {
        armor = num_armor;
        return true;
    }
    else
    {
        return false;
    }
}
//sets the number of rings
void Group::setNumRings(int num_rings)
{
    treasures[0] = num_rings;
}
//sets the number of necklaces 
void Group::setNumNecklace(int num_necklace)
{
    treasures[1] = num_necklace;
}
//sets the number of braclets
void Group::setNumBraclet(int num_braclet)
{
    treasures[2] = num_braclet;
}
//sets the number of circlets 
void Group::setNumCirclet(int num_circlet)
{
    treasures[3] = num_circlet;
}
//sets the number of goblets
void Group::setNumGoblet(int num_goblet)
{
    treasures[4] = num_goblet;
}

// adds a player to the players vector
void Group::addPlayer(Player p)
{
    players.push_back(p);
}

//removes a player from the players vector and decreases the max count of armor and weapons
void Group::removePlayer(int index)
{
    players.erase(players.begin() + index);
    if (armor > players.size()){
        armor--;
    }
    if (totalWeapons > players.size()){
        if (weapons[0] > 0){
            weapons[0]--;
        }
        else if (weapons[1] > 0){
            weapons[1]--;
        }
        else if (weapons[2] > 0){
            weapons[2]--;
        }
        else if (weapons[3] > 0){
            weapons[3]--;
        }
        else if (weapons[4] > 0){
            weapons[4]--;
        }
    }
}

//prints the status update for the group
void Group::statusUpdate()
{   // in game user UI display
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
    for (int i = 0; i < players.size(); i++){
        cout << "| " << players.at(i).getName() << " | Fullness: " << players.at(i).getFullness() << endl;
    }
    cout << "+-------------+" << endl;
    cout << endl;
}

//runs the food cooking process if that option is selected
void Group::cookFood()
{
    int userInput; 
    // in game user UI display
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
        if (cookware[0] == 0) // if no pots
        {
            cout << "You do not have any ceramic pots to cook with." << endl;
            cout << endl;
        }
        else // ask ingredients
        {
            cout << "How much ingredients would you like to cook? (Enter a positive multiple of 5)" << endl;
            cin >> userInput;
            while ((userInput % 5) != 0 || userInput > ingredients || userInput < 0)
            {
                cout << "That is not a valid input. Enter a postive multiple of 5 or reduce your ingredients." << endl;
                cin >> userInput;
            }
            ingredients -= userInput;
            if (rand() % 4 == 0) // cermaic pot break
            {
                cout << "Whoops. It looks like your Ceramic Pot has broken." << endl;
                cout << endl;
                cookware[0] -= 1;
            }
            else // succesful cook
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
        if (cookware[1] == 0) // if no pans
        {
            cout << "You do not have any frying pans to cook with." << endl;
            cout << endl;
        }
        else // ask for ingredients
        {
            cout << "How much ingredients would you like to cook? (Enter a positive multiple of 5)" << endl;
            cin >> userInput;
            while ((userInput % 5) != 0 || userInput > ingredients || userInput < 0)
            {
                cout << "That is not a valid input. Enter a postive multiple of 5 or reduce/increase your ingredients." << endl;
                cin >> userInput;
            }
            ingredients -= userInput;
            if (rand() % 10 == 0) // cermaic pot break
            {
                cout << "Whoops. It looks like your Ceramic Pot has broken." << endl;
                cout << endl;
                cookware[1] -= 1;
            }
            else // succesful cook
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
        if (cookware[2] == 0) // check cookware
        {
            cout << "You do not have any cauldrons to cook with." << endl; 
            cout << endl;
        }
        else
        {
            cout << "How much ingredients would you like to cook? (Enter a positive multiple of 5)" << endl; // ask ingredidents
            cin >> userInput;
            while ((userInput % 5) != 0 || userInput > ingredients || userInput < 0)
            {
                cout << "That is not a valid input. Enter a postive multiple of 5 or reduce your ingredients." << endl;
                cin >> userInput;
            }
            ingredients -= userInput;
            if (rand() % 50 == 0) // cauldron break
            {
                cout << "Whoops. It looks like your Cauldron has broken." << endl;
                cout << endl;
                cookware[2] -= 1;
            }
            else // successful cook
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

//saves the final stats for the current game in a file results.txt
void Group::saveStats(){ 
    ofstream file("results.txt");
    file << endl;
    file << "+-------------+" << endl;
    file << "| STATUS      |" << endl;
    file << "+-------------+" << endl;
    file << "| Rooms Cleared: " << rooms_cleared << " | Keys: " << num_keys << " | Anger Level: " << anger_level << endl;
    file << "+-------------+" << endl;
    file << "| INVENTORY   |" << endl;
    file << "+-------------+" << endl;
    file << "| Gold        | " << gold << endl;
    file << "| Ingredients | " << ingredients << " kg" << endl;
    file << "| Cookware    | P: " << cookware[0] << " | F: " << cookware[1] << " | C: " << cookware[2] << endl;
    file << "| Weapons     | C: " << weapons[0] << "| S: " << weapons[1] << " | R: " << weapons[2] << " | B: " << weapons[3] << " | L: " << weapons[4] << endl;
    file << "| Armor       | " << armor << endl;
    file << "| Treasures   | R: " << treasures[0] << " | N: " << treasures[1] << " | B: " << treasures[2] << " | C: " << treasures[3] << " | G: " << treasures[4] << endl;
    file << "+-------------+" << endl;
    file << "| PARTY       |" << endl;
    file << "+-------------+" << endl;
    for (int i = 0; i < players.size(); i++){
        file << "| " << players.at(i).getName() << " | Fullness: " << players.at(i).getFullness() << endl;
    }
    file << "+-------------+" << endl;
    file << endl;
    file.close();
}

//runs the misfortunes when one occurs
void Group::misfortune(bool room){
    srand(time(0));
    int random;
    if (room){
        if(rand()%10 == 0 || rand()%10 == 0 || rand()%10 == 0){
            cout << endl;
            cout << "OH NO! Your team was robbed by dungeon bandits." << endl;
            random = rand()%5;
            if (random == 0){
                if(ingredients > 10){
                    cout << "You lost 10 kg of ingredients" << endl;
                    cout << endl;
                    ingredients -= 10;
                    
                }
                else{
                    cout << "You had nothing of interest for the bandit to steal." << endl;
                    cout << endl;
                }
            }
            if (random == 1){
                if (armor > 0){
                    cout << "You lost 1 armor." << endl;
                    cout << endl;
                    armor--;
                }
                else{
                    cout << "You had nothing of interest for the bandit to steal." << endl;
                    cout << endl;
                }
            }
            if (random == 2){
                if (cookware[0] > 0){
                    cout << "You lost 1 Ceramic Pot." << endl;
                    cout << endl;
                    cookware[0]--;
                }
                else{
                    cout << "You had nothing of interest for the bandit to steal." << endl;
                    cout << endl;
                }
            }
            if (random == 3){
                if (cookware[1] > 0){
                    cout << "You lost 1 Frying Pan." << endl;
                    cout << endl;
                    cookware[1]--;
                }
                else{
                    cout << "You had nothing of interest for the bandit to steal." << endl;
                    cout << endl;
                }
            }
            if (random == 4){
                if (cookware[2] > 0){
                    cout << "You lost 1 Cauldron." << endl;
                    cout << endl;
                    cookware[2]--;
                }
                else{
                    cout << "You had nothing of interest for the bandit to steal." << endl;
                    cout << endl;
                }
            }
        }
        else if (rand()%10 == 0){
            random = rand()%5;
            if (random == 0){
                if (weapons[0] > 0){
                    cout << "OH NO! Your Club broke." << endl;
                    weapons[0]--;
                    cout << endl;
                }
            }
            if (random == 1){
                if(weapons[1] > 0){
                    cout << "OH NO! Your Spear broke." << endl;
                    weapons[1]--;
                    cout << endl;
                }
            }
            if (random == 2){
                if (weapons[2] > 0){
                    cout << "OH NO! Your +1 Rapier broke." << endl;
                    weapons[2]--;
                    cout << endl;
                }
            }
            if (random == 3){
                if (weapons[3] > 0){
                    cout << "OH NO! Your +2 Battle Axe broke." << endl;
                    weapons[3]--;
                    cout << endl;
                }
            }
            if (random == 4){
                if (weapons[4] > 0){
                    cout << "OH NO! Your +3 Longsword broke." << endl;
                    weapons[4]--;
                    cout << endl;
                }
            }
        }
        else if(rand()%10 == 0 || rand()%10 == 0 || rand()%10 == 0){
            random = rand()%players.size();
            cout << "OH NO! " << players.at(random).getName() << " has gotten food poisoning. Lose 10 points of hunger!" << endl;
            cout << endl;
            players.at(random).setFullness(players.at(random).getFullness() - 10);
        }
        else if (rand()%10 == 0 || rand()%10 == 0 || rand()%10 == 0){
            random = (rand()%(players.size()-1)) + 1;
            cout << "OH NO! Your teammate " << players.at(random).getName() << " is trapped in the previous room and is unable to get through. You must continue without them." << endl;
            cout << endl;
            removePlayer(random);
        }
    }
    else{
        if(rand()%10 == 0 || rand()%10 == 0 || rand()%10 == 0){
            cout << endl;
            cout << "OH NO! Your team was robbed by dungeon bandits." << endl;
            random = rand()%5;
            if (random == 0){
                if(ingredients > 10){
                    cout << "You lost 10 kg of ingredients" << endl;
                    cout << endl;
                    ingredients -= 10;
                    
                }
                else{
                    cout << "You had nothing of interest for the bandit to steal." << endl;
                    cout << endl;
                }
            }
            if (random == 1){
                if (armor > 0){
                    cout << "You lost 1 armor." << endl;
                    armor--;
                    cout << endl;
                }
                else{
                    cout << "You had nothing of interest for the bandit to steal." << endl;
                    cout << endl;
                }
            }
            if (random == 2){
                if (cookware[0] > 0){
                    cout << "You lost 1 Ceramic Pot." << endl;
                    cookware[0]--;
                    cout << endl;
                }
                else{
                    cout << "You had nothing of interest for the bandit to steal." << endl;
                    cout << endl;
                }
            }
            if (random == 3){
                if (cookware[1] > 0){
                    cout << "You lost 1 Frying Pan." << endl;
                    cookware[1]--;
                    cout << endl;
                }
                else{
                    cout << "You had nothing of interest for the bandit to steal." << endl;
                    cout << endl;
                }
            }
            if (random == 4){
                if (cookware[2] > 0){
                    cout << "You lost 1 Cauldron." << endl;
                    cookware[2]--;
                    cout << endl;
                }
                else{
                    cout << "You had nothing of interest for the bandit to steal." << endl;
                    cout << endl;
                }
            }
        }
        else if (rand()%10 == 0){
            random = rand()%5;
            if (random == 0){
                if (weapons[0] > 0){
                    cout << "OH NO! Your Club broke." << endl;
                    weapons[0]--;
                    cout << endl;
                }
            }
            if (random == 1){
                if(weapons[1] > 0){
                    cout << "OH NO! Your Spear broke." << endl;
                    weapons[1]--;
                    cout << endl;
                }
            }
            if (random == 2){
                if (weapons[2] > 0){
                    cout << "OH NO! Your +1 Rapier broke." << endl;
                    weapons[2]--;
                    cout << endl;
                }
            }
            if (random == 3){
                if (weapons[3] > 0){
                    cout << "OH NO! Your +2 Battle Axe broke." << endl;
                    weapons[3]--;
                    cout << endl;
                }
            }
            if (random == 4){
                if (weapons[4] > 0){
                    cout << "OH NO! Your +3 Longsword broke." << endl;
                    weapons[4]--;
                    cout << endl;
                }
            }
        }
        else if(rand()%10 == 0 || rand()%10 == 0 || rand()%10 == 0){
            random = rand()%players.size();
            cout << "OH NO! " << players.at(random).getName() << " has gotten food poisoning. Lose 10 points of hunger!" << endl;
            cout << endl;
            players.at(random).setFullness(players.at(random).getFullness() - 10);
        }
    }
}
