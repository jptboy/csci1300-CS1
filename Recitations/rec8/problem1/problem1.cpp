// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 8 - Problem # 1
#include <iostream>
#include <fstream>
using namespace std;
/*
Algorithim: Checks if a file has been opened properly
	1. Create a filestream and input the file into the filestream
    2. If the file has been opened return true otherwise return false
Input paramters: file
Output:Whether or not the file has been opened properly
Return:Whether or not the file has been opened properly
*/
bool checkFile(string fn)
{
    
    ifstream myFileStream;
    myFileStream.open(fn);//initialize the filestream object and open the file
    if (myFileStream.is_open())
    {
        myFileStream.close();//if the file opened return true
        return true;
    }
    else
    {
        return false;//otherwise return false
    }
}

int main()
{
    string fn = "Q1_myfile.txt";
    cout << checkFile(fn) << endl;//test case 1

    string fn2 = "hi.txt";
    cout << checkFile(fn2) << endl;//test case 2

    return 0;
}