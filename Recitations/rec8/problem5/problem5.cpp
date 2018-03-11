// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 8 - Problem # 5
#include <iostream>
#include <fstream>
using namespace std;
/*
Algorithim: Prints the average for a set of string numbers and a name from an array
	1.Only modify the file if the number of digits isn't set to a negative number.
	2.Use stod to convert the string values to doubles and put them into a second array.
    3.Put the last element of the array as the name variable.
    4.Use the second array and for loops and filestream to insert the values from the second array into the text file and finally filestream the name in.
Input paramters: data array of strings a file number of digits in the data and the size of the data array
Output:text file with the average and the name
Return:text file with the average and the name
*/
void saveData(string fileName, string data[], int n, int size)
{
    if(n>=0)//only proceed if the number of digits isn't -1 because the function still works with n equals 0 meaning that the name exists
    {
        ofstream fs;//initialize filestream object
        fs.open(fileName);//use the open method to open the file
        
        double arr[size-1];//initialize the second array that will be 1 less than the size of the first one bceause it doesn't hold the name
        double m=0;//used to store the addition of the numbers up
        double average = 0;//self explaintory
    
        for(int i=0; i < size-1; i++)
        {
            arr[i] = stod(data[i]);//stod the values into the second array with a for loop
        }
        
        for(int i=0; i< size-1;i++)
        {
            m+=arr[i];
            average = m/(size-1);//calculate the average value of the doubles inside of the second array
        }
        
        fs << "Name: " << data[n] << endl;//file stream the name in
        fs <<"Avg: " <<average;//file stream the average in
        fs.close();//close the file
    }
}

int main()
{
    string data[4] = {"3.2", "-1.1", "0.4", "Manzoni"}; //test case 1
    string filename = "my_data2.txt";
    saveData(filename, data, 3, 4);

    string data2[6] = {"1.11","0.13","5.22", "5", "6", "Foscolo"};//test case 2
    string filename2 = "my_data3.txt";
    saveData(filename2, data2, 5, 6);
    
    return 0;
}