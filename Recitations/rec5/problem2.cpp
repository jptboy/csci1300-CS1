// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 5 - Problem # 2
#include <iostream>
using namespace std;
/*
Algorithim: Calculates the number of digits in a given string.
	1.Take the string in as a parameter.
	2.Set the number of or counter of digits in the string to 0 at the beginning.
	3.Using a for loop go through the ith entry of the given string to see if each entry is a digit or not.
	4.If the entry is a digit increase the counter by one.
	5.Return the digit counter.
Input paramters: A string to see how many digits there are in.
Output:the number of digits in that string
Return:the number of digits in that string
*/
int getDigitCount(string s)
{
    int digit = 0;//set the digit counter to zero at first
    for(int i = 0; i < s.length(); i++)// we use the for loop to check the ith element of the string
    {
        if(s[i]== '1' || s[i]== '2' || s[i]== '3' || s[i]== '4' || s[i]== '5' || s[i]== '6' || s[i]== '7' || s[i]== '8' || s[i]== '9' || s[i] == '0')// really horrible code because I didn't know you could compare chars that were numbers to real numbres. 
        {
            digit++;//if the ith element of the string is a number increment the counter by 1
        }
    }
    return digit;//return the counter
}
int main()
{
    cout << getDigitCount("a0aaa") << endl;//TEST CASE 1
    cout << getDigitCount("abre1567") << endl;//TEST CASE 2
    return 0;
}