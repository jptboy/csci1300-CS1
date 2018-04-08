#ifndef STORE_H
#define STORE_H
#include "Inventory.h"
#include "Customer.h"
#include "Manager.h"
#include <vector>
#include <iostream>
using namespace std;
class Store
{
    public:
        Store();
        void loadCustomers();
        void menu();
        void searchUsers();
        void buyItem();
        void addItemtoFavorite();
        ~Store();
    private:
        vector <Customer> customers;
};



#endif//STORE_H