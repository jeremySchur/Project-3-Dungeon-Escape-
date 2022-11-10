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

//returns true if you are able to speak to the merchant, false otherwise
bool Merchant::getSpeakable(){
    return speakable;
}

//sets speakable to speak
void Merchant::setSpeakable(bool speak){
    speakable = speak;
}

//prints message and sets the speakable back to false
void Merchant::closeMerchant(){
    
}