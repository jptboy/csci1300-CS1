#include <iostream>
#include <fstream>
using namespace std;

int ReadCorrectWords(string fn, string correctWords[], int size, int stindex)
{
    string ln = "";
    int ic = stindex;
    ifstream fs;
    fs.open(fn, ios::app);
    if(fs.is_open())
    {
        while(getline(fs,ln))
        {
            correctWords[ic] = ln;
        }
    }
    return 0;
}

int main()
{
    return 0;
}