#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(string name_){
    name = name_;
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



