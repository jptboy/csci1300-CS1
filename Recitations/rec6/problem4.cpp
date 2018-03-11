// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 6 - Problem # 4
#include <iostream>
using namespace std;
/*
Algorithim: Replaces the inner elements of an array that is longer or equal to 3 by the highest number on either side.
	1.Take the integer array and length of that array as input into the function.
	2.Only do the algorithim if the array is more than length 3.
	3.Make another array to store the new values in depending on which value is higher on the right or left side.
	4.Using a for loop put the new values of the ith elements of arr[length] into arr2[length] we use a second array to not mess up the algorithim
    5.Put the values of arr2[length] back into arr[length] using a for loop
Input paramters: An array and its length.
Output:An new array that has the highest adjacent element to the inner values of the original array ... hard to articulate this
Return: An new array that has the highest adjacent element to the inner values of the original array
*/
void replaceNums(int arr[], int length)
{
    int arr2[length];//initialize the second array
    
    if(length >= 3)//only do the algorithim if the length is more than three otherwise it doesnt make sense
    {
        arr2[0] = arr[0];//set the first element of the real array to the first element of the holder
        arr2[length-1] = arr[length - 1];//do the same thing as above but with the last elements
        
        for(int i = 1; i < length -1; i++)//from the second element of the real array to the one before the last...
        {
            if(arr[i-1] > arr[i+1])//if the left element is bigger put that as the ith value into the holder array
            {
                arr2[i] = arr[i-1];
            }
            else if(arr[i+1] > arr[i-1])//if the right element is bigger put that as the ith value into the holder array
            {
                arr2[i] = arr[i+1];
            }
        }
        
        for(int i = 0; i < length; i++)
        {
            arr[i] = arr2[i];//fill the real array back up with the new values from the holder array
        }
    }
}

int main()
{
    int myArray[3] = {1,2,3};
    replaceNums(myArray, 3);
    cout << "Test Case 1 Array Printed:" << endl;    //TEST CASE 1
    for(int i = 0; i < 3; i++)
    {
        cout << myArray[i] << " "; //use a for loop to print out the result of the test case
    }
    cout << endl;



    int myArray2[5] = {1,2,3234,5,5342};
    replaceNums(myArray2, 5);
    cout << "Test Case 2 Array Printed:" << endl;   //TEST CASE 2
    for(int i = 0; i < 5; i++)
    {
        cout << myArray2[i]<< " "; //use a for loop to print out the result of the test case
    }
    cout << endl;



    return 0;
}