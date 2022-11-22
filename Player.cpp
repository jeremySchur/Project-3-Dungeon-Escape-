//Player.cpp
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <vector>
#include "Player.h"
using namespace std;

Player::Player(){
    name = "";
}

Player::Player(string name_){
    name = name_;
    fullness = 50;
}

//returns the name of the player
string Player::getName(){
    return name;
}

//return the players fullness level
int Player::getFullness(){
    return fullness;
}

//sets the fullness level of the player
void Player::setFullness(int fullness_){
    fullness = fullness_;
}



