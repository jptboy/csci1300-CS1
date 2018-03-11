// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 6 - Problem # 2
#include <iostream>
using namespace std;
/*
Algorithim: Prints all the elements in an array of integers
	1.Take the array and the length of the array in as parameters.
	2.Using a for loop print out the ith element of the array and start a new line
Input paramters: An array of ints and the length of the array
Output: The values in that array printed from beginning to end
Return: The values in that array printed from beginning to end
*/
void printValues(int myArray[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << myArray[i] << endl;//using a for loop print the ith element of the array until the last element is reached
    }
}

int main()
{
    int myArray[3] = {1,2,3};
    printValues(myArray, 3);//TEST CASE 1

    int myArray2[3] = {3,23,234};
    printValues(myArray2, 3);//TEST CASE 2

    return 0;
}