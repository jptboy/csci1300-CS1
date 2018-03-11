// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 6 - Problem # 1
#include <iostream>
using namespace std;
/*
Algorithim: Splits a string and puts its subsections into an array
	1.Find how many seperators there are in the string and add 1 to it if there are more than 1 and store it in a variable that we will call foo
	2.Repat foo times if there are actual seperators
        1.Count till the seperator character or the end of the string and put all of the chars leading up to the seperator in the array when the seperator or the end of the string is reached
        2.Increment the position within the string to make sure you arent at the end
    3.The array is filled with the subsections of the long string
Input paramters: empty array to fill with the subsections of a long string seperated by a character that is also an input. Size is also given for no reason
Output:An array filled with the subsections of the string
Return:An array filled with the subsections of the string
*/
int Split(string s, char a, string word[], int size)
{
    int ctilchar = 0;//counts the number of chars until the seperator character
    int arrayindex = 0;//keeps position in the string
    int initseprs = 0;// the initial amount of seperators
    int subs = 0;// used to count the number of substrings
    int seprs = 0;// if there is actually a seperator then we increment initseprs by 1 to get seprs otherwise seprs stays 0
    int ctilcharreal = 0;//is used to see if we are at the end of the string 
    
    for(int i=0; i<s.length();i++)
    {
        if(s[i] == a)
        {
            initseprs++;//if there are seperators then increment init seprs by that amount
        }
    }

    if(initseprs > 0)
    {
        seprs = initseprs + 1;//if init seprs is more than 0 than the real amount of seperators needs to be one more than that for my algorithim
    }



    if(initseprs == 0 && s.length() > 0)//if init seprs is 0 and the string has a length then we just put the string into the 0th index of the  array so we return one subsection
    {
        word[0] = s;
        return 1;
    }
    else
    {
        for(int o = 0; o < seprs; o++)//repeat the outer for loop until the number of seperators is reached
        {
                for(int i = arrayindex; i <= s.length(); i++)
                    {
                        if(s[i] != a)
                        {
                            ctilchar++;//if the ith char of the string isnt the seperator increase the count till char value because thats the purpose of that var
                            ctilcharreal++;//we always increase this to determine our position in the string
                        }
                        
                        if(ctilcharreal==s.length())
                        {
                            word[o] = s.substr(arrayindex, ctilcharreal-arrayindex);//if we reach the end of the string then we put whatever was before that into the array
                            subs++;//increment the number of substrings put into the array
                            break;
                        }
                        
                        if(s[i] == a)
                        {
                            word[o] = s.substr(arrayindex, ctilchar);//if the ith character is the seperator then we make whatever was before that a substring and put it into the array
                            subs++;//increment the amount of substrings put into the array
                            arrayindex += ctilchar + 1;//increment this; its like the cutters arm that would hold your arm while the cutters other arm used a sword to cut it idk how else to explain this
                            ctilchar = 0;//reset the counter till the seperator to 0
                            ctilcharreal++;//we always increase this
                            break;
                        }
                    }
        }
    }
    return subs;// return the number of substrings put into the array
}

int main()
{
	int size = 4;
	string word[size];
	Split("12 -45 67 -89 ", ' ' ,word, size);//TEST CASE 1

    for(int i=0; i<size; i++)
    {
        cout << word[i] << endl;
    }

    int size1 = 5;
	string word1[size1];
	Split("sadfads,asdfas,dddff,ererere,adasdfas ", ',' ,word1, size1);//TEST CASE 2

    for(int i=0; i<size1; i++)
    {
        cout << word1[i] << endl;
    }

	return 0;
}
