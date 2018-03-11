// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 6 - Problem # 4
#include <iostream>
using namespace std;
/*
Algorithim: Prints a flood map by comparing the values of a 2d array to a double and if its lower or equal it prints an star otherwise if it is higher it prints an o 
	1.Take the array and the number of rows in the array in as parameters along with the water level.
	2.Go through each of the rows with a for loop and see the value at each intersection of the columns and the rows with nested for loops;
	3.If it is flooded print an o.
	4.If it is not compiled print an *.
Input paramters: 2d array with water levels the water threshold and the number of rows in the 2d array
Output:Flood Map
Return: Flood Map
*/
void floodMap(double r2matr[][4], int rows, double wlvl)
{
    for(int m=0; m<rows; m++)//traverse the rows with this
    {
        for(int i=0; i<4;i++)//go horizontally through the rows with this
        {
            if(r2matr[m][i] <= wlvl)//if the [i][m]th index is less than or equal to the water level then cout a *
            {
                cout <<"*";
            }
            else//couting an o for visibility because underscores look invisible
            {
                cout << "o";//if the [i][m]th index is more than the water level than cout an o
            }
        }
        
        if(m==3)
        {
            break;//once on the third row break the other for loop so we dont have an uncessecary endl character. idk why i did this it wasnt even necessary
        }
        cout << endl;
    }
}

int main()
{
    double map[4][4] = {{5.9064, 15.7541, 6.11483, 11.3928},
                        {16.8498, 5.736, 9.33342, 6.36095},
                        {3.18645, 16.935, 4.7506, 9.63635},  //TEST CASE 1
                        {2.22407, 0.815145, 0.298158, 13.466}};

    floodMap(map, 4, 9.3);
    cout << endl << endl;
    double map1[4][4] = {{0, 1, 2, 3},
                        {4, 5, 6, 7},
                        {8, 9, 10, 11},
                        {12, 13, 14, 15}};//TEST CASE 2
    floodMap(map1, 4, 5.5);

    cout << endl;
    return 0;
}