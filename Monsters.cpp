#include <iostream>
#include <vector>
#include <fstream>
#include "Monsters.h"
#include <ctime>
using namespace std;

//split function
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

//converts a string to all uppercase leters 
string Uppercase(string str){ 
    for (int i = 0; i < str.length(); i++){ // loop thru
        if ((int)str[i] > 96 && (int)str[i] < 123){ // check asci value
            str[i] -= 32;
        }
    }
    return str;
}

//creats an instance of a group of monsters
Monsters::Monsters(string fileName){
    ifstream file(fileName); // variables
    string arr[2];
    string line;

    while (!file.eof()){ // loop while not at end of file
        getline(file, line);
        split(line, ',', arr, 2); // split each line
        // check the tier of the monster and add it to its respective vector
        if (stoi(arr[1]) == 1){ 
            tier1.push_back(arr[0]);
        }
        else if (stoi(arr[1]) == 2){
            tier2.push_back(arr[0]);
        }
        else if (stoi(arr[1]) == 3){
            tier3.push_back(arr[0]);
        }
        else if (stoi(arr[1]) == 4){
            tier4.push_back(arr[0]);
        }
        else if (stoi(arr[1]) == 5){
            tier5.push_back(arr[0]);
        }
        else if (stoi(arr[1]) == 6){
            tier6.push_back(arr[0]);
        }
    }
}

