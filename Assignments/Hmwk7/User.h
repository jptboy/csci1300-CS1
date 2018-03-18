// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 7 part 1, all problems
#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User
{
    public:
        User();
        User(string new_username, int new_ratings[], int new_numratings);
        void setName(string new_username);
        string getName();
        void setNumRatings(int new_numratings);
        int getNumRatings();
        int setRatingAt(int pos, int new_rating);
        int getRatingAt(int idx);
        ~User();
    private:
        string username;
        int ratings[100];
        int numratings;
};


#endif //USER_H