#include <iostream>
#include <vector>
#include <fstream>
#include "Monsters.h"
#include <ctime>
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

string Uppercase(string str){
    for (int i = 0; i < str.length(); i++){
        if ((int)str[i] > 96 && (int)str[i] < 123){
            str[i] -= 32;
        }
    }
    return str;
}

Monsters::Monsters(string fileName){
    ifstream file(fileName);
    string arr[2];
    string line;

    while (!file.eof()){
        getline(file, line);
        split(line, ',', arr, 2);
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

bool Monsters::fightMonster(Group players, int tier){
    srand(time(0));
    int random, d, userInput;
    double outcome;
    int total = players.getNumClubs() + players.getNumSpears() + 2*players.getNumRapiers() + 3*players.getNumBattleAxes() + 4*players.getNumLongSwords();
    if (players.getNumClubs() == 1 && players.getNumSpears() == 1 && players.getNumRapiers() == 1 && players.getNumBattleAxes() == 1 && players.getNumLongSwords() == 1){
        d = 4;
    }
    else{
        d = 0;
    }

    if (tier == 1){
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
        else{
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1 && userInput != 2){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Fight" << endl;
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
                outcome = total*(rand()%6 + 1)+d - (tier*(rand()%6 + 1))/players.getNumArmor();
                if (outcome <= 0){
                    tier1.erase(tier1.begin() + random);
                    return false;
                }
                else{
                    tier1.erase(tier1.begin() + random);
                    return true;
                }
            }
            else{
                tier1.erase(tier1.begin() + random);
                return false;
            }
        }
    }
    else if (tier == 2){
        random = rand()%tier2.size();
        cout << Uppercase(tier2.at(random)) << " AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << endl;
        if (total == 0 || players.getNumArmor() == 0){
            cout << "1. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Surrender" << endl;
                cin >> userInput;
            }
            tier2.erase(tier2.begin() + random);
            return false;
        }
        else{
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1 && userInput != 2){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Fight" << endl;
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
                outcome = total*(rand()%6 + 1)+d - (tier*(rand()%6 + 1))/players.getNumArmor();
                if (outcome <= 0){
                    tier2.erase(tier2.begin() + random);
                    return false;
                }
                else{
                    tier2.erase(tier2.begin() + random);
                    return true;
                }
            }
            else{
                tier2.erase(tier2.begin() + random);
                return false;
            }
        }
    }
    else if (tier == 3){
        random = rand()%tier3.size();
        cout << Uppercase(tier3.at(random)) << " AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << endl;
        if (total == 0 || players.getNumArmor() == 0){
            cout << "1. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Surrender" << endl;
                cin >> userInput;
            }
            tier3.erase(tier3.begin() + random);
            return false;
        }
        else{
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1 && userInput != 2){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Fight" << endl;
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
                outcome = total*(rand()%6 + 1)+d - (tier*(rand()%6 + 1))/players.getNumArmor();
                if (outcome <= 0){
                    tier3.erase(tier3.begin() + random);
                    return false;
                }
                else{
                    tier3.erase(tier3.begin() + random);
                    return true;
                }
            }
            else{
                tier3.erase(tier3.begin() + random);
                return false;
            }
        }
    }
    else if (tier == 4){
        random = rand()%tier4.size();
        cout << Uppercase(tier4.at(random)) << " AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << endl;
        if (total == 0 || players.getNumArmor() == 0){
            cout << "1. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Surrender" << endl;
                cin >> userInput;
            }
            tier4.erase(tier4.begin() + random);
            return false;
        }
        else{
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1 && userInput != 2){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Fight" << endl;
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
                outcome = total*(rand()%6 + 1)+d - (tier*(rand()%6 + 1))/players.getNumArmor();
                if (outcome <= 0){
                    tier4.erase(tier4.begin() + random);
                    return false;
                }
                else{
                    tier4.erase(tier4.begin() + random);
                    return true;
                }
            }
            else{
                tier4.erase(tier4.begin() + random);
                return false;
            }
        }
    }
    else if (tier == 5){
        random = rand()%tier5.size();
        cout << Uppercase(tier5.at(random)) << " AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << endl;
        if (total == 0 || players.getNumArmor() == 0){
            cout << "1. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Surrender" << endl;
                cin >> userInput;
            }
            tier5.erase(tier5.begin() + random);
            return false;
        }
        else{
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1 && userInput != 2){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Fight" << endl;
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
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
            else{
                tier5.erase(tier5.begin() + random);
                return false;
            }
        }
    }
    else{
        cout << Uppercase(tier6.at(0)) << " AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << endl;
        if (total == 0 || players.getNumArmor() == 0){
            cout << "1. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Surrender" << endl;
                cin >> userInput;
            }
            tier6.erase(tier6.begin());
            return false;
        }
        else{
            cout << "1. Fight" << endl;
            cout << "2. Surrender" << endl;
            cin >> userInput;
            while (userInput != 1 && userInput != 2){
                cout << "That is not a valid input. Choose one of the following:" << endl;
                cout << "1. Fight" << endl;
                cout << "2. Surrender" << endl;
                cin >> userInput;
            }
            if (userInput == 1){
                outcome = total*(rand()%6 + 1)+d - (tier*(rand()%6 + 1))/players.getNumArmor();
                if (outcome <= 0){
                    tier6.erase(tier6.begin());
                    return false;
                }
                else{
                    tier6.erase(tier6.begin());
                    return true;
                }
            }
            else{
                tier6.erase(tier6.begin());
                return false;
            }
        }
    }
}