#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>
using namespace std;

class Merchant
{
    private:
       double multiplyer = 1.0;

    public:
        Merchant();
        double getMultiplyer();
        void printMenu();
        void updateMultiplyer();
        
};
#endif;

