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
    //the store will load customers
}
void Store::menu()//a menu asking customers what they want to do
{

}
void Store::searchUsers()//this is for the  store to search users the customer wont be seeing this or using it
{

}
void Store::buyItem()//self explanitory
{

}
void Store::addItemtoFavorite()//customers can add items to their favorites
{

}
void Store::shopLift()//customers can try to steal things if they dont have enough money to pay for them
{

}
void Store::viewBalance()//customers can see how much money they have before they pay for things
{

}
void Store::getReccomendations()//customers can get recomendations for foods clothing and electronics if they don't know what to buy
{

}
void Store::viewItems()//for the customer to view the inventory of the store and search it, they can narrow down to types of items and items
{

}
void Store::requestOrder()
{

}//this is used to ask the manager to order a item if you cant find it
void Store::quit()//I might name this leaveStore
{

}
Store::~Store()
{
    
};