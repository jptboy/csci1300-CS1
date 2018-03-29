// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 7 part 1, all problems
#include <iostream>
#include "User.h"
using namespace std;
User::User()
{
    username = "NONE";
    ratings[100];
    numratings = 0;
};

User::User(string new_username, int new_ratings[], int new_numratings)
{
    for(int i=0; i<new_username.length(); i++)
    {
        new_username[i] = tolower(new_username[i]);
    }
    username = new_username;
    for(int i=0; i<new_numratings;i++)
    {
        ratings[i] = new_ratings[i];
    }
    numratings = new_numratings;
};

void User::setName(string new_username)
{
    username = new_username;
}

string User::getName()
{
    return username;
}

void User::setNumRatings(int new_numratings)
{
    numratings = new_numratings;
}
int User::getNumRatings()
{
    return numratings;
}
int User::setRatingAt(int pos, int new_rating)
{   
    if(pos >= numratings)
    {
        return -1000;
    }
    
    if((new_rating >= -5 && new_rating <= 3) || new_rating == 5)
    {    
        ratings[pos] = new_rating;
        //cout << "Success!" << endl;
        return 0;
    }

    cout << "Invalid Input!" << endl;
    return -1;


}
int User::getRatingAt(int idx)
{
    if(idx >= numratings)
    {
        return -1000;
    }
    return ratings[idx];
}

User::~User()
{
    username = "NONE";
    ratings[100];
    numratings = 0;
};