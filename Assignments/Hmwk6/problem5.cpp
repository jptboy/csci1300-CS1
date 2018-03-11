#include <iostream>
#include <fstream>
using namespace std;

int getWordCount(string s)
{
    int word = 1;
    for(int i=0; i < s.length(); i++)
    {
        char foo = s[i];
        
        if(foo == ' ')
        {
            word++;
        }
        
    }
    if(s.length()==0)
    {word = 0;}
    
    return word;
}
int ReadCorrectWords(string fn, string correctWords[], int size, int stindex)
{

    string ln = "";
    ifstream fs;
    fs.open(fn);
    
    if(stindex >= size)
    {
        return -1;
    }
    if(!fs.is_open() || stindex > size)
    {
        return -1;
    }
    else
    {
        while(getline(fs,ln))
        {
            if(stindex < size)
            {
                correctWords[stindex] = ln;
                stindex++;
            }
        }
        fs.close();
    }
    return stindex;



}
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
int ReadMisspelledWords(string fn, string misspelledWords[][2], int rows, int sind)
{
    string l = "";
    string word[2];
    ifstream fs(fn);
    if(!fs.is_open()||sind >= rows)
    {
        return -1;
    }
    if(fs.is_open() && sind < rows)
    {
        while(sind < rows && getline(fs,l))
        {
            Split(l, '\t', word, 2);
            misspelledWords[sind][0] = word[0];
            misspelledWords[sind][1] = word[1];
            sind++;
        }
        fs.close();
    }
    return sind;
}
string CheckWord(string word, string correctWords[], int sizeCW, string misspelledWords[][2], int rows)
{
    for(int i=0; i < sizeCW; i++)
    {
        if(word==correctWords[i])
        {
           return word;
        }
        
        else
        {
            for(int i=0; i < rows; i++)
            {
                if(word == misspelledWords[i][0])
                {
                    return misspelledWords[i][1];
                }
            }
        }
    }
    return "unknown";
}
void CheckPhrase(string phrase, string outputFile, string correctWords[], int sizeCW, string misspelledWords[][2], int rows)
{
    int sizeForSplit = getWordCount(phrase);
    if(sizeForSplit <= 0)
    {
        cout << "Phrase is empty. Nothing to write in file." << endl;
        return;
    }
    else
    {
        string splittedPhrase[sizeForSplit];
        Split(phrase, ' ', splittedPhrase, sizeForSplit);
        for(int i=0; i<sizeForSplit; i++)
        {
           splittedPhrase[i] = CheckWord(splittedPhrase[i], correctWords, sizeCW, misspelledWords, rows);
        }
        
        ofstream fs;
        fs.open(outputFile, ios::app);
        
        if(!fs.is_open())
        {
            cout << "Unable to access output file" << endl;
            return;
        }
        else
        {
            for(int i=0; i < sizeForSplit; i++)
            {
                fs << splittedPhrase[i];
                if(i!=sizeForSplit-1)
                {
                    fs << ' ';
                }
                
            }
            
            fs << endl;
        }
        
    }
    
    
    
}

void CheckFile(string inputFile, string outputFile, string correctWords[], int sizeCW, string misspelledWords[][2], int rows)
{
    string l = "";    
    ifstream fs(inputFile);
    
    if(!fs.is_open())
    {
        cout << "Invalid" << endl;
    }
    else
    {
        while(getline(fs, l))
        {
            if(l.length() > 0)
            {
                CheckPhrase(l,outputFile, correctWords, sizeCW, misspelledWords, rows);
            }
        }
    }
}

int main()
{
    return 0;
}