// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 5 - Problem # 3
#include <iostream>
using namespace std;
/*
Algorithim: Calculates the number of times a substring occurs a longer string
	1.Take both parameters in as strings.
	2.Return an error if the substring or the long string is empty or if the substring is longer than the long string.
	3.If there is no error move onto the real algoritihm.
	4.Using the substring function check from the ith element of the string to the ith+2 element of the string and create a substring from that.
	5.If the substring from step 4 matches the given substring increment the counter by 1.
    6.Return the value of the counter.
Input paramters: a substring and a longer string 
Output:The number of times the given substring occurs in the longer string
Return: The number of times the given substring occurs in the longer string
*/
int getMatchCount(string substr, string longstr)
{
    int count = 0;//set the counter to 0 at first
    string foo;//this is the string that I use to store the different substrings from the longer string in
    
    if(longstr.length() == 0 || substr.length()==0)// if either the long string has no length or the shorter string has no length we return an error
    {
        return -1;
    }
    else if(substr.length() > longstr.length())//we return an error if the substring is longer than the string that is supposed to be long
    {
        count = -2;
    }
    else//if there is no error we move onto the real algoritihm
    {
        for(int i = 0; i < longstr.length(); i++)//we again use the for loop to increment i for counting purposes
        {
            foo = longstr.substr(i, substr.length());//from i to essentially i+substr.length() or the length of the substring we make the foo container string that substring
            if(foo==substr)// if the container string foo is equal to the given substring we increment the counter by 0
            {
                count++;//incrementing the counter
            }
        }
        
    }
    
    
    return count;//return the counter
}

int main()
{
    cout << getMatchCount("he","hellohello") << endl;//TEST CASE 1
    cout << getMatchCount("abcdef","ab") << endl;//TEST CASE 2
    return 0;
}