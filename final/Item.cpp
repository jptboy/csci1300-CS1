#include <iostream>
#include <fstream>
#include "Item.h"
using namespace std;


Item::Item()
{
    price=-1;
    quantity=-1;
};

Item::Item(double newPrice, double newQuantity)
{
    price=newPrice;
    quantity=newQuantity;
};

double getPrice()
{
    return price;
}
double getQuantity()
{
    return quantity;
}
void setPrice(double newPrice)
{
    price=newPrice;
}
void setQuantity(double newQuantity)
{
    quantity=newQuantity;
}

Item::~Item()
{
    price=-1;
    quantity=-1;
};