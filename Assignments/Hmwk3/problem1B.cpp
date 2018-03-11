// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 3 - Problem # 1B

#include <iostream>
#include <string>
using namespace std;

void story1();
void story2();
void story3();
void menu();
/*
Algorithim: Asks user what story they want to choose and play that story and go back to the menu until the user quits
	1.Ask the user what story they want to play and play the story or ask again if there is invalid input
	2. As long as the user doesnt press q to quit keep asking the user what story they want to play until they quit
	3. Play the story
    4. When the user presses q quit.
Input paramters: Choice for the story to play. Its not inputted directly into the functions argument but its prompted in the function.
Output: stories
Return: stories
*/

int main()
{
    menu();//test case 1
    return 0;
}

void menu()
{
    string choice;//initialize the storage variable for choice

    while(choice != "q")//as long as the choice isn't the string q keep doing what is in the loop
       { 
        cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: " << endl;//prompt the user for the story they want to play
        cin >> choice;
                if(choice == "1")// if the choice is 1 play the corresponding story1
                {
                    story1();
                }
                else if(choice == "2")// if the choice is 2 play the corresponding story2
                {
                    story2();
                }
                else if(choice == "3")// if the choice is 3 play the corresponding story3
                {
                    story3();
                }
                else if(choice == "q")// if the choice is q quit
                {
                    cout << "good bye" << endl;
                }
                
                if(choice != "1" && choice != "2" && choice != "3" && choice != "q") // if the choice doesn't match any of these options give the error phrase
                {
                    cout << "Valid choice not selected." << endl;
                }
       }
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


