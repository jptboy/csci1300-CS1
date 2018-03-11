// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 8 - Problem # 3
#include <iostream>
#include <fstream>
using namespace std;
/*
Algorithim: gets the number of lines in a file
	1.Use file stream to open the file and if it is opened do the rest of the algorithim.
	2.While getline can get the lines of the text file put each line into the variable called line
    3.Increment the counter everytime you can do this and return it
Input paramters: file
Output:integer that tells you how many lines there are in the file or an error
Return:integer that tells you how many lines there are in the file or an error
*/
int fileLoadRead(string fn)
{
    int counter = 0;//init the counter
    ifstream fs;//init the filestream object
    fs.open(fn);//open the file name
    
    if(!fs.is_open())
    {
        counter = -1;//return error if it didn't open
    }
    else
    {
        string line = "";
        while(getline(fs, line))
        {
            counter++;
        }
        fs.close();//as long as getline can get a line increment the counter by 1
    }
    
    return counter;
}
int main()
{
    cout << fileLoadRead("empty.txt") << endl;//test case 1
    cout << fileLoadRead("testFile2.txt") << endl;//test case 2
    return 0;
}