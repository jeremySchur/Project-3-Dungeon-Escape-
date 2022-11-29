//Merchant.cpp
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#include <iostream>
#include "Merchant.h"
#include "Group.h"
#include <string>
#include <fstream>
using namespace std;

int split(string input_string, char separator, string arr[], int arr_size){
    //declaring variable
    int breakPoint = 0, index = 0, subLen = 0;
    
    //if the input_string is empty return 0
    if (input_string == ""){
        return 0;
    }
    //otherwise, loop through input string
    else{
        for (int i = 0; i < input_string.length(); i++){
            subLen++;
            
            //if a separator is found, add the substr from breakPoint to one before the separator to arr
            if (input_string[i] == separator){
                arr[index++] = input_string.substr(breakPoint, subLen - 1);
                breakPoint = i+1;
                subLen = 0;
            }

            if (index >= arr_size){
                return -1;
            }
        }
        //add the final substr since the string cannot end in a separator 
        arr[index++] = input_string.substr(breakPoint);

        return index;
    }
}

//default constructor
Merchant::Merchant(){
    ifstream file("riddles.txt");
    string line;
    string splitLine[2];

    while (!file.eof()){
        getline(file, line);
        split(line, '~', splitLine, 2);
        riddles[num_riddles][0] = splitLine[0];
        riddles[num_riddles++][1] = splitLine[1];
    }
}

//returns the multiplyer the merchant has on their prices
double Merchant::getMultiplyer(){
    return multiplyer;
}

//increases the multiplyer by 25%
void Merchant::updateMultiplyer(){
    multiplyer += .25;
}

//prints the buying options for a merchant
void Merchant::printMenu(){

}


bool Merchant::openMerchant(Group &players){
    bool open = true;
    int userInput;
    char userDecision;
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
                    if (players.setNumClubs(players.getNumClubs() + userInput)){
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        cout << endl;
                        players.setGold(players.getGold() - ((2*multiplyer) * userInput));
                    }
                    else{
                        cout << "You cannot carry any more weapons. What else can I get for you?" << endl;
                        cout << endl;
                    }
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
                    if (players.setNumSpears(players.getNumSpears() + userInput)){
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        cout << endl;
                        players.setGold(players.getGold() - ((2*multiplyer) * userInput));
                    }
                    else{
                        cout << "You cannot carry any more weapons. What else can I get for you?" << endl;
                        cout << endl;
                    }
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
                    if (players.setNumRapiers(players.getNumRapiers() + userInput)){
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        cout << endl;
                        players.setGold(players.getGold() - ((5*multiplyer) * userInput));
                    }
                    else{
                        cout << "You cannot carry any more weapons. What else can I get for you?" << endl;
                        cout << endl;
                    }
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
                    if(players.setNumBattleAxes(players.getNumBattleAxes() + userInput)){
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        cout << endl;
                        players.setGold(players.getGold() - ((15*multiplyer) * userInput));
                    }
                    else{
                        cout << "You cannot carry any more weapons. What else can I get for you?" << endl;
                        cout << endl;
                    }
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
                    if(players.setNumLongSwords(players.getNumLongSwords() + userInput)){
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                        cout << endl;
                        players.setGold(players.getGold() - ((50*multiplyer) * userInput));
                    }
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
                if (players.setNumArmor(players.getNumArmor() + userInput)){
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    cout << endl;
                    players.setGold(players.getGold() - (5*multiplyer) * userInput);
                }
                else{
                    cout << "You already have armor for everyone. What else can I get you?" << endl;
                    cout << endl;
                }
                
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
}