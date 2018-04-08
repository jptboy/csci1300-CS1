// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 11 - Problem # 1
#include "planet.h"

planet::planet(){
	radius = 0.0;
}

planet::planet(string planetName, float planetRadius){
	name = planetName;
	radius = planetRadius;
}

planet::~planet(){
	//letting compiler handle deconstruction of the class
}

void planet::setName(string planetName){
	name = planetName;
}

string planet::getName(){
	return name;
}

void planet::setRadius(float planetRadius){
	radius = planetRadius;
}

float planet::getRadius(){
	return radius;
}

