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