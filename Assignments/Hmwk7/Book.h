#ifndef BOOK_H
#define BOOK_H
#include <iostream>
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