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
        double getMultiplyer();
        void printMenu();
        void updateMultiplyer();
        bool getSpeakable();
        void setSpeakable(bool speak);
        void closeMerchant();
};
#endif;

