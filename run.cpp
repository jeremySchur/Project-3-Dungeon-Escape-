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
#include "Map.h"
#include "Monsters.h"
#include "Scoreboard.h"
using namespace std;

//main for the entire game run
int main(){
    srand(time(0));
    Group players;
    Map gameMap = Map();
    Monsters monsters("monsters.txt");
    Merchant merch;
    Scoreboard playerHighScores;
    char direction, userDecision;
    string name;
    bool running = true;
    int userInput, random;

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

    cout << endl;
    cout << "These are the current highscores for Dungeon Escape." << endl;
    playerHighScores.printScoreBoard();
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
            gameMap.foundNPC(gameMap.getPlayerRow(), gameMap.getPlayerCol());
            //menu
            cout << "Select one:" << endl;
            cout << " 1. Move" << endl;
            cout << " 2. Speak to NPC" << endl;
            cout << " 3. Give up" << endl;
            cin >> userInput; //store input
            while (userInput < 1 || userInput > 3){ //loop 
            //menu
                cout << "That is not a valid input. Select one:" << endl;
                cout << " 1. Move" << endl;
                cout << " 2. Speak to NPC" << endl;
                cout << " 3. Give up" << endl;
                cin >> userInput;
            }

            if (userInput == 1){ //if input 1 ask direction
                cout << "What direction would you like to move (w,a,s,d)." << endl;
                cin >> direction;
                while (!gameMap.move(direction)){
                    cout << "You are trying to move outside the bounds of the map (12x12). Please enter a different direction (w,a,s,d)." << endl; //invalid
                    cin >> direction;
                } 
                for (int i = 0; i < players.getSize(); i++){ //loop fullness
                    if (rand() % 5 == 0){
                        players.setPlayerFullness(i, players.getPlayer(i).getFullness() - 1);
                    }
                }
                if (!gameMap.isExplored(gameMap.getPlayerRow(), gameMap.getPlayerCol())){ //add to anger level
                    players.setAngerLevel(players.getAngerLevel() + 1);
                }
            }
            else if (userInput == 2){ //input 2
                if (merch.openMerchant(players)){
                    playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + 10); // add 10 to score
                    merch.updateMultiplyer();
                }
                else{
                    cout << "You are not worthy of my goods. Take this!" << endl; //fight
                    if (monsters.fightMonster(players, players.getRoomsCleared() + 1)){
                        cout << "You were victorious in your battle." << endl; //win battle
                        cout << endl;
                        players.setGold(players.getGold() + 10*(players.getRoomsCleared()+1)); //update gold
                        players.setIngredients(players.getIngredients() + 5*(players.getRoomsCleared()+1)); //update ingredients
                        playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + 10); //update score
                        if (rand()%10 == 0){
                            players.setNumKeys(players.getNumKeys()+1); // update keys
                        }
                    }
                    else{
                        cout << "You lost your battle." << endl; //lost abttle
                        cout << endl;
                        players.setGold(int(players.getGold()*.75)); // remove gold
                        if (players.getIngredients() < 30){
                            players.setIngredients(0); //remove ingredients
                        }
                        else{
                            players.setIngredients(players.getIngredients() - rand()%31);
                        }
                        for (int i = 1; i < players.getNumArmor(); i++){ //loop thru team 
                            if (rand()%20 == 0){
                                cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl; //companion dies
                                players.removePlayer(i); // remove companion
                            }
                        }
                        for (int i = players.getNumArmor(); i < players.getSize(); i++){ //loop thru players
                            if (rand()%10 == 0){
                                cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl; // companion dies
                                players.removePlayer(i); //remove copmaion
                            }
                        }
                    }
                }
                gameMap.removeNPC(gameMap.getPlayerRow(), gameMap.getPlayerCol()); //updates
            }
            else if (userInput == 3){ // user input 3
                cout << "Game over. You gave up." << endl; // user loses
                cout << endl;
                playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + players.getGold() + 100*players.getSize() + 10*players.getNumKeys() + 5*players.getNumArmor() + players.getNumClubs() + players.getNumSpears() + 2*players.getNumRapiers() + 3*players.getNumBattleAxes() + 4*players.getNumLongSwords() + players.getNumPots() + players.getNumPans() + players.getNumCauldrons());
                if (playerHighScores.addHighScore(players.getPlayer(0).getName(), to_string(playerHighScores.getCurrentScore()))){ // if user reaches new highscore
                    cout << "YOU BEAT A HIGHSCORE!!!" << endl; //if new highscore
                    playerHighScores.printScoreBoard(); // print board
                }
                else{
                    cout << "No highscores were beat." << endl; // no new score
                    playerHighScores.printScoreBoard(); // print board
                }
                running = false; // end
                break;
            }
        }
        else if (gameMap.isRoomLocation(gameMap.getPlayerRow(), gameMap.getPlayerCol())){
            players.statusUpdate(); //updates
            gameMap.displayMap();


            // menu
            cout << "Select one:" << endl;
            cout << " 1. Move" << endl;
            cout << " 2. Enter Room" << endl;
            cout << " 3. Give up" << endl;
            cin >> userInput; //store input
            while (userInput < 1 || userInput > 3){ //loop 
                cout << "That is not a valid input. Select one:" << endl;
                cout << " 1. Move" << endl;
                cout << " 2. Enter Room" << endl;
                cout << " 3. Give up" << endl;
                cin >> userInput;
            }

            if (userInput == 1){ //input 1
                cout << "What direction would you like to move (w,a,s,d)." << endl;
                cin >> direction;
                while (!gameMap.move(direction)){ //invalid move
                    cout << "You are trying to move outside the bounds of the map (12x12). Please enter a different direction (w,a,s,d)." << endl;
                    cin >> direction; //store input
                }
                for (int i = 0; i < players.getSize(); i++){ //loop thru size
                    if (rand() % 5 == 0){
                        players.setPlayerFullness(i, players.getPlayer(i).getFullness() - 1); //lower fullness
                    }
                }
                if (!gameMap.isExplored(gameMap.getPlayerRow(), gameMap.getPlayerCol())){
                    players.setAngerLevel(players.getAngerLevel() + 1); // add to anger level
                }
            }
            else if (userInput == 2){ //user input 2
                if (players.getNumKeys() > 0){
                    if (monsters.fightMonster(players, players.getRoomsCleared() + 2)){ //player fights monster / clear room
                        cout << "You were victorious in your battle." << endl; // win battle
                        cout << endl;
                        gameMap.removeRoom(gameMap.getPlayerRow(), gameMap.getPlayerCol());
                        players.setNumKeys(players.getNumKeys() - 1); //remove key
                        playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + 100); // update score
                    }
                    else{ 
                        cout << "You lost your battle." << endl; //lose battle
                        cout << endl;
                        players.setGold(int(players.getGold()*.75));//remove gold
                        players.setNumKeys(players.getNumKeys() - 1); // remove keys
                        if (players.getIngredients() < 30){ //remove ingredients
                            players.setIngredients(0);
                        }
                        else{
                            players.setIngredients(players.getIngredients() - rand()%31);
                        }
                        for (int i = 1; i < players.getNumArmor(); i++){ //loop armor
                            if (rand()%20 == 0){
                                cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl; //companion dies
                                players.removePlayer(i); // remove companion
                            }
                        }
                        for (int i = players.getNumArmor(); i < players.getSize(); i++){ // loop armor
                            if (rand()%10 == 0){
                                cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl; //companion dies
                                players.removePlayer(i); // remove companion
                            }
                        }
                        //HAVE A MISFORTUNE OCCUR 
                    }
                }
                else{
                    //menu
                    bool enter = false;
                    random = rand()%3;
                    cout << "You do not have a key to enter the room. Beat me in a challenge and you can enter:" << endl;
                    cout << "Choose one:" << endl;
                    cout << " 1. Boulder" << endl;
                    cout << " 2. Parchment" << endl;
                    cout << " 3. Sheers" << endl;
                    cin >> userInput;
                    while ((userInput-1) == random){
                        cout << "Its a tie. Choose one:" << endl; //tie options
                        cout << " 1. Boulder" << endl;
                        cout << " 2. Parchment" << endl;
                        cout << " 3. Sheers" << endl;
                        random = rand()%3;
                        cin >> userInput;
                    }
                    if (userInput-1 == 0 && random == 2){
                        cout << "You win. Enter the room." << endl; // win and enter
                        cout << endl;
                        enter = true;
                    }
                    else if (userInput-1 == 1 && random == 0){
                        cout << "You win. Enter the room." << endl; // win and enter
                        cout << endl;
                        enter = true;
                    }
                    else if (userInput-1 == 2 && random == 1){
                        cout << "You win. Enter the room." << endl; // win and enter
                        cout << endl;
                        enter = true;
                    }
                    else{
                        random = rand()%(players.getSize()-1) + 1; // lose and companion dies
                        cout << "Sorry. You may not enter the room. As a result of your recklessnes, companion " << players.getPlayer(random).getName() << " has died." << endl;
                        cout << endl;
                        players.removePlayer(random);
                    }

                    if (enter){
                        if (monsters.fightMonster(players, players.getRoomsCleared() + 2)){
                            cout << "You were victorious in your battle." << endl; // win battle
                            cout << endl;
                            gameMap.removeRoom(gameMap.getPlayerRow(), gameMap.getPlayerCol());
                            playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + 100); // update scorfe
                        }
                        else{
                            cout << "You lost your battle." << endl; //lose battle
                            cout << endl;
                            players.setGold(int(players.getGold()*.75)); //lose gold
                            if (players.getIngredients() < 30){ // lose ingreidents
                                players.setIngredients(0);
                            }
                            else{
                                players.setIngredients(players.getIngredients() - rand()%31);
                            }
                            for (int i = 1; i < players.getNumArmor(); i++){ //loop armor
                                if (rand()%20 == 0){
                                    cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl; //companion dies
                                    players.removePlayer(i); //remove companion
                                }
                            }
                            for (int i = players.getNumArmor(); i < players.getSize(); i++){
                                if (rand()%10 == 0){
                                    cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl;// companion dies
                                    players.removePlayer(i); // remove companion
                                }
                            }
                            //HAVE A MISFORTUNE OCCUR 
                        }
                    }
                }
            }
            else if (userInput == 3){
                cout << "Game over. You gave up." << endl; // end game
                cout << endl;
                //check  for new highschore
                playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + players.getGold() + 100*players.getSize() + 10*players.getNumKeys() + 5*players.getNumArmor() + players.getNumClubs() + players.getNumSpears() + 2*players.getNumRapiers() + 3*players.getNumBattleAxes() + 4*players.getNumLongSwords() + players.getNumPots() + players.getNumPans() + players.getNumCauldrons());
                if (playerHighScores.addHighScore(players.getPlayer(0).getName(), to_string(playerHighScores.getCurrentScore()))){
                    cout << "YOU BEAT A HIGHSCORE!!!" << endl; //new highscore
                    playerHighScores.printScoreBoard(); //print scoreboard
                }
                else{
                    cout << "No highscores were beat." << endl; // no new highscore
                    playerHighScores.printScoreBoard(); // print scoreboard
                }
                running = false; // end
                break;
            }
        }
        else if (gameMap.isDungeonExit(gameMap.getPlayerRow(), gameMap.getPlayerCol())){
            players.statusUpdate();
            gameMap.displayMap();
            //menu
            cout << "Select one:" << endl;
            cout << " 1. Move" << endl;
            cout << " 2. End Game" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 2){
                cout << "That is not a valid input. Select one:" << endl; //invlid input
                cout << " 1. Move" << endl;
                cout << " 2. End Game" << endl;
                cin >> userInput;
            }

            if (userInput == 1){ // input 1
                cout << "What direction would you like to move (w,a,s,d)." << endl;
                cin >> direction;
                while (!gameMap.move(direction)){
                    cout << "You are trying to move outside the bounds of the map (12x12). Please enter a different direction (w,a,s,d)." << endl; // invalid input
                    cin >> direction;
                }
                for (int i = 0; i < players.getSize(); i++){
                    if (rand() % 5 == 0){
                        players.setPlayerFullness(i, players.getPlayer(i).getFullness() - 1); //lower fullness
                    }
                }
                if (!gameMap.isExplored(gameMap.getPlayerRow(), gameMap.getPlayerCol())){
                    players.setAngerLevel(players.getAngerLevel() + 1); // add to anger level
                }
            }
            else if (userInput == 2){
                if (players.getRoomsCleared() < 5){
                    cout << "There is a magical barrier blocking the exit. Defeat the sorcerer to gain access." << endl; //barrier, no access
                }
                else{
                    cout << "CONGRATS, YOU BEAT DUNGEON ESCAPE!!!" << endl; // game win
                    cout << endl;
                    playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + 5000); //update score
                    playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + players.getGold() + 100*players.getSize() + 10*players.getNumKeys() + 5*players.getNumArmor() + players.getNumClubs() + players.getNumSpears() + 2*players.getNumRapiers() + 3*players.getNumBattleAxes() + 4*players.getNumLongSwords() + players.getNumPots() + players.getNumPans() + players.getNumCauldrons());
                    if (playerHighScores.addHighScore(players.getPlayer(0).getName(), to_string(playerHighScores.getCurrentScore()))){
                        cout << "YOU BEAT A HIGHSCORE!!!" << endl; // check for new highschore and print scoreboard
                        playerHighScores.printScoreBoard();
                    }
                    else{
                        cout << "No highscores were beat." << endl; // no new highschore but still print scoreboard
                        playerHighScores.printScoreBoard();
                    }
                    running = false;
                    break;
                }
            }
        }
        else if (gameMap.isExplored(gameMap.getPlayerRow(), gameMap.getPlayerCol())){
            players.statusUpdate();
            gameMap.displayMap();
            //menu
            cout << "Select one:" << endl;
            cout << " 1. Move" << endl;
            cout << " 2. Pick a Fight" << endl;
            cout << " 3. Cook and Eat" << endl;
            cout << " 4. Give up" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 4){
                cout << "That is not a valid input. Select one:" << endl; //invalid
                cout << " 1. Move" << endl;
                cout << " 3. Pick a Fight" << endl;
                cout << " 4. Cook and Eat" << endl;
                cout << " 5. Give up" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
                cout << "What direction would you like to move (w,a,s,d)." << endl; //move direciton
                cin >> direction;
                while (!gameMap.move(direction)){
                    cout << "You are trying to move outside the bounds of the map (12x12). Please enter a different direction (w,a,s,d)." << endl; //invalid move
                    cin >> direction; 
                }
                for (int i = 0; i < players.getSize(); i++){ //loop thru size
                    if (rand() % 5 == 0){
                        players.setPlayerFullness(i, players.getPlayer(i).getFullness() - 1); //lower fullness
                    }
                }
                if (!gameMap.isExplored(gameMap.getPlayerRow(), gameMap.getPlayerCol())){ //check position
                    players.setAngerLevel(players.getAngerLevel() + 1); // add to ange
                }
            }
            else if (userInput == 2){ //input 2
                if (monsters.fightMonster(players, players.getRoomsCleared() + 1)){//update room cleared
                    cout << "You were victorious in your battle." << endl; // win battle
                    cout << endl;
                    players.setGold(players.getGold() + 10*(players.getRoomsCleared()+1)); //update gold
                    players.setIngredients(players.getIngredients() + 5*(players.getRoomsCleared()+1)); //update ingredients
                    playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + 10);  //update score
                    if (rand()%10 == 0){
                        players.setNumKeys(players.getNumKeys()+1); //update keys
                    }
                }
                else{
                    cout << "You lost your battle." << endl; //lose battle
                    cout << endl;
                    players.setGold(int(players.getGold()*.75)); //lose gold
                    if (players.getIngredients() < 30){ //lose ingreidnets
                        players.setIngredients(0); 
                    }
                    else{
                        players.setIngredients(players.getIngredients() - rand()%31); //update ingredeitns
                    }
                    for (int i = 1; i < players.getNumArmor(); i++){
                        if (rand()%20 == 0){
                            cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl; //companion dies
                            players.removePlayer(i); //remove companion
                        }
                    }
                    for (int i = players.getNumArmor(); i < players.getSize(); i++){
                        if (rand()%10 == 0){
                            cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl; //companion dies
                            players.removePlayer(i); // remove comapnion
                        }
                    }
                }
            }
            else if (userInput == 3){
                players.cookFood();
            }
            else if (userInput == 4){
                cout << "Game over. You gave up." << endl; // user gives up
                cout << endl;
                // chcek for new user highschore
                playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + players.getGold() + 100*players.getSize() + 10*players.getNumKeys() + 5*players.getNumArmor() + players.getNumClubs() + players.getNumSpears() + 2*players.getNumRapiers() + 3*players.getNumBattleAxes() + 4*players.getNumLongSwords() + players.getNumPots() + players.getNumPans() + players.getNumCauldrons());
                if (playerHighScores.addHighScore(players.getPlayer(0).getName(), to_string(playerHighScores.getCurrentScore()))){
                    cout << "YOU BEAT A HIGHSCORE!!!" << endl; //new highschore and print scoreboard
                    playerHighScores.printScoreBoard();
                }
                else{
                    cout << "No highscores were beat." << endl; // no new highschore print scoreboard still
                    playerHighScores.printScoreBoard();
                }
                running = false;
                break;
            }
        }
        else{
            players.statusUpdate();
            gameMap.displayMap();
            //menu
            cout << "Select one:" << endl;
            cout << " 1. Move" << endl;
            cout << " 2. Investigate" << endl;
            cout << " 3. Pick a Fight" << endl;
            cout << " 4. Cook and Eat" << endl;
            cout << " 5. Give up" << endl;
            cin >> userInput;
            while (userInput < 1 || userInput > 5){
                cout << "That is not a valid input. Select one:" << endl; //invalid input
                cout << " 1. Move" << endl;
                cout << " 2. Investigate" << endl;
                cout << " 3. Pick a Fight" << endl;
                cout << " 4. Cook and Eat" << endl;
                cout << " 5. Give up" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
                cout << "What direction would you like to move (w,a,s,d)." << endl; //move direction
                cin >> direction;
                while (!gameMap.move(direction)){
                    cout << "You are trying to move outside the bounds of the map (12x12). Please enter a different direction (w,a,s,d)." << endl; //invalidmove
                    cin >> direction;
                }
                for (int i = 0; i < players.getSize(); i++){
                    if (rand() % 5 == 0){
                        players.setPlayerFullness(i, players.getPlayer(i).getFullness() - 1); // lower player fullness
                    }
                }
                if (!gameMap.isExplored(gameMap.getPlayerRow(), gameMap.getPlayerCol())){ // check position
                    players.setAngerLevel(players.getAngerLevel() + 1);
                }
            }
            else if (userInput == 2){ //input 2
                playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + 1);
                if (rand()%10 == 0){
                    cout << "YOU FOUND A KEY!!!" << endl; //user finds key add 1 to key
                    players.setNumKeys(players.getNumKeys()+1);
                }
                if (rand()%5 == 0){
                    if (players.getRoomsCleared() == 0){ // found ring add 1 to rings
                        cout << "YOU FOUND A SILVER RING!!!" << endl;
                        players.setNumRings(players.getNumRings() + 1);
                    }
                    else if (players.getRoomsCleared() == 1){
                        cout << "YOU FOUND A RUBY NECKLACE!!!" << endl;
                        players.setNumNecklace(players.getNumNecklace() + 1); // found necklace add 1 to necklace
                    }
                    else if (players.getRoomsCleared() == 2){
                        cout << "YOU FOUND A EMERALD BRACLET!!!" << endl;
                        players.setNumBraclet(players.getNumBraclet() + 1); // found bracelet add 1 to bracelets
                    }
                    else if (players.getRoomsCleared() == 3){
                        cout << "YOU FOUND A DIAMOND CIRCLET!!!" << endl;
                        players.setNumCirclet(players.getNumCirclet() + 1); //found circlet add 1 to circlet
                    }
                    else if (players.getRoomsCleared() == 4){
                        cout << "YOU FOUND A GEM-ENCRUSTED GOBLET!!!" << endl;
                        players.setNumGoblet(players.getNumGoblet() + 1); // found gem encrust goblet add 1 to goblet
                    }
                }
                if (rand()%5 == 0){
                    if (monsters.fightMonster(players, players.getRoomsCleared() + 1)){ //update rooms cleared
                        cout << "You were victorious in your battle." << endl; // if user wins battle
                        cout << endl;
                        players.setGold(players.getGold() + 10*(players.getRoomsCleared()+1)); //update room clear
                        players.setIngredients(players.getIngredients() + 5*(players.getRoomsCleared()+1)); 
                        playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + 10); // update score
                        if (rand()%10 == 0){ 
                            players.setNumKeys(players.getNumKeys()+1); //update keys
                        }
                    }
                    else{
                        cout << "You were victorious in your battle." << endl;// win battle
                        cout << endl;
                        players.setGold(int(players.getGold()*.75)); // update gold
                        if (players.getIngredients() < 30){
                            players.setIngredients(0);
                        }
                        else{
                            players.setIngredients(players.getIngredients() - rand()%31);
                        }
                        for (int i = 1; i < players.getNumArmor(); i++){
                            if (rand()%20 == 0){
                                cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl; //companin dies
                                players.removePlayer(i); // remove companion
                            }
                        }
                        for (int i = players.getNumArmor(); i < players.getSize(); i++){
                            if (rand()%10 == 0){
                                cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl; // companion dies
                                players.removePlayer(i); // remove companion
                            }
                        }
                    }
                    for (int i = 0; i < players.getSize(); i++){
                        if (rand()%2 == 0){
                            players.getPlayer(i).setFullness(players.getPlayer(i).getFullness() - 1); // update fullness
                        }
                    }
                }
                gameMap.addExploreSpace(gameMap.getPlayerRow(), gameMap.getPlayerCol()); // user pos check 
            }
            else if (userInput == 3){
                if (monsters.fightMonster(players, players.getRoomsCleared() + 1)){ // update room clear
                    cout << "You were victorious in your battle." << endl; // win battle
                    cout << endl;
                    players.setGold(players.getGold() + 10*(players.getRoomsCleared()+1));
                    players.setIngredients(players.getIngredients() + 5*(players.getRoomsCleared()+1));
                    playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + 10); // update score
                    if (rand()%10 == 0){
                        players.setNumKeys(players.getNumKeys()+1); //update keys
                    }
                }
                else{
                    cout << "You lost your battle." << endl;
                    cout << endl;
                    players.setGold(int(players.getGold()*.75)); // update gold
                    if (players.getIngredients() < 30){ // update ingreidnets
                        players.setIngredients(0); 
                    }
                    else{
                        players.setIngredients(players.getIngredients() - rand()%31);
                    }
                    for (int i = 1; i < players.getNumArmor(); i++){
                        if (rand()%20 == 0){
                            cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl; // compnaion dies
                            players.removePlayer(i); // remove compnaion
                        }
                    }
                    for (int i = players.getNumArmor(); i < players.getSize(); i++){
                        if (rand()%10 == 0){
                            cout << "Companion " << players.getPlayer(i).getName() << " has died during combat." << endl; // companion dies
                            players.removePlayer(i); // remove companion
                        }
                    }
                }
                for (int i = 0; i < players.getSize(); i++){
                    if (rand()%2 == 0){
                        players.getPlayer(i).setFullness(players.getPlayer(i).getFullness() - 1); // update fullness
                    }
                }
            }
            else if (userInput == 4){ // input 4
                players.cookFood();
            }
            else if (userInput == 5){
                cout << "Game over. You gave up." << endl; // user give up
                cout << endl;
                // check for new user highschore
                playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + players.getGold() + 100*players.getSize() + 10*players.getNumKeys() + 5*players.getNumArmor() + players.getNumClubs() + players.getNumSpears() + 2*players.getNumRapiers() + 3*players.getNumBattleAxes() + 4*players.getNumLongSwords() + players.getNumPots() + players.getNumPans() + players.getNumCauldrons());
                if (playerHighScores.addHighScore(players.getPlayer(0).getName(), to_string(playerHighScores.getCurrentScore()))){
                    cout << "YOU BEAT A HIGHSCORE!!!" << endl; // new highschore print scoreboard
                    playerHighScores.printScoreBoard();
                }
                else{
                    cout << "No highscores were beat." << endl; // no new hs but still print scoreboard
                    playerHighScores.printScoreBoard();
                }
                running = false;
                break;
            }
        }
        for (int i = 0; i < players.getSize(); i++){
            if (players.getPlayer(i).getFullness() <= 0){
                cout << "Player " << players.getPlayer(i).getName() << " has died of stravation." << endl; //player dies of sarvation
                cout << endl;
                players.removePlayer(i);
            }
        }
        if (players.getAngerLevel() == 100){ // game ends due to anger
            cout << "Game over. There sorcerer has become irritated." << endl;
            cout << endl;
            // check hs
            playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + players.getGold() + 100*players.getSize() + 10*players.getNumKeys() + 5*players.getNumArmor() + players.getNumClubs() + players.getNumSpears() + 2*players.getNumRapiers() + 3*players.getNumBattleAxes() + 4*players.getNumLongSwords() + players.getNumPots() + players.getNumPans() + players.getNumCauldrons());
            if (playerHighScores.addHighScore(players.getPlayer(0).getName(), to_string(playerHighScores.getCurrentScore()))){
                cout << "YOU BEAT A HIGHSCORE!!!" << endl; // new highschore print board
                playerHighScores.printScoreBoard();
            }
            else{
                cout << "No highscores were beat." << endl; // no new hs print board
                playerHighScores.printScoreBoard();
            }
            running = false;
            break;
        }
        if (players.getSize() < 2){
            cout << "Game over. You cannot traverse the dungeon alone." << endl; // no companions
            cout << endl;
            // check for new hs value
            playerHighScores.setCurrentScore(playerHighScores.getCurrentScore() + players.getGold() + 100*players.getSize() + 10*players.getNumKeys() + 5*players.getNumArmor() + players.getNumClubs() + players.getNumSpears() + 2*players.getNumRapiers() + 3*players.getNumBattleAxes() + 4*players.getNumLongSwords() + players.getNumPots() + players.getNumPans() + players.getNumCauldrons());
            if (playerHighScores.addHighScore(players.getPlayer(0).getName(), to_string(playerHighScores.getCurrentScore()))){
                cout << "YOU BEAT A HIGHSCORE!!!" << endl; // new hs print board
                playerHighScores.printScoreBoard();
            }
            else{
                cout << "No highscores were beat." << endl; // no new hs print board
                playerHighScores.printScoreBoard();
            }
            running = false;
            break;
        }
    }

    playerHighScores.writeScoreBoard(); // print scorebarod / highschores
    players.saveStats(); // save stats
    return 0;
}