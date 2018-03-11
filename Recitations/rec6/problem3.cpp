// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 6 - Problem # 3
#include <iostream>
using namespace std;
/*
Algorithim: Prints the sum of the values in an array of integers
	1.Take the array and the length of the array into the function.
	2.Set a holder variable and a current variable to 0.
	3.Using a for loop set the holder to the ith element of the array and increment the current variable by the holder until i is one less than the length of the array.
	4.Return the holder variable.
Input paramters: An array and the length of that array as an integer.
Output:The sum of all the elements in that array.
Return: The sum of all the elements in that array.
*/
int getArraySum(int arr[], int length)
{
    int holder = 0;//set holder variable
    int current = 0;//set current variable to 0 to avoid memory corruption
    
    for(int i = 0; i < length; i++)
    {
        holder = arr[i];// using a for loop from the first value of the array to the last increment the current variable by the holder variable which is the ith element of the array
        current += holder;//that is the definition of a sum
    }
    return current;//return the sum
}

int main()
{
    int myArray[3] = {1,2,3};
    cout << getArraySum(myArray, 3) << endl;//TEST CASE 1

    int myArray2[3] = {3,23,234};
    cout << getArraySum(myArray2, 3) << endl;//TEST CASE 2

    return 0;
}