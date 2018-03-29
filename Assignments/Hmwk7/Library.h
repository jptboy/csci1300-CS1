#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include "User.h"
#include "Book.h"
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

class Library
{
    private:
		Book books[1000];//array sizes need to be defined here
		User users[1000];
		int Split(string s, char a, string word[], int size);//we could put this in another file and call it
		int numusers;
		int numbooks;
    public:
        Library();
		void loadData();
		void login();
		void addNewUser();
		int menu(int whois);
		void viewRatings(int whois);
		void rateBook(int whois);
		void recommend(int whois);
		void quit();
		void test();
		//~Library();
};


#endif//LIBRARY_H
