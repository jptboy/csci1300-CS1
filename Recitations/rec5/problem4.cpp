// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 5 - Problem # 4
#include <iostream>
using namespace std;
/*
Algorithim: Gives the last place in a string where a given char occurs
	1.Take the char and the string into the function.
	2.Using a for loop check the ith index of the string until i equals to the length of the string.
	3.If the ith index of the string matches the given char set the counter for where the string last occurs to that specific i value.
	4.Return the value where the char last occurs or return an error if the string is empty.
Input paramters: A char and a string. 
Output:Where that char occurs last in the string
Return: Where that char occurs last in the string
*/
int getLastIndex(char foo, string bar)
{
    int last_index = 0;//set the counter to 0 at first
    char foobar;//redundant code I could just use bar[i] for the if statement whatever..
    
    for(int i=0; i < bar.length(); i++)//use the for loop to set the foobar character to the ith element of the string bar we go up till the string length like all the last cases
    {
        foobar = bar[i];
        if(foobar == foo)//if the ith element of the string is equal to the char we set the counter to the actual i value where bar[i]=foo
        {
            last_index = i;//this is literally setting the last index to the last index where the foo character occurs
        }
    }

    if(bar == "")
    {
        last_index = -1;//return an error if the string is empty
    }

    
    return last_index;//return the count for the last index
}

int main()
{
    cout << getLastIndex('z', "zebra") << endl; //TEST CASE 1
    cout << getLastIndex('a', "anaconda") << endl;//TEST CASE 2
}