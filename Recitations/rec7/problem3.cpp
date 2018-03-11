// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 6 - Problem # 3
#include <iostream>
using namespace std;
/*
Algorithim: Fills a 2d arrays with the sum of its indicies of its rows and columns
	1.Traverse the arrays rows with the outer for loop and traverse each of the intersections with an inside for loop and set the [i][m]th index to the sum of i + m
	2.Do this till the number of rows is reached in the outside for loop.
Input paramters: empty array
Output:Array with sum of matrix indexes
Return:Array with sum of matrix indexes
*/
void fillMatrix(int r2matr[][4], int size)
{
    for(int m=0; m < 4; m++)//we traverse the rows with this
    {
        for(int i=0; i < size; i++)//we go horizontally through the rows with this
        {
            r2matr[i][m] = i+m;//set the [i][m]th index to the sum of i and m
        }
    }
}

int main()
{
    int size = 4;
    int matr[size][4];
    fillMatrix(matr, size);

    for(int m=0; m < 4; m++)
    {
        for(int i=0; i < size; i++)
        {
            cout << "Value at Column: " << i <<" Row: " << m << " is " << matr[i][m] << ". "; //TEST CASE 1
        }
        cout << endl;
    }

    cout << endl;

    int size1 = 1;
    int matr2[size1][4];
    fillMatrix(matr2, size1);

    for(int m=0; m < 4; m++)
    {
        for(int i=0; i < size1; i++)
        {
            cout << "Value at Column: " << i <<" Row: " << m << " is " << matr2[i][m] << ". "; //TEST CASE 2
        }
        cout << endl;
    }


    return 0;
}