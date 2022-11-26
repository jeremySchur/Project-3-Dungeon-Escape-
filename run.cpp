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
    Merchant merch;
    char direction, userDecision;
    string name;
    bool running = true;
    int userInput;

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
    merch.openMerchant(players);
    merch.updateMultiplyer();

    while (running){
        if (gameMap.isNPCLocation(gameMap.getPlayerRow(), gameMap.getPlayerCol())){
            players.statusUpdate();
            gameMap.displayMap();

            cout << "Select one:" << endl;
            cout << " 1. Move" << endl;
            cout << " 2. Speak to NPC" << endl;
            cout << " 3. Give up" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 3){
                cout << "That is not a valid input. Select one:" << endl;
                cout << " 1. Move" << endl;
                cout << " 2. Speak to NPC" << endl;
                cout << " 3. Give up" << endl;
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
                merch.openMerchant(players);
                merch.updateMultiplyer();
                gameMap.removeNPC(gameMap.getPlayerRow(), gameMap.getPlayerCol());
            }
            else if (userInput == 3){
                cout << "Game over. You gave up." << endl;
                running = false;
                break;
            }
        }
        else if (gameMap.isRoomLocation(gameMap.getPlayerRow(), gameMap.getPlayerCol())){
            players.statusUpdate();
            gameMap.displayMap();

            cout << "Select one:" << endl;
            cout << " 1. Move" << endl;
            cout << " 2. Enter Room" << endl;
            cout << " 3. Give up" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 3){
                cout << "That is not a valid input. Select one:" << endl;
                cout << " 1. Move" << endl;
                cout << " 2. Enter Room" << endl;
                cout << " 3. Give up" << endl;
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
                if (players.getNumKeys() > 0){
                    if (monsters.fightMonster(players, players.getRoomsCleared() + 2)){
                        //HAVE A MISFORTUNE OCCUR
                        gameMap.removeRoom(gameMap.getPlayerRow(), gameMap.getPlayerCol());
                    }
                    else{
                        players.setGold(int(players.getGold()*.75));
                        players.setIngredients(players.getIngredients() - rand()%31);
                        players.setNumKeys(players.getNumKeys() - 1);
                        for (int i = 1; i < players.getNumArmor(); i++){
                            if (rand()%20 == 0){
                                cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl;
                                players.removePlayer(i);
                            }
                        }
                        for (int i = players.getNumArmor(); i < players.getSize(); i++){
                            if (rand()%10 == 0){
                                cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl;
                                players.removePlayer(i);
                            }
                        }
                        //HAVE A MISFORTUNE OCCUR 
                    }
                }
                else{
                    cout << "You do not have a key to enter the room." << endl;
                    //MAKE THE PARTY FALL INTO A TRAP
                }
            }
            else if (userInput == 3){
                cout << "Game over. You gave up." << endl;
                running = false;
                break;
            }
        }
        else if (gameMap.isDungeonExit(gameMap.getPlayerRow(), gameMap.getPlayerCol())){
            players.statusUpdate();
            gameMap.displayMap();

            cout << "Select one:" << endl;
            cout << " 1. Move" << endl;
            cout << " 2. End Game" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 2){
                cout << "That is not a valid input. Select one:" << endl;
                cout << " 1. Move" << endl;
                cout << " 2. End Game" << endl;
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
                if (players.getRoomsCleared() < 5){
                    cout << "There is a magical barrier blocking the exit. Defeat the sorcerer to gain access." << endl;
                }
                else{
                    cout << "CONGRATS, YOU BEAT DUNGEON ESCAPE!!!" << endl;
                    running = false;
                    break;
                }
            }
        }
        else if (gameMap.isExplored(gameMap.getPlayerRow(), gameMap.getPlayerCol())){
            players.statusUpdate();
            gameMap.displayMap();

            cout << "Select one:" << endl;
            cout << " 1. Move" << endl;
            cout << " 2. Pick a Fight" << endl;
            cout << " 3. Cook and Eat" << endl;
            cout << " 4. Give up" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 4){
                cout << "That is not a valid input. Select one:" << endl;
                cout << " 1. Move" << endl;
                cout << " 2. Investigate" << endl;
                cout << " 3. Pick a Fight" << endl;
                cout << " 4. Cook and Eat" << endl;
                cout << " 5. Give up" << endl;
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
                if (monsters.fightMonster(players, players.getRoomsCleared() + 1)){
                    players.setGold(players.getGold() + 10*(players.getRoomsCleared()+1));
                    players.setIngredients(players.getIngredients() + 5*(players.getRoomsCleared()+1));
                    if (rand()%10 == 0){
                        players.setNumKeys(players.getNumKeys()+1);
                    }
                }
                else{
                    players.setGold(int(players.getGold()*.75));
                    if (!(players.getIngredients() == 0)){
                            players.setIngredients(players.getIngredients() - rand()%31);
                        }
                    for (int i = 1; i < players.getNumArmor(); i++){
                        if (rand()%20 == 0){
                            cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl;
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
            else if (userInput == 3){
                players.cookFood();
            }
            else if (userInput == 4){
                cout << "Game over. You gave up." << endl;
                running = false;
                break;
            }
        }
        else{
            players.statusUpdate();
            gameMap.displayMap();

            cout << "Select one:" << endl;
            cout << " 1. Move" << endl;
            cout << " 2. Investigate" << endl;
            cout << " 3. Pick a Fight" << endl;
            cout << " 4. Cook and Eat" << endl;
            cout << " 5. Give up" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 5){
                cout << "That is not a valid input. Select one:" << endl;
                cout << " 1. Move" << endl;
                cout << " 2. Investigate" << endl;
                cout << " 3. Pick a Fight" << endl;
                cout << " 4. Cook and Eat" << endl;
                cout << " 5. Give up" << endl;
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
                if (rand()%10 == 0){
                    cout << "YOU FOUND A KEY!!!" << endl;
                    players.setNumKeys(players.getNumKeys()+1);
                }
                if (rand()%5 == 0){
                    if (players.getRoomsCleared() == 0){
                        cout << "YOU FOUND A SILVER RING!!!" << endl;
                        players.setNumRings(players.getNumRings() + 1);
                    }
                    else if (players.getRoomsCleared() == 1){
                        cout << "YOU FOUND A RUBY NECKLACE!!!" << endl;
                        players.setNumNecklace(players.getNumNecklace() + 1);
                    }
                    else if (players.getRoomsCleared() == 2){
                        cout << "YOU FOUND A EMERALD BRACLET!!!" << endl;
                        players.setNumBraclet(players.getNumBraclet() + 1);
                    }
                    else if (players.getRoomsCleared() == 3){
                        cout << "YOU FOUND A DIAMOND CIRCLET!!!" << endl;
                        players.setNumCirclet(players.getNumCirclet() + 1);
                    }
                    else if (players.getRoomsCleared() == 4){
                        cout << "YOU FOUND A GEM-ENCRUSTED GOBLET!!!" << endl;
                        players.setNumGoblet(players.getNumGoblet() + 1);
                    }
                }
                if (rand()%5 == 0){
                    if (monsters.fightMonster(players, players.getRoomsCleared() + 1)){
                        players.setGold(players.getGold() + 10*(players.getRoomsCleared()+1));
                        players.setIngredients(players.getIngredients() + 5*(players.getRoomsCleared()+1));
                        if (rand()%10 == 0){
                            players.setNumKeys(players.getNumKeys()+1);
                        }
                    }
                    else{
                        players.setGold(int(players.getGold()*.75));
                        if (!(players.getIngredients() == 0)){
                            players.setIngredients(players.getIngredients() - rand()%31);
                        }
                        for (int i = 1; i < players.getNumArmor(); i++){
                            if (rand()%20 == 0){
                                cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl;
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
                    for (int i = 0; i < players.getSize(); i++){
                        if (rand()%2 == 0){
                            players.getPlayer(i).setFullness(players.getPlayer(i).getFullness() - 1);
                        }
                    }
                }
                gameMap.addExploreSpace(gameMap.getPlayerRow(), gameMap.getPlayerCol());
            }
            else if (userInput == 3){
                if (monsters.fightMonster(players, players.getRoomsCleared() + 1)){
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
                for (int i = 0; i < players.getSize(); i++){
                    if (rand()%2 == 0){
                        players.getPlayer(i).setFullness(players.getPlayer(i).getFullness() - 1);
                    }
                }
            }
            else if (userInput == 4){
                players.cookFood();
            }
            else if (userInput == 5){
                cout << "Game over. You gave up." << endl;
                running = false;
                break;
            }
        }
    }

    return 0;
}