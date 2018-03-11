// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 4 - Problem # 2B

#include <iostream>
#include <math.h>
using namespace std;

float windChillCalculator(float T, float V);
void printWindChill(float T,float low_wind_speed,float high_wind_speed,float wind_speed_step);
/*
Algorithim: that tests the windchill at a certain temperature for different wind speeds up to a certain max
	1.Set the wind speed temperature max ceiling for wind speed and step in the function call in the main.
	2. If the wind speed step is lower than 0 or the lower ceiling is higher than the upper give an error.
	3. Using a for loop generate the windchill statement for each wind speed up until the max.
Input paramters: float Temperature float Windspeed lower ceiling float Windspeed upper ceiling float increment value
Output: Statement that is the wind chill for that given range and given parameters
Return: Statement that is the wind chill for that given range and given parameters
*/
int main()
{
    printWindChill(-17, 86, 103, 2.83333);//test case 1
    printWindChill(13.0, 20.678, 30.99, 2);//test case 2

    return 0;
}

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

void printWindChill(float T, float low_wind_speed, float high_wind_speed,float wind_speed_step)//function definition
{
    if(low_wind_speed > high_wind_speed || wind_speed_step < 0)// if the lower ceiling is higher than the upper or the step is less than 0 give an error
    {
        cout << "Invalid input" << endl;
    }
    else
    {
        for(float i = low_wind_speed;i <= high_wind_speed;i=i+wind_speed_step)// initialize the variable i as the low wind speed and go up to the high wind speed incrementing by the wind speed step and stop when more than the higher ceiling
        {
            cout << "The wind chill is " << windChillCalculator(T,i) << " degrees F for an air temperature of " << T << " degrees F and a wind speed of " << i << " mph." << endl;
            //above input the i values from the for loop into the statement and the calculator function to calcuate the windchill for each wind speed
        }
    }
}
