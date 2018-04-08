#include <iostream>
#include <fstream>
#include "Customer.h"
using namespace std;

Customer::Customer()
{
    bankVal = -0.01;
    name="NONE"
}
Customer::Customer(double newName, double newBankVal)
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
    bankval+=addedMoney;
}

Customer::~Customer()
{
    bankVal = -0.01;
    name="NONE"
}