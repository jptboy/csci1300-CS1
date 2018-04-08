// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 11 - Problem # 1
#include <iostream>
using namespace std;
#ifndef PLANET_H
#define PLANET_H
class planet
{
    public:
        planet();
        planet(string name, float new_rad);

        void setName(string new_name);
        string getName();

        void setRadius(float new_rad);
        float getRadius();

        ~planet();
    private:
        float radius;
        string name;
};
#endif//PLANET_H