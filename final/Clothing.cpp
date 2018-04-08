#include <iostream>
#include <fstream>
#include "Clothing.h"
using namespace std;

Clothing::Clothing()
{
    type = "NONE";
    size=-1;
    color="NONE";
    price=-1;
    quantity=-1;
};

Clothing::Clothing(string new_Type, int new_Size, string new_Color, double newPrice, double newQuantity)
{
    type = new_Type;
    size=new_Size;
    color=new_Color;
    price=newPrice;
    quantity=newQuantity;
};

string getType()
{
    return type;
}
string getColor()
{
    return color;
}
int getSize()
{
    return size;
}

void setType(string new_Type)
{
    type = new_Type;
}
void setColor(string new_Color)
{
    size=new_Size;
}
void setSize(int new_Size)
{
    color=new_Color;
}
Clothing::~Clothing()
{
    type = "NONE";
    size=-1;
    color="NONE";
    price=-1;
    quantity=-1;
};