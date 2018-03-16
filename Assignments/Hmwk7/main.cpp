#include <iostream>
#include "User.h"
using namespace std;

/*
If you dont want to do this by including the other files and stuff you can just get rid of include "User.h" and paste this whole comment up here except for this sentence.
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
User::User()
{
    username = "NONE";
    ratings[100];
    numratings = 0;
};

User::User(string new_username, int new_ratings[], int new_numratings)
{
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
        cout << "Success!" << endl;
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
*/
int main()
{
    	
    //test setRatingsAt, getRatingsAt
    int user1_ratings[] = {0, 1, 3, -1, 0, -5, -3};
    User user1("ayush", user1_ratings, 7);
    cout << user1.setRatingAt(3, -10000) << endl;
    return 0;
}