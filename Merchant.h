//Merchant.h
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>
#include <string>
#include "Group.h"
using namespace std;

class Merchant
{
    private:
       double multiplyer = 1.0;
       string riddles[][2];
       int num_riddles;

   public:
        Merchant();
        // getters
        double getMultiplyer();
        void printMenu();
        
        void updateMultiplyer();
        bool openMerchant(Group &players);
};
#endif