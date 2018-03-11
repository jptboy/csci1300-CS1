// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 6 - Problem # 2
#include <iostream>
using namespace std;
/*
Algorithim: Gets the individual integers from a long string of scores.
	1.Use the split function from the first problem to split up the long string into substrings.
	2.Stoi each substring and store it in an array.
    3.Repeat until the value that the split function returns with for loops to fill the array and you are done.
Input paramters: empty array, string and max size of array
Output:integer scores from the string
Return:integer scores from the string
*/
int Split(string s, char a, string word[], int size)
{
    int ctilchar = 0;
    int arrayindex = 0;
    int initseprs = 0;
    int subs = 0;
    int seprs = 0;
    int ctilcharreal = 0;
    
    for(int i=0; i<s.length();i++)
    {
        if(s[i] == a)
        {
            initseprs++;
        }
    }

    if(initseprs > 0)
    {
        seprs = initseprs + 1;
    }



    if(initseprs == 0 && s.length() > 0)
    {
        word[0] = s;
        return 1;
    }
    else
    {
        for(int o = 0; o < seprs; o++)
        {
                for(int i = arrayindex; i <= s.length(); i++)
                    {
                        if(s[i] != a)
                        {
                            ctilchar++;
                            ctilcharreal++;
                        }
                        
                        if(ctilcharreal==s.length())
                        {
                            word[o] = s.substr(arrayindex, ctilcharreal-arrayindex);
                            subs++;
                            break;
                        }
                        
                        if(s[i] == a)
                        {
                            word[o] = s.substr(arrayindex, ctilchar);
                            subs++;
                            arrayindex += ctilchar + 1;
                            ctilchar = 0;
                            ctilcharreal++;
                            break;
                        }
                    }
        }
    }
    return subs;
}

int GetScores(string s, int arr[], int size)
{
    int counter = 0;//start the counter at 0; this counter measures the number of scores put into the array
    string arr2[size];//initialize a second array with the same size as given as a parameter
    
    int rsize = Split(s,' ',arr2,size);//the real size is how many substrings are split in the function
    //also when the function is called it puts the split function into the second array
    
    for(int i=0;i<rsize;i++)
    {
        arr[i]=stoi(arr2[i]);// we stoi the ith value of the second array and put it into the first and increment the counter every time
        counter++;
    }
    return counter;// we return the counter 
}

int main()
{
    int size = 4;
    int arr[size];
    GetScores("12 45 67 89", arr, size);//TEST CASE 1

    for(int i=0; i<size; i++)
    {
        cout << arr[i] << endl;
    }

    int size1 = 5;
    int arr1[size1];
    GetScores("213 -4325 -67 8923 -12312312", arr1, size1);//TEST CASE 2

    for(int i=0; i<size1; i++)
    {
        cout << arr1[i] << endl;
    }
    return 0;
}