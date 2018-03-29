// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 7 part 1, all problems
#include "Book.h"
#include <iostream>
using namespace std;

Book::Book()
{
    title = "NONE";
    author = "NONE";
}

Book::Book(string tit, string auth)
{
    for(int i=0; i<tit.length(); i++)
    {
        tit[i] = tolower(tit[i]);
    }
    for(int i=0; i<auth.length(); i++)
    {
        auth[i] = tolower(auth[i]);
    }
    title = tit;
    author = auth;
};
string Book::getTitle()
{
    return title;
}

void Book::setTitle(string x)
{
    for(int i=0; i<x.length(); i++)
    {
        x[i] = tolower(x[i]);
    }
    title = x;
}

string Book::getAuthor()
{
    return author;
}

void Book::setAuthor(string y)
{
    for(int i=0; i<y.length(); i++)
    {
        y[i] = tolower(y[i]);
    }
    author = y;
}
Book::~Book()
{
    title = "NONE";
    author = "NONE";
}