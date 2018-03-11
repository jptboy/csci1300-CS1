// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 5 - Problem # 1
#include <iostream>
using namespace std;
/*
Algorithim: Finds the best match for a given dna genome and a given dna sequence
	1.Okay, basically the user inputs 3 genomes and a sequence until all of the genomes aren't empty and the sequence isn't longer than the genomes.
	2.This first goes to the best match function which finds the best match in the given genomes for that specific sequence by using the find similarity function.
	3.The best score for each genome is returned.
	4.The genome(s) with the highest similarity score are chosen.
Input paramters: 3 genomes and 1 sequence
Output:The genomes with the highest similarity score to the given sequence.
Return: The genomes with the highest similarity score to the given sequence.
*/

/*
This function right here will take two strings and find the similarity score between those strings. In the case of genomes
equal segments of the genome will be compared to the sequence that is the same length.
*/
float findSimilarityScore(string one, string two)
{
    float scoreadjusted;//this variable will make sense later
    float score = 0;// the counter variable to see how many characters are similar in the genome and the sequence
    if(two.length() != one.length())//if the two strings aren't the same length we return an error
    {
        return -1;
    }
    if(two.length() == 0|| one.length() == 0)// if either the strings are equal to 0 we return an error
    {
        return -1;
    }
    else
    {
        for(int i=0; i < one.length(); i++)//we check the ith element of the first and second strings too see if they are equal
        {
            if(one[i]==two[i])//if they are equal we increment the score counter by 1
            {
                score++;
            }
        }
        
    }
    
    scoreadjusted = (score/one.length());//what score adjusted does is divide the score by the length of the small segment of the genome which is the same as the length of the sequence
    return scoreadjusted;//return the adjusted score
}

float findBestMatch(string longone, string two)//what this function does is divide up the big genome into segments that are equal to the length of the small sequence
{
    string substring;//container for each little piece of the big genome
    float currentscore = 0;//the current similiarity score at each time for the comparision of each segment
    float finalscore = 0;// the best similarity score
    //this is how i fixed the bug
    if(longone.length()==0 || two.length()==0)//if either the long string or the short string is equal to zero return an error
    {
        return -1;
    }
    if(two.length()>longone.length())//if the length of the sequence is longer than the genome return an error
    {
        return -2;
    }
    for(int i = 0; i < longone.length();i++)//this is a counter to divide up the genome into segments that are long as the sequence
    {
        substring = longone.substr(i,two.length());//we make the substring variable a substring from i to the length of the sequence of the genome
        currentscore = findSimilarityScore(substring, two);// we set the current score to the similarity score fo the sequence
        if(currentscore > finalscore)//if the current score is higher than the final score set the final score equal to the current score
        {
            finalscore = currentscore;
        }
    }
    return finalscore;//return the final score
}

int main()
{

    string genome1;
    string genome2;
    string genome3;
    string seq;

    cout << "Please enter genome 1:" << endl;//We enter the values for the sequence and the genomes here
    cin >> genome1;
    cout << "Please enter genome 2:" << endl;
    cin >> genome2;
    cout << "Please enter genome 3:" << endl;
    cin >> genome3;

    cout << "Please enter a sequence:" << endl;
    cin >> seq;
    

    if(genome1.length()== 0 || genome2.length()== 0 || genome3.length()== 0 || seq.length()==0)//we say that the genome and the sequence cannot be empty if anyone of them are
    {
        cout << "Genome and sequence cannot be empty." << endl;
    }
    else//if the previous error doesn't happen we check for the next error which is if the sequence length is more than any of the genomes and
    {
        while(seq.length() > genome1.length() || seq.length() > genome2.length() || seq.length() > genome3.length())
            {
                cout << "Sequence cannot be longer than genomes." << endl;
                cout << "Please enter a sequence:" << endl;
                cin >> seq;
            }
       //if it is we keep asking for it

    }


    //we find the best similarity score for each genome here
    float sim1 = findBestMatch(genome1, seq);
    float sim2 = findBestMatch(genome2, seq);
    //cout << "";//The silver bullet from the debugging god
    float sim3 = findBestMatch(genome3, seq);
    
    //we use if else if statements to see which genome(s) has or have the best match to the given sequence
    //all it is, is just seeing which similarity scores are higher or equal
    if(sim1 > sim2 && sim1 > sim3)
    {
        cout << "Genome 1 is the best match." << endl;
    }
    else if(sim2 > sim1 && sim2 > sim3)
    {
        cout << "Genome 2 is the best match." << endl;
    }
    else if(sim3 > sim2 && sim3 > sim1)
    {
        cout << "Genome 3 is the best match." << endl;

    }
    else if(sim1 == sim2 && sim1 > sim3)
    {
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 2 is the best match." << endl;
    }
    else if(sim2 == sim3 && sim2 > sim1)
    {
        cout << "Genome 2 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
    }
    else if(sim1 == sim3 && sim1 > sim2)
    {
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
    }
    
    else if(sim1==sim2 && sim1==sim3 && sim2==sim3 && genome1.length() > 0 && genome2.length() > 0 && genome3.length() > 0 && seq.length()>0)
    {
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 2 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
    }
    
    return 0;
}

