//Merchant.h
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>
using namespace std;

class Merchant
{
    private:
       double multiplyer = 1.0;
       bool speakable = false;

    public:
        Merchant();
        // getters
        double getMultiplyer();
        bool getSpeakable();
        void printMenu();
        
        void updateMultiplyer();
        void setSpeakable(bool speak);
        void closeMerchant();
};
#endif;

