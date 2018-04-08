// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 11 - Problem # 1
#include "solarSystem.h"
#include <iostream>
using namespace std;

solarSystem::solarSystem(string new_name)
{
    numPlanets=0;
    maxNumPlanets=10;
    systemName=new_name;
}


string solarSystem::getName()
{
    return systemName;
}		// return the name of the solar system
int solarSystem:: getNumPlanets()
{
    return numPlanets;
}		// return the number of planets in the system
bool solarSystem::addPlanet(string new_name, float new_radius)
{
    if(numPlanets<9)    
    {
        planet new_planet = planet(new_name,new_radius);
        systemPlanets[numPlanets]=new_planet;
        numPlanets++;
        return true;
    }    
    else
    {
        return false;
    }
}	
planet solarSystem::getPlanet(int idx)
{
    return systemPlanets[idx];
}	// return an object of planet at provided index
float solarSystem::radiusDifference(planet new_planet, planet new_planet2)
{
    float diffrad=new_planet.getRadius()-new_planet2.getRadius();
    return diffrad;
}
solarSystem::~solarSystem()
{
    //ok
}