// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 7 part 1, all problems
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;
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
#endif//BOOK_H