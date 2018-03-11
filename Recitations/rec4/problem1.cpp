// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 4 - Problem # 1
#include <iostream>
using namespace std;
/*
Algorithim: Calculates the payrate accounting for overtime
	1.Take the hours worked and the payrate as inputs that are floats.
	2.If the hours worked is more than 40 use the special algoritihm which multiplies the extra overtime hours by 1.5 times the pay and adds it to the regular pay times 40.
	3.If hours is negative or payrate is negative give error.
	4.If hours is less than 40 and more than 0 use the regular algorithim.
	5.Print the total pay for that period.
Input paramters: float hours worked and float payrate
Output:total paycheck
Return: total paycheck
*/
void calcPay(float hours, float payrate) //defining of the calcPay function
{
    float pay;//define pay variable
    if( hours < 0 || payrate < 0)// if pay is negative or hours is negative give an error
    {
        cout << "Pay rate and hours worked cannot be negative values." << endl;
    }
    else if(hours >= 40)// If hours worked is more than 40 find the total pay for 40 hours and add it to the overtime hours times 1.5 the pay.
    {
        pay = ((hours-40) * 1.5 * payrate)+((40)*payrate);
        cout << "Your pay is $" << pay << "." << endl;
    }
    else if(hours < 40 && hours > 0)//If the hours are less than 40 but more than 0 calculate the normal pay.
    {
        pay = hours * payrate;
        cout << "Your pay is $" << pay << "." << endl;
    }
    else if(hours == 0)// if the pay is 0 return a value of 0
    {
        pay = hours * 0 * payrate;
        cout << "Your pay is $" << pay << "." << endl;
    }
}

int main()
{
    float hours = 40.1;
    float payrate = 5.5;
    calcPay(hours,payrate); //test case 1
    
    float hours2 = 20;
    float payrate2 = 10.5;
    calcPay(hours2,payrate2);//test case 2
    return 0;
}