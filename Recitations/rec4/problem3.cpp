// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 4 - Problem # 3
#include <iostream>
using namespace std;
/*
Algorithim: Prints all the even numbers less than a certian max.
	1.take the max number as a parameter that is an integer.
	2.Create a for loop and initialize a counter i. As long as i is less than or equal to the max output i and then increment it by two and repeat until i surpasses the max.
	3. This does the algoritihim
Input paramters: max number
Output:every even number before that number
Return: every even number before that number
*/
void printEvenNums(int max)
{
    for (int i=2;i<=max;i=i+2)//Create a for loop and initialize a counter i. As long as i is less than or equal to the max output i and then increment it by two and repeat until i surpasses the max.
    {
        cout << i << endl;
    }// if i is negative or 0 the loop never has the condition to start
    
    /*int i=2;
    while(i<=max)
    {
        cout << i << endl;
        i = i+2;
    }*/ //other way to do it with a while loop
    
}

int main()
{
    //int x;
    //cin >> x;
    //printEvenNums(x);
    printEvenNums(8);//test case 1
    printEvenNums(9);//test case 2
    return 0;
}