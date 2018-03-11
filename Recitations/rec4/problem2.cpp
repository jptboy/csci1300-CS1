// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 4 - Problem # 2
#include <iostream>
using namespace std;
/*
Algorithim: Returns the next number in a collatz sequence
	1.Take the input number in as an int.
	2.If the number is a even number return half the number.
	3.If hours is odd return 3*number + 1.
Input paramters: int number
Output:next number in sequence
Return: next number in sequence
*/
float collatzStep(int num)//defining the function
{
    float sequence;
    if(num % 2 == 0)//if the number mod 2 is 0 then its even so just return the number divided by 2
    {
        sequence = num/2;
    }
    else
    {
        sequence = (3*num) + 1;//in all other cases meaning when the number is odd set sequence equal to 3 times the number plus 1
    }
    
    return sequence;
}

int main()
{
    int num = 8;
    cout << collatzStep(num) << endl;//test case 1
    
    int num2 = 13;
    cout << collatzStep(num2) << endl;//test case 2
    return 0;
}