#include <iostream>
#include <fstream>
#include "Electronic.h"
using namespace std;

Electronic::Electronic()
{
    brand="NONE";
    warrantyLength=-1;
    deviceType="NONE";
    price=-1;
    quantity=-1;
};
Electronic::Electronic(string newBrand, int newWarrantyLength, string newDeviceType, double newPrice, double newQuantity)
{
    brand=newBrand;
    warrantyLength=newWarrantyLength;
    deviceType=newDeviceType;
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
    brand=newBrand;
}
void setColor(string new_Color)
{
    warrantyLength=newWarrantyLength;
}
void setSize(int new_Size)
{
    deviceType=newDeviceType;
}
Electronic::~Electronic()
{
    brand="NONE";
    warrantyLength=-1;
    deviceType="NONE";
    price=-1;
    quantity=-1;
};