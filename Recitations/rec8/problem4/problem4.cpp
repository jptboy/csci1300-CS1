// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 8 - Problem # 4
#include <iostream>
#include <fstream>
using namespace std;
/*
Algorithim: Gets the number of non empty lines in a file and puts them into an array
	1.Use filestream to read the number of lines in a file with getline
	2.If the length of that line isn't 0 put it into the array and increment the counter
    3.Return the counter or an error
Input paramters: file array and size of the array
Output:arrray with each string from the file or an error
Return:arrray with each string from the file or an error
*/
int getLinesFromFile(string fn, string warr[], int size)
{
    int counter = 0;//init the counter
    ifstream fs(fn);//intialize the filestream object and open the file
    if(!fs.is_open())//if the file isn't open return an error
    {
        counter = -1;
    }
    else//otherwise set the line equal to each line of the file and increment the counter by 1 if it isn't empty
    {
        string l = "";
        while(getline(fs, l))//stops when getline cant get anymore lines
        {
            if(l.length()!=0)
            {
                warr[counter] = l;
                counter++;
            }
        }
        fs.close();//close the file
    }
    
    return counter;
}

int main()
{
    int size = 4;
    string arr[size];
    cout << "There are: "<< getLinesFromFile("testFile.txt", arr, size) << " lines in the file" << endl;//test case 1
    for(int i=0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    int size2 = 4;
    string arr2[size2];
    cout << "There are: "<< getLinesFromFile("emptyLines.txt", arr2, size2) << " lines in the file" << endl;//test case 2
    for(int i=0; i < size2; i++)
    {
        cout << arr2[i] << endl;
    }
    return 0;
}