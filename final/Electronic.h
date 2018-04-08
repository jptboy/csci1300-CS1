#ifndef ELECTRONIC_H
#define ELECTRONIC_H
#include "Item.h"
#include <iostream>
using namespace std;
class Electronic: public Item, protected Item
{
    public:
        Electronic();
        Electronic(string newBrand, int newWarrantyLength, string newDeviceType);

        string getBrand();
        int getWarrantyLength();
        string getdeviceType();

        void setBrand(string newBrand);
        void setWarrantyLength(int newWarrantyLength);
        void setDeviceType(string newDeviceType);

        ~Electronic();
    private:
        string brand;
        int warrantyLength;
        string deviceType;
};
#endif//ELECTRONIC_H