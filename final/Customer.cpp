#include <iostream>
#include <fstream>
#include "Customer.h"
using namespace std;

Customer::Customer()
{
    bankVal = -0.01;
    name="NONE";
};
Customer::Customer(string newName, double newBankVal)
{
    bankVal = newBankVal;
    name= newName;
}
double Customer::getBankVal()
{
    return bankVal;
}
void Customer::addMoney(double addedMoney)
{
    bankVal+=addedMoney;
}

Customer::~Customer()
{
    bankVal = -0.01;
    name="NONE";
};