#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;
class Customer
{
    public:
        
        Customer();
        Customer(string newName, double newBankVal);
        
        double getBankVal();//returns the amount of money that the customer has in their bank
        void addMoney(double addedMoney);//allows the user to add money to their bank account
    
        ~Customer();
    private:
        
        double bankVal;
        string name;

};

#endif//CUSTOMER_H