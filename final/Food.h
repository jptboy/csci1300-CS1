#ifndef FOOD_H
#define FOOD_H
#include "Item.h"
#include <iostream>
using namespace std;
class Food:public Item, protected Item
{
    public:
        Food();
        Food(string newTaste, int newExpiration, string newEthnicOrigin);

        string getTaste();
        int getExpiration();
        string getEthnicOrigin();

        void setTaste(string newTaste);
        void setExpiration(int newExpiration);
        void setEthnicOrigin(string newEthnicOrigin);

        ~Food();
    private:
        string taste;
        int expiration;
        string ethnicOrigin;
};
#endif//FOOD_H