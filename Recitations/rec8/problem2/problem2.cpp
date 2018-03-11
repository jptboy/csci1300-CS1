// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 8 - Problem # 2
#include <fstream>
#include <iostream>
using namespace std;
/*
Algorithim: Writes the squares for 1-10 in a text file
	1.Create a filestream and input the target file into the filestream even if it doesnt exist
	2.Use a for loop and the stream insertion operator to insert the i^2 value into the file stream for i=1 through i=10
    3.Returns whether or not it worked
Input paramters: file
Output:modified file
Return:integer that tells you whether or not it worked
*/
int fileLoadWrite(string fn)
{
    ofstream fs;//init the filestream object
    fs.open(fn);//open the file
        if(fs.is_open())
        {
            for(int i=1; i<=10; i++)
            {    
                fs << i*i << endl;//insert i*i into each line of the file
            }
            fs.close();//close the file
            return 0;
        }
        else{return -1;}
}

int main()
{
    string fn = "problem2.txt";//test case 1
    fileLoadWrite(fn);

    string fn2 = "problem2(1).txt";//test case 2
    fileLoadWrite(fn2);
    return 0;
}