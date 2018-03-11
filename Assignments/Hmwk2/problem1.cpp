// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 2 - Problem # 1
#include <iostream>
using namespace std;
int population(int currentpopulation); // declaring the population function
/*
Algorithim: that finds the change in population in one year.
	1.Take the current population passed into the function through the "currentpopulation" variable.
	2.Take the number of seconds in a year and divide by the amount of deaths, births, and new immgigrants per second to calculate the total deaths, births, and immigrants in a year.
	3. Add the total number of births and immgigrants to the current population and subtract the number of deaths.
	4. Return the population after a year to the main function which prints it out.
Input paramters: Current population (int type)
Output: integer that is the population after one year
Return: integer that is the population after one year
*/

int main()//defining the main function
{
	cout << population(0) << endl; // TEST CASE 1:printing out the population after one year starting from 0
	cout << population(12365478) << endl;// TEST CASE 2:printing out the population after one year starting from 12355478
	return 0;// main function has to return 0
}

int population(int currentpopulation)//definition of the population function that takes in the current population and adds the total births and immigrants and subtracts the deaths to calculate the population after one year
{
	int secondsinYear = 31536000;// defining the number of seconds there are in a year
	int births = secondsinYear/8;// calculating the total number of births in a year by dividing the number of seconds in a year by the birth rate per second
	int deaths = secondsinYear/12;// calculating the total number of deaths in a year by dividng the number of seconds in a year by the death rate per second
	int immigrant = secondsinYear/33;// calculating the total number of new immgirants per year by dividing the total number of seconds in a year by the new immigrant rate
	int population = currentpopulation + births + immigrant - deaths;// adding the total number of births and new immigrants to the currentpopulation passed into the function and then subtracting the number of deaths to calculate the population after one year
	return population; // returning the population after one year
}

