// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 11 - Problem # 1
#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <string>
#include <iostream>
#include "planet.h"
using namespace std;

class solarSystem{
	public:
		solarSystem(string);
		~solarSystem();

		float radiusDifference(planet new_planet, planet new_planet2);
		string getName();			// return the name of the solar system
		int getNumPlanets();		// return the number of planets in the system
		bool addPlanet(string, float);	//Adds a single planet to solar system
        planet getPlanet(int);  	// return an object of planet at provided index

	private:
		int maxNumPlanets; // This should be initialized to 10 in the constructor
		string systemName;
		int numPlanets;
		planet systemPlanets[10]; // array of object planet, each obj is a planet
		
};
#endif // SOLAR_SYSTEM_H