//runs the process for fighting a monster
bool Monsters::fightMonster(Group players, int tier){
    srand(time(0)); 
    int random, d, userInput; // variables
    double outcome;
    int total = players.getNumClubs() + players.getNumSpears() + 2*players.getNumRapiers() + 3*players.getNumBattleAxes() + 4*players.getNumLongSwords();
    if (players.getNumClubs() == 1 && players.getNumSpears() == 1 && players.getNumRapiers() == 1 && players.getNumBattleAxes() == 1 && players.getNumLongSwords() == 1){
        d = 4;
    }
    else{
        d = 0;
    }

    if (tier == 1){ // if tier is 1 print statemnt and check if the user is able to fight
        random = rand()%tier1.size();
        cout << Uppercase(tier1.at(random)) << " AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << endl;
        if (total == 0 || players.getNumArmor() == 0){
            cout << "1. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Surrender" << endl;
                cin >> userInput;
            }
            tier1.erase(tier1.begin() + random);
            return false;
        }
        else{ // allow user to fight or surrender
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1 && userInput != 2){ // invalid input
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Fight" << endl;
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){//fight input
                outcome = total*(rand()%6 + 1)+d - (tier*(rand()%6 + 1))/players.getNumArmor();
                if (outcome <= 0){
                    tier1.erase(tier1.begin() + random);
                    return false;
                }
                else{ // other input
                    tier1.erase(tier1.begin() + random);
                    return true;
                }
            }
            else{ //other input overall
                tier1.erase(tier1.begin() + random);
                return false;
            }
        }
    }
    else if (tier == 2){//if tier 2
        random = rand()%tier2.size(); // rand num
        cout << Uppercase(tier2.at(random)) << " AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << endl;
        if (total == 0 || players.getNumArmor() == 0){ // check if user has no armor
            cout << "1. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1){
                cout << "That is not a valid input. Choose one of the following:" << endl; // invalid input
                cout << "1. Surrender" << endl;
                cin >> userInput;
            }
            tier2.erase(tier2.begin() + random);
            return false;
        }
        else{ // user prompt to fight or surrender
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1 && userInput != 2){ // invalid input
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Fight" << endl;
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){ // if user fights
                outcome = total*(rand()%6 + 1)+d - (tier*(rand()%6 + 1))/players.getNumArmor();
                if (outcome <= 0){
                    tier2.erase(tier2.begin() + random);
                    return false;
                }
                else{ // any other user input
                    tier2.erase(tier2.begin() + random);
                    return true;
                }
            }
            else{ // other user input
                tier2.erase(tier2.begin() + random);
                return false;
            }
        }
    }
    else if (tier == 3){ // tier 3
        random = rand()%tier3.size();
        cout << Uppercase(tier3.at(random)) << " AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << endl;
        if (total == 0 || players.getNumArmor() == 0){  // if user no armor
            cout << "1. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1){
                cout << "That is not a valid input. Choose one of the following:" << endl; // invalid input
                cout << "1. Surrender" << endl;
                cin >> userInput;
            }
            tier3.erase(tier3.begin() + random);
            return false;
        }
        else{ // prompt user to fight or surredner
            cout << "1. Fight" << endl; 
            cout << "2. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1 && userInput != 2){
                cout << "That is not a valid input. Choose one of the following:" << endl; // invalid input
                cout << "1. Fight" << endl; 
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){ // if fight
                outcome = total*(rand()%6 + 1)+d - (tier*(rand()%6 + 1))/players.getNumArmor();
                if (outcome <= 0){
                    tier3.erase(tier3.begin() + random);
                    return false;
                }
                else{ //other input
                    tier3.erase(tier3.begin() + random);
                    return true;
                }
            }
            else{ // other overall input
                tier3.erase(tier3.begin() + random);
                return false;
            }
        }
    }
    else if (tier == 4){ // tier 4
        random = rand()%tier4.size(); // rand num
        cout << Uppercase(tier4.at(random)) << " AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << endl;
        if (total == 0 || players.getNumArmor() == 0){
            cout << "1. Surrender" << endl; 
            cin >> userInput; // store user input
            while (userInput != 1){ // invalid input
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Surrender" << endl;
                cin >> userInput;
            }
            tier4.erase(tier4.begin() + random);
            return false;
        }
        else{ // user chooses fight or surrender
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> userInput; //store input
            while (userInput != 1 && userInput != 2){
                cout << "That is not a valid input. Choose one of the following:" << endl; // invalid input
                cout << "1. Fight" << endl;
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){ // if fight
                outcome = total*(rand()%6 + 1)+d - (tier*(rand()%6 + 1))/players.getNumArmor();
                if (outcome <= 0){ //if outcome <= 0 
                    tier4.erase(tier4.begin() + random);
                    return false;
                }
                else{
                    tier4.erase(tier4.begin() + random);
                    return true;
                }
            }
            else{ // other usser input
                tier4.erase(tier4.begin() + random);
                return false;
            }
        }
    }
    else if (tier == 5){ // tier 5
        random = rand()%tier5.size(); // rand num
        cout << Uppercase(tier5.at(random)) << " AHEAD! THEY LOOK HOSTILE!" << endl; //print hostile
        cout << endl;
        if (total == 0 || players.getNumArmor() == 0){ // if total 0 or user no armor allow to surrender
            cout << "1. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1){
                cout << "That is not a valid input. Choose one of the following:" << endl; // invalid input
                cout << "1. Surrender" << endl;
                cin >> userInput;
            }
            tier5.erase(tier5.begin() + random);
            return false;
        } 
        else{ // allow user to fight surrender
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1 && userInput != 2){ // check user input
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Fight" << endl;
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){ // if fight
                outcome = total*(rand()%6 + 1)+d - (tier*(rand()%6 + 1))/players.getNumArmor();
                if (outcome <= 0){
                    tier5.erase(tier5.begin() + random);
                    return false;
                }
                else{
                    tier5.erase(tier5.begin() + random);
                    return true;
                }
            }
            else{ // other inputs
                tier5.erase(tier5.begin() + random);
                return false;
            }
        }
    }
    else{ // any other input
        cout << Uppercase(tier6.at(0)) << " AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << endl;
        if (total == 0 || players.getNumArmor() == 0){ 
            cout << "1. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1){
                cout << "That is not a valid input. Choose one of the following:" << endl; // invalid ipnut
                cout << "1. Surrender" << endl;
                cin >> userInput;
            }
            return false;
        }
        else{ // user fight/surrender
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> userInput; // sotre input
            while (userInput != 1 && userInput != 2){
                cout << "That is not a valid input. Choose one of the following:" << endl; //invalid input
                cout << "1. Fight" << endl;
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){ // if user input 1
                outcome = total*(rand()%6 + 1)+d - (tier*(rand()%6 + 1))/players.getNumArmor();
                if (outcome <= 0){ //outcome less than or equal to 0
                    return false;
                }
                else{
                    tier6.erase(tier6.begin());
                    return true;
                }
            }
            else{ // other input
                return false;
            }
        }
    }
}