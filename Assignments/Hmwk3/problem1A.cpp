// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 3 - Problem # 1A

#include <iostream> //including iostream and doing all the prequired stuff
#include <string>
using namespace std;

void story1();
void story2();//definition of the story functions
void story3();
/*
Algorithim: print a story
	1.Call the story function for the respective story so story1() story2() or story3()
	2. Ask for each of the required words for the story
	3.Make the story and print it out
Input paramters: None
Output: A story
Return: A story
*/

int main()
{
    story1();//test case 1
    story2();//test case 2
    story3();//test case 3
    return 0;
}

void story1()
{
    cout << "Enter a plural noun: "<<endl;//prompt user for word
    string pluralnoun;
    cin >> pluralnoun;//user enters word

    cout << "Enter an occupation: "<<endl;//prompt user for word
    string occupation;
    cin >> occupation;    //user enters word

    cout << "Enter an animal name: "<<endl;
    string animalname;
    cin >> animalname;//user enters word

    cout << "Enter a place: "<<endl;
    string place;//user enters word
    cin >> place;

    cout << "In the book War of the " << pluralnoun << ", " << "the main character is an anonymous " << occupation << " who records the arrival of the " << animalname << "s in " << place << "." << endl; //say the whole phrase about the war of the <x> with the entered words
}

void story2()
{
    cout << "Enter a name: " << endl;//prompt user for word
    string name;
    cin >> name;//user enters word

    cout << "Enter a state/country: " << endl;//prompt user for word
    string stateorcountry;//user enters word
    cin >> stateorcountry;

    cout << name << ", I've got a feeling we're not in " << stateorcountry << " anymore." << endl;//make the sentence and spit it out

}

void story3()
{
    cout << "Enter a first name: "<<endl;//prompt user for word
    string firstname;
    cin >> firstname;//user enters word

    cout << "Enter a relative: "<<endl;//prompt user for word
    string relative;//user enters word
    cin >> relative;    

    cout << "Enter a verb: "<<endl;//prompt user for word
    string verb;//user enters word
    cin >> verb;

    cout << "Hello. " << "My name is " << firstname << "." << " You killed my " << relative << "." << " Prepare to " << verb << "." << endl; //make the sentence and cout it
}

