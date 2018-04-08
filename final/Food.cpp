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


string getTaste()
{
    return taste;
}
int getExpiration()
{
    return expiration;
}
string getEthnicOrigin()
{
    return ethnicOrigin;
}

void setTaste(string newTaste)
{
    taste=newTaste;
}
void setExpiration(int newExpiration)
{
    expiration=newExpiration;
}
void setEthnicOrigin(string newEthnicOrigin)
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