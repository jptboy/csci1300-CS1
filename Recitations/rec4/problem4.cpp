// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 4 - Problem # 4
#include <iostream>
using namespace std;
/*
Algorithim: prints the multiples of a function until a max is reached
	1.Take the max and the number to be multiplied as integers.
	2.Create a storage variable called num and store the parameter to be multiplied inside.
	3.Output the number storage variable and then add the parameter to it which is basically multiplication.
	4.Repeat until the storage variable is more than the max parameter.
Input paramters: Number to be multiplied and the max to not be exceeded.
Output:multiple of the number 
Return:multiple of the number
*/
void printMultiples(int parameter, int param_max)
{
    int num = parameter;//creating storage variable to store the parameter at first and all its multiples
    while (num <= param_max)// the loop executes until the storage variable exceeds the passed in max parameter variable
    {
        cout << num << endl;//print out the storage variable
        num += parameter;//add the number whose multiples are being printed out to the storage variable
    }
}

int main()
{
    int parameter = 2;//test case 1
    int max = 10;
    printMultiples(parameter, max);
    
    int parameter2 = 4;//test case 2
    int max2 = 17;
    printMultiples(parameter2, max2);
    return 0;
}