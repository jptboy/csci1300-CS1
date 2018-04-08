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

string Electronic::getBrand()
{
    return brand;
}
int Electronic::getWarrantyLength()
{
    return warrantyLength;
}
string Electronic::getdeviceType()
{
    return deviceType;
}

void Electronic::setBrand(string newBrand)
{
    brand=newBrand;
}
void Electronic::setWarrantyLength(int newWarrantyLength)
{
    warrantyLength=newWarrantyLength;
}
void Electronic::setDeviceType(string newDeviceType)
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