// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 2 - Problem # 3
#include <iostream>
using namespace std;
float carnot(float TC, float TH);//declaring the carnot function

/*
Algorithim: that finds the carnot efficency between two heat engines
	1.Take the temperature of the two reserivors as parameters into the carnot() function.
	2. Divide the temperature of the first resirvor by the second and the subtract from 1.
	3. Return the carnot efficency.
Input paramters: Temperature of two heat engines (float type)
Output: float that is the carnot efficency
Return: float that is the carnot efficency
*/

int main()// defining the main function
{
    cout << carnot(160, 1100) << endl;//TEST CASE 1: 160 degrees and 1100 degrees as the parameters
    cout << carnot(260, 673) << endl;//TEST CASE 2: 260 degrees and 673 degrees as the parameters

    return 0;// main function has to return 0
}

float carnot(float TC, float TH)// definition of the carnot function that takes in two temperatures as parameters
{
    float n = 1 - (TC/TH);// finding the carnot effincency
    return n;// returning the carnot efficency
}