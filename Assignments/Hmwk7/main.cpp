// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 7 part 1, all problems
#include <iostream>
#include "User.h"
#include "Book.h"
using namespace std;

//I did this with multiple files at first but you can uncomment the next block comment and comment out the header files and everything will still work

/*
class Book
{
    public:
        Book();
        Book(string tit, string auth);
        string getTitle();
        void setTitle(string x);
        string getAuthor();
        void setAuthor(string y);
        ~Book();
    private:
        string title;
        string author;
};

Book::Book()
{
    title = "NONE";
    author = "NONE";
};

Book::Book(string tit, string auth)
{
    title = tit;
    author = auth;
};
string Book::getTitle()
{
    return title;
}

void Book::setTitle(string x)
{
    title = x;
}

string Book::getAuthor()
{
    return author;
}

void Book::setAuthor(string y)
{
    author = y;
}
Book::~Book()
{
    title = "NONE";
    author = "NONE";
}
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
    //test case 1 for problem 1
    Book cs_textbook("Problem Solving with C++ (9th Edition)", "Walter  Savitch");
    cout << cs_textbook.getAuthor() << endl;
    //test case 2 for problem 1
    Book fakebook("Fake", "Faker  Fakest");
    cs_textbook.setAuthor("Vipra Gupta");

    //test case 1 for problem 2
    int user1_ratings[] = {0, 1, 3, -1, 0, -5, -3};
    User user1("ayush", user1_ratings, 7);
    cout << user1.setRatingAt(3, -10000) << endl;
    //test case 2 for problem2
    int user2_ratings[] = {0, 3, 3, -5, 2, -3, -3};
    User user2("chiekeef", user2_ratings, 7);
    cout << user2.getRatingAt(3) << endl;
    
    return 0;
}