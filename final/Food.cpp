#include <iostream>
#include <fstream>
#include "Food.h"
using namespace std;

Food::Food()
{
    taste="NONE";
    expiration=-1;
    ethnicOrigin="None";
    price=-1;
    quantity=-1;
};

Food::Food(string newTaste, int newExpiration, string newEthnicOrigin, double newPrice, double newQuantity)
{
    taste=newTaste;
    expiration=newExpiration;
    ethnicOrigin=newEthnicOrigin;
    price=newPrice;
    quantity=newQuantity;
};


string Food::getTaste()
{
    return taste;
}
int Food::getExpiration()
{
    return expiration;
}
string Food::getEthnicOrigin()
{
    return ethnicOrigin;
}

void Food::setTaste(string newTaste)
{
    taste=newTaste;
}
void Food::setExpiration(int newExpiration)
{
    expiration=newExpiration;
}
void Food::setEthnicOrigin(string newEthnicOrigin)
{
    ethnicOrigin=newEthnicOrigin;
}


Food::~Food()
{
    taste="NONE";
    expiration=-1;
    ethnicOrigin="None";
    price=-1;
    quantity=-1;
};