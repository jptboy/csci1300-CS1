// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 5 - Problem # 1
#include <iostream>
using namespace std;
/*
Algorithim: Calculates the amount of words in a given string.
	1.Take the string in as input into the getWordCount function.
	2.Check the length of the string, if it is 0 immediately return that there is 0 words in the sentence.
	3.If the length of the string isn't 0 then there has to be one word in the sentence so set the word counter to 1 immediately.
	4.The way we see if there is a new word in the sentece is by checking for spaces.
	5.For every space increase the word counter by 1.
Input paramters: A setence or phrase inputted as a string.
Output: Total word count in the sentence.
Return: Total word count in the sentence.
*/
int getWordCount(string s)
{
    int word = 1;// if there is no error there has to be one word in the sentence, this is the counter btw
    for(int i=0; i < s.length(); i++)// we use this for loop to check the ith element of the string
    {
        char foo = s[i];//redundant code as i could have put s[i] into the if statement but whatever. I set foo to s[i] instead
        
        if(foo == ' ')// if the ith element of the string equals a space then we increase the word counter.
        {
            word++;//increment counter
        }
        
    }
    if(s.length()==0)//if the string has no length then that means that there are 0 words in the sentence
    {word = 0;}
    
    return word;//return the word counter
}
int main()
{
    cout << getWordCount("I went ...") << endl;//TEST CASE 1
    cout << getWordCount("Colorless green ideas dream furiously") << endl;//TEST CASE 2
    return 0;
}