//Scoreboard.cpp
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <vector>
#include "Scoreboard.h"
using namespace std;

int splitThis(string input_string, char separator, string arr[], int arr_size){
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

void sortScore(string arr[][2], int size){
    string largest, temp; // declare varibles
    string largestName, tempName;
    int pos;
    for (int i = 0; i < size - 1; i++){ // loop thru score
        largestName = arr[i][0];
        largest = arr[i][1];
        pos = i;
        for (int j = i+1; j < size; j++){ // loop again
            if (stoi(largest) < stoi(arr[j][1])){ // check for largest
                largestName = arr[j][0]; // fill arrays
                largest = arr[j][1];
                pos = j;
            }
        }
        tempName = arr[i][0]; // array fill variables
        temp = arr[i][1];
        arr[i][0] = largestName;
        arr[i][1] = largest;
        arr[pos][0] = tempName;
        arr[pos][1] = temp;
    }
}

//reads from the scoreboard.txt file and adds the highscores to the highscore array
Scoreboard::Scoreboard(){
    ifstream file("scoreboard.txt"); // variable declarations
    string line;
    string splitLine[2];
    for (int i = 0; i < scoreboardSize; i++){ // loop thru scorboard
        getline(file, line);
        splitThis(line, ',', splitLine, 2); // split at ,
        scoreboard[i][0] = splitLine[0];
        scoreboard[i][1] = splitLine[1];
    }
    file.close();
}

//prints out the people and their scores on the scoreboard
void Scoreboard::printScoreBoard(){
    cout << "High Scores: " << endl;
    for (int i = 0; i < scoreboardSize; i++){
        cout << " " << i+1 << ". " + scoreboard[i][0] + ": " + scoreboard[i][1] << endl;
    }
}
void Scoreboard::writeScoreBoard(){
    ofstream file("scoreboard.txt");
    for (int i = 0; i < scoreboardSize; i++){ //write scoreboard to a file
        file << scoreboard[i][0] + "," + scoreboard[i][1] << endl;
    }
    file.close();
}

//adds a user and their highscore to the highscore array
bool Scoreboard::addHighScore(string name, string highscore){
    for (int i = 0; i < scoreboardSize; i++){ // loop thru scoreboard
        if (stoi(scoreboard[i][1]) < stoi(highscore)){ // check condition of scoreboard to highscore
            scoreboard[scoreboardSize - 1][0] = name; // ovverride name variable
            scoreboard[scoreboardSize - 1][1] = highscore; // ovverride highschore variable
            sortScore(scoreboard, scoreboardSize); // sort scoreboard ranks
            return true;
        }
    }
    return false;
}

//returns the currentScore of the group
int Scoreboard::getCurrentScore(){
    return currentScore;
}

//sets the current score for the group
void Scoreboard::setCurrentScore(int score){
    currentScore = score;
}
