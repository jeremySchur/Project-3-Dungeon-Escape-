//Merchant.h
//CSCI 1300 Fall 2022
//Author: Jeremy Schur and Anthony Radke
//Recitation: 305/221 - Nikhith Sannidhi
#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>
#include <string>
#include <vector>
#include "Group.h"
using namespace std;

class Merchant
{
    private:
       double multiplyer = 1.0;
       vector<string> riddles;
       int num_riddles;
       int visits = 0;

   public:
        Merchant();
        // getters
        double getMultiplyer();
        void printMenu();
        
        void updateMultiplyer();
        bool openMerchant(Group &players);
};
#endif