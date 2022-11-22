//Merchant.cpp
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#include <iostream>
#include "Merchant.h"
using namespace std;

//default constructor
Merchant::Merchant(){

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

//prints message and sets the speakable back to false
void Merchant::closeMerchant(){
    
}