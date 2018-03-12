// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 6 - All problems
#include <iostream>
#include <fstream>
using namespace std;
/*
Algorithim: The whole point of this program is to spell check an entire file and replace incorrect words with correct ones
	1.Load the correct and incorrect words from two files into two arrays
	2.Use the checkword function to see if the inputted test word is from either array of correct words or incorrect ones and keep the word if it is correct, modify it if it is misspelled, or return unknown if its unknown.
	3.The checkphrase function use checkword for a whole line of text from a text file
	4.The checkfile function uses checkphrase to check an entire file and correct it.
It would simply be more conducive to the understanding of the reader to just comment what each of my functions does by single line comments than it would be 
to write a block comment explaining the alogrithim to a bunch of functions at once.
Input paramters: text files
Output: corrected text files
*/
int getWordCount(string s)//I use this function in check phrase because I need to tell the split function how many words to seperate into an array and this determines the size of that array the function was from recitation 5
{
    int word = 1;
    for(int i=0; i < s.length(); i++)
    {
        char foo = s[i];
        
        if(foo == ' ')
        {
            word++;//if it finds a space in a phrase it increments the word count
        }
        
    }
    if(s.length()==0)//if the string is empty there are 0 words
    {word = 0;}
    
    return word;
}
int ReadCorrectWords(string fn, string correctWords[], int size, int stindex)
{

    string ln = "";//declare the line variable
    ifstream fs;
    fs.open(fn);//start the filestream
    
    if(!fs.is_open() || stindex >= size)
    {
        return -1;//if the file didnt open or the starting index is more than or equal to the size return an error
    }
    else
    {
        while(getline(fs,ln))//other wise while get line can get a line from the file stream and put it into the line variable se the index of the correctWords array to the line variable
        {
            if(stindex < size)
            {
                correctWords[stindex] = ln;
                stindex++;
            }
        }
        fs.close();//close the file stream
    }
    return stindex;//return the index you are at which will tell you the amount of correct words in the array



}
int Split(string s, char a, string word[], int size)//split function from recitation 7
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
int ReadMisspelledWords(string fn, string misspelledWords[][2], int rows, int sind)//uses the same process as ReadCorrectWords but with a 2d array
{
    string l = "";//set the line variable
    string word[2];//declare an array to hold the splitted values from the misspelled words file
    ifstream fs(fn);//start the file stream
    if(!fs.is_open()||sind >= rows)
    {
        return -1;//if the index is more than the rows or equal or the file isnt open return an error
    }
    if(fs.is_open() && sind < rows)
    {
        while(sind < rows && getline(fs,l))
        {
            Split(l, '\t', word, 2);
            misspelledWords[sind][0] = word[0];//split each line of the file by tabs to get the wrong word in the second column and the right word in the first one
            misspelledWords[sind][1] = word[1];
            sind++;
        }
        fs.close();
    }
    return sind;//return the index you got to
}
string CheckWord(string word, string correctWords[], int sizeCW, string misspelledWords[][2], int rows)
{
    for(int i=0; i < sizeCW; i++)
    {
        if(word==correctWords[i])
        {
           return word;//use a for loop to check if the inputted word is in the correct words array and return the same word if it is
        }
        
        else
        {
            for(int i=0; i < rows; i++)//use a for loop to check if it is in the misspelled words array and return the correct word if it is
            {
                if(word == misspelledWords[i][0])
                {
                    return misspelledWords[i][1];
                }
            }
        }
    }
    return "unknown";//otherwise return unknown
}
void CheckPhrase(string phrase, string outputFile, string correctWords[], int sizeCW, string misspelledWords[][2], int rows)
{
    int sizeForSplit = getWordCount(phrase);//I use get word count to determine the size of the array for the split function
    if(sizeForSplit <= 0)
    {
        cout << "Phrase is empty. Nothing to write in file." << endl;//if there are 0 words or less somehow in the phrase then say the phrase is empty
        return;
    }
    else
    {
        string splittedPhrase[sizeForSplit];
        Split(phrase, ' ', splittedPhrase, sizeForSplit);//otherwise split the phrase and put it into the splitted phrases array
        for(int i=0; i<sizeForSplit; i++)
        {
           splittedPhrase[i] = CheckWord(splittedPhrase[i], correctWords, sizeCW, misspelledWords, rows);//set the new values of the splittedphrase array to the checkword of the ith index of the old splittedphrase array with the wrong words and everything
        }
        
        ofstream fs;
        fs.open(outputFile, ios::app);//start a file stream in append mode
        
        if(!fs.is_open())
        {
            cout << "Unable to access output file" << endl;//if the file isn't opened give an error and end
            return;
        }
        else
        {
            for(int i=0; i < sizeForSplit; i++)//otherwise input the ith element of the splittedPhrase array with the correct words and stuff into the file
            {
                fs << splittedPhrase[i];
                if(i!=sizeForSplit-1)
                {
                    fs << ' ';//this is to not put a space at the end of the line by checking if it is at the last index of the array
                }
                
            }
            
            fs << endl;//putting the endline and the end of the line
            fs.close();
        }
        
    }
    
    
    
}

void CheckFile(string inputFile, string outputFile, string correctWords[], int sizeCW, string misspelledWords[][2], int rows)
{
    string l = "";    
    ifstream fs(inputFile);//open the input file
    
    if(!fs.is_open())
    {
        cout << "Invalid" << endl;//return an error if it isnt opened
    }
    else
    {
        while(getline(fs, l))//while get line can get a line from the input file...
        {
            if(l.length() > 0)//and as long as that lines length is more than zero 
            {
                CheckPhrase(l,outputFile, correctWords, sizeCW, misspelledWords, rows);//perform the CheckPhrase function on each line 
            }
        }
    }
}

int main()
{

    //test cases
    int sizeCW = 3005;
    string correctWords[3005];
    string misspelledWords[600][2];
    int rows = 600;
    ReadCorrectWords("VALID_WORDS_3000.txt", correctWords, sizeCW, 0);//problem1
    
    ReadMisspelledWords("MISSPELLED.txt", misspelledWords, rows, 0);//problem2

    cout << CheckWord("bbrose", correctWords, sizeCW, misspelledWords, rows) << endl;//problem3
    cout << CheckWord("derrickrose", correctWords, sizeCW, misspelledWords, rows) << endl;

    CheckPhrase("bbrose chieckn bubbls bubbles", "output.txt", correctWords, sizeCW, misspelledWords, rows);
    CheckPhrase("bbrose memes cauler bureau", "output2.txt", correctWords, sizeCW, misspelledWords, rows);//problem4


    CheckFile("testfile.txt", "newfile.txt", correctWords, 3005, misspelledWords, 600);
    CheckFile("testfile2.txt", "newfile.txt2", correctWords, 3005, misspelledWords, 600);//problem5
    return 0;
}