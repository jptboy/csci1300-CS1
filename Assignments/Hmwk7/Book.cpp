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