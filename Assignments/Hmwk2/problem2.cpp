// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 2 - Problem # 2

#include <iostream>
using namespace std;
void howLong(int secondsInput);// declaration of the howLong function

/*
Algorithim: that finds the change in population in one year.
	1.The function takes the total number of seconds as the secondsInput variable.
	2.Take the total number of seconds and divide by 86400 to calculate the number of days.
	3. Take the total number of seconds from the secondsInput variable and do the modulus of it with 86400 to figure out the input for the calculation for the hours.
    4. Take the number of seconds left after step 3 and divide by 3600 to figure out the hours.
    5. Take the modulus of the hours input with 3600 to figure out the remaining seconds for the minutes calculation.
    6. Take the amount from step 5 and divide by 60 to figure out the number of minutes.
    7. Take the mod of the input for step 5 with 60 to figure out the number of seconds left.
Input paramters: Seconds to be converted into conventional time (int type)
Output: nothing
Return: Conventional time string saying x days x hours and so on.
*/

int main()//defining the main function
{
    howLong(0);//TEST CASE 1: 0 seconds
    howLong(70000);//TEST CASE 2: 70,000 seconds
    return 0;// main function has to return 0
}

void howLong(int secondsInput)// definition of the howLong() function
{
    int days = secondsInput/86400;//taking the total number of seconds inputted and dividing by 86400 to find the days
    int hoursinput = secondsInput%86400;// taking the total number of seconds and seeing the remainder of dividing it by 86400 in order to get the input for the hours calculation
    int hours = hoursinput/3600;// dividing the hoursinput by 3600 to calculate the number of hours
    int minutesinput = hoursinput%3600;// finding the remainder from the previous calculation to calculate the minutesinput for the minutes calculation
    int minutes = minutesinput/60;// calculating the number of minutes
    int secondsinput = minutesinput%60;// finding the left over seconds
    int seconds = secondsinput;
    
    cout << secondsInput << " seconds is " << days << " days, " << hours << " hours, " << minutes << " minutes, and " << seconds << "  seconds." << endl; //this void function prints out the results of its calculations
}