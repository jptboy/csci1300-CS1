#include <iostream>
#include <fstream>
#include "Store.h"
using namespace std;
Store::Store()
{
    loadCustomers();
    Inventory storeInventory;
};
void Store::loadCustomers()
{

}
void Store::menu()
{

}
void Store::searchUsers()
{

}
void Store::buyItem()
{

}
void Store::addItemtoFavorite()
{

}
~Store()
{
    storeInventory.~Inventory();
};