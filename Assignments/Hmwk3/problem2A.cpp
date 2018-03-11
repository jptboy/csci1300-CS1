// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 4 - Problem # 2A

#include <iostream>
#include <math.h>
using namespace std;

float windChillCalculator(float T, float V);
/*
Algorithim: find the wind chill
	1. The windchill values are already put into the functionc call in the main,
	2. It calculates it in one line. float windChill = (35.74) + (0.6215*T) - (35.75*(pow(V,0.16))) + (0.4275*T*(pow(V,0.16)));
	3. It returns the wind chill.
Input paramters: Temperature and wind speed
Output: Wind chill in degrees Fahrenheit
Return: Wind chill in degrees Fahrenheit
*/
int main()
{
    cout << windChillCalculator(30.0,5.2) << endl;//test case 1
    cout << windChillCalculator(-30.7,5.0) << endl;//test case 2
    return 0;
}


/*
I really love how moodle just completely breaks if you use doubles insteads of floats for your data types. g++ also compiled this differently on c9 and my linux install
than moode complied it. Talking about problem2 as a whole. Really annoying when you aren't actually wrong but are forced to somehow guess which coding style to adhere to.
*/

float windChillCalculator(float T, float V)//function definition
{
    if(V>=0)// if the wind speed is more than 0 it calculates hte wind chill otherwise gives and error
    {
        float windChill = (35.74) + (0.6215*T) - (35.75*(pow(V,0.16))) + (0.4275*T*(pow(V,0.16)));//using the formula I found on moodle to calculate the windchill
        return windChill;//returning the windchill
    }
    else//error message if windspeed isn't 0 or more than 0
    {
        cout << "Not applicable" << endl;
        return 0;
    }

}