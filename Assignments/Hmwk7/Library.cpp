#include "Library.h"

Library::Library()
{
    loadData();
};

int Library::Split(string s, char a, string word[], int size)//split function from recitation 7
{
    int ctilchar = 0;//counts the number of chars until the seperator character
    int arrayindex = 0;//keeps position in the string
    int initseprs = 0;// the initial amount of seperators
    int subs = 0;// used to count the number of substrings
    int seprs = 0;// if there is actually a seperator then we increment initseprs by 1 to get seprs otherwise seprs stays 0
    int ctilcharreal = 0;//is used to see if we are at the end of the string 
    
    for(int i=0; i<s.length();i++)
    {
        if(s[i] == a)
        {
            initseprs++;//if there are seperators then increment init seprs by that amount
        }
    }

    if(initseprs > 0)
    {
        seprs = initseprs + 1;//if init seprs is more than 0 than the real amount of seperators needs to be one more than that for my algorithim
    }



    if(initseprs == 0 && s.length() > 0)//if init seprs is 0 and the string has a length then we just put the string into the 0th index of the  array so we return one subsection
    {
        word[0] = s;
        return 1;
    }
    else
    {
        for(int o = 0; o < seprs; o++)//repeat the outer for loop until the number of seperators is reached
        {
                for(int i = arrayindex; i <= s.length(); i++)
                    {
                        if(s[i] != a)
                        {
                            ctilchar++;//if the ith char of the string isnt the seperator increase the count till char value because thats the purpose of that var
                            ctilcharreal++;//we always increase this to determine our position in the string
                        }
                        
                        if(ctilcharreal==s.length())
                        {
                            word[o] = s.substr(arrayindex, ctilcharreal-arrayindex);//if we reach the end of the string then we put whatever was before that into the array
                            subs++;//increment the number of substrings put into the array
                            break;
                        }
                        
                        if(s[i] == a)
                        {
                            word[o] = s.substr(arrayindex, ctilchar);//if the ith character is the seperator then we make whatever was before that a substring and put it into the array
                            subs++;//increment the amount of substrings put into the array
                            arrayindex += ctilchar + 1;//increment this; its like the cutters arm that would hold your arm while the cutters other arm used a sword to cut it idk how else to explain this
                            ctilchar = 0;//reset the counter till the seperator to 0
                            ctilcharreal++;//we always increase this
                            break;
                        }
                    }
        }
    }
    return subs;// return the number of substrings put into the array
}

void Library::loadData()
{
    string userLine;
    string bookLine;
    
    ifstream loadUsers("ratings.txt");
    ifstream loadBooks("books.txt");
    
    int bookCounter = 0;
    int sizeBookSplitArr = 2;
    string bookSplitArr[sizeBookSplitArr];
    
    int userCounter = 0;
    int sizeUserSplitArr = 2;
    string userSplitArr[sizeUserSplitArr];

    

    if(!loadUsers.is_open() || !loadBooks.is_open())
    {
        cout << "Launch unsuccessful" << endl;
        cout << "Error! books or ratigs file could not be found." << endl;
        return;
    }
    
    while(getline(loadBooks, bookLine))
    {
        Split(bookLine, ',',  bookSplitArr, sizeBookSplitArr);
        Book newBook(bookSplitArr[1], bookSplitArr[0]);
        books[bookCounter] = newBook;
        bookCounter++;
    }
    //cout << books[54].getTitle();
    loadBooks.close();

    int sizeUserRatArr = bookCounter;
    string userRatArr[sizeUserRatArr];
    int newUserRatings[sizeUserRatArr];

    while(getline(loadUsers, userLine))
    {
        Split(userLine, ',', userSplitArr, sizeUserSplitArr);
        Split(userSplitArr[1], ' ', userRatArr, sizeUserRatArr);
        for(int i=0; i < sizeUserRatArr; i++)
        {
            newUserRatings[i] = stoi(userRatArr[i]);
        }
        User newUser(userSplitArr[0],newUserRatings,sizeUserRatArr);
        users[userCounter] = newUser;
        userCounter++;
    }
    loadUsers.close();
    numusers = userCounter;//issue might need to increment by one and the thing below it
    numbooks = bookCounter;
    cout << "Data Loaded successfully!" << endl;
    return;  
}

void Library::login()
{
    int option = -2;
    int useridx = -2;
    string logUsern;
    string newLogUsern = logUsern;
    bool isinlist = false;
    cout << "Welcome to the Library, What is your name?:" << endl;
    getline(cin, logUsern);
    newLogUsern = logUsern;
    for(int i=0; i < logUsern.length(); i++)
    {
        newLogUsern[i] = tolower(logUsern[i]);
    }
    while(logUsern.length() == 0)
    {
        cout << "You provided an empty user name, Please provide a valid user name to login or register:" << endl;
        cout << "Enter your name again:" << endl;
        //cout <<newLogUsern<<endl;        
        getline(cin, logUsern);
        //cout <<logUsern<<endl;
        newLogUsern = logUsern;        
        for(int i=0; i < logUsern.length(); i++)
        {
            newLogUsern[i] = tolower(logUsern[i]);
        }
        //cout <<newLogUsern<<endl;
    }
    for(int i=0; i < logUsern.length(); i++)
        {
            newLogUsern[i] = tolower(logUsern[i]);
        }
    for(int i=0; i<numusers; i++)
    {
        if(users[i].getName() == newLogUsern || users[i].getName() == logUsern)//the strings were different lengths
        {
            //cout << "@@@@@@@@@@" << endl;
            isinlist=true;
            useridx = i;
        }
    }
    if(isinlist==true)
    {
        cout << "Welcome back, " << logUsern << endl;
        menu(useridx);
        numusers++;
        return;
    }
    else
    {     

        int unknownRatingsArr[numbooks];
        for(int i=0; i < numbooks; i++)
        {
            unknownRatingsArr[i] = 0;
        }
        int unknownSizeVal = numbooks;
        users[numusers] = User(logUsern, unknownRatingsArr, unknownSizeVal);
        numusers++;
    } 
    cout << "Welcome to the Library, " <<logUsern << endl;
    for(int i=0; i<numusers; i++)
    {
        if(users[i].getName() == newLogUsern || users[i].getName() == logUsern)//the strings were different lengths
        {
            //cout << "@@@@@@@@@@" << endl;
            isinlist=true;
            useridx = i;
        }
    }
    menu(useridx);


    return;//there might be an issue with this return staatement so idk
}

int Library::menu(int whois)
{
    char option;
    cout << "Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:"<< endl;
    cin >> option;
    
    /*
    do{cout << "Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:"<< endl;
    cin >> option;}
    //option = tolower(option);
    while(!(option == 'v'|| option == 'r'|| option == 'g'|| option == 'q' || option == 'V'|| option == 'R'|| option == 'G'|| option == 'Q'));
    */
    while(!(option == 'v'|| option == 'r'|| option == 'g'|| option == 'q' || option == 'V'|| option == 'R'|| option == 'G'|| option == 'Q'))
    {
        cout << "Please input a valid choice"<< endl;
        cout << "Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:"<< endl;
        cin >> option;
    }
    if(option =='v' ||option =='V')
    {
        viewRatings(whois);
    }
    else if(option =='r' || option =='R')
    {
        rateBook(whois);
    }
    else if(option =='g'|| option =='G')
    {
        recommend(whois);
    }
    else if(option =='q'|| option =='Q')
    {
        quit();
    }
    return 0;
}
void Library::viewRatings(int whois)
{
    string gong;
    int numraters = 0;

    for(int i =0; i <numbooks; i++)
        {
            if(users[whois].getRatingAt(i)==-5 ||users[whois].getRatingAt(i)==-3 ||users[whois].getRatingAt(i)==1||users[whois].getRatingAt(i)==3||users[whois].getRatingAt(i)==5)
            {   
                numraters++;
            } 
        
        }

    if(numraters==0)
    {
        cout << "You have not rated any books as yet:"<<endl;
        menu(whois);
    }
    else
    {
        cout << "Here are the books that you have rated:" << endl; 
        for(int i =0; i <numbooks; i++)
        {
            if(users[whois].getRatingAt(i) != 0 ||users[whois].getRatingAt(i)==-1 ||users[whois].getRatingAt(i)==-3 ||users[whois].getRatingAt(i)==-5||users[whois].getRatingAt(i)==3||users[whois].getRatingAt(i)==5)
            {   gong = books[i].getTitle().substr(0,books[i].getTitle().length()-1);
                cout << "Title : " << gong << endl;
                cout << "Rating : "<< users[whois].getRatingAt(i) << endl;
                cout << "------------------------------" << endl;
            } 
        
        }
        menu(whois);
    }
}
void Library::rateBook(int whois)
{
    string namebook;
    int ratingidx = -1;
    int rating = 0;
    //string rating1;
    bool exist = false;
    cout << "Enter the name of the book that you would like to rate:" << endl;
    cin.ignore();
    getline(cin,namebook);
    cout << "Enter your rating of the book:" << endl;
    cin >> rating;
    string bangbook;
    bangbook = namebook;
    for(int i=0; i < namebook.length(); i++)
    {
        namebook[i] = tolower(namebook[i]);
    }
     string thing;
    for(int i=0; i < numbooks; i++)
    {
        thing =books[i].getTitle(); 
        if(thing.substr(0,thing.length()-1) == namebook)
        {
            //cout << "valid" << endl;
            exist = true;
        }
    }
    if(namebook.length()==0)
    {
        exist = false;
    }
    if(exist == true)
    {
        cout << "Success!" << endl;
        cout << "Thank-you. The rating for the book titled "  << bangbook  <<" has been updated to " << rating <<endl;
    }

    while(exist == false)
    {
        cout << "Invalid Book" << endl;
        cin.ignore();
        getline(cin, namebook);
        cout << "Enter your rating of the book :" << endl;
        cin >> rating;
        for(int i=0; i < namebook.length(); i++)
        {
            namebook[i] = tolower(namebook[i]);
        }
        string thing2;

        for(int i=0; i < numbooks; i++)
        {
            thing2 =books[i].getTitle(); 

            if(thing2.substr(0,thing2.length()-1)==namebook)//where we left off why doesnt this work?
            {
                exist = true;
            }
        }
        if(namebook.length()==0)
        {
            exist = false;
        }

        if(exist==false)
        {
            cout << "Invalid Book" << endl;
        }
        if(exist == true)
        {
            cout << "Success!" << endl;
            cout << "Thank-you. The rating for the book titled "   << bangbook  <<" has been updated to " << rating <<endl;
        }
    }

    string thing3;

    for(int i=0; i < numbooks; i++)
    {
        thing3 =books[i].getTitle(); 

        if(namebook== thing3.substr(0,thing3.length()-1))
        {
            users[whois].setRatingAt(i, rating);
        }
    }
    menu(whois);
    //cout << users[numusers-1].getRatingAt(43) << endl;
}
void Library::test()
{
  //  for(int i=0; i<numbooks; i++)
    //{
        //if(books[i].getTitle().length() > 0)
        //{
            cout << "";
            //cout << users[numusers-1].getRatingAt(numbooks-1);
        //}
    //}

}
void Library::recommend(int whois)
{
    double ssd = 0;
    double currrat1 = 0;
    double currrat2=0;
    double diff = 0;
    double totrat1 =0;
    int ratcount = 0;

    double bestmatch = 1000000000000;
    int usermatch = -1;

    int numrec = 0;
    for(int m=0; m<numusers; m++)
    {
        for(int i =0; i<numbooks; i++)
        {
            currrat1 = users[whois].getRatingAt(i);
            currrat2 = users[m].getRatingAt(i);
            diff = (currrat1-currrat2)*(currrat1-currrat2);
            totrat1+=diff;
        }
        if(totrat1 < bestmatch && totrat1!=0)
            {
                bestmatch = totrat1;
                usermatch = m;
            } 
        totrat1=0;
        
    }
    //cout << usermatch << endl;
    for(int i=0; i < numbooks; i++)
    {
        if((users[usermatch].getRatingAt(i) == 3 || users[usermatch].getRatingAt(i) == 5) && users[whois].getRatingAt(i)==0 )
        {
            //cout << 
            numrec++;
            //cout << numrec << endl;
        }

        
    }
    if(numrec==0)
    {
        cout <<"There are no recommendations for you at present" << endl;
        menu(whois);
    }
    else{
        cout << "Here are some of the books that we think you would like" << endl;
        cout <<flush;
        string work;
        for(int i=0; i < numbooks; i++)
        {
            
            cout << flush;
            if((users[usermatch].getRatingAt(i) == 3 || users[usermatch].getRatingAt(i) == 5) && users[whois].getRatingAt(i)==0 && ratcount <10)
            {
                work = books[i].getTitle();
                work+= '\n';
                work = work.substr(0, work.length()-2);
                cout << work << " by " <<books[i].getAuthor() << endl;
                ratcount++;
                //return;
            }

        }
        menu(whois);
    }
    
}

void Library::quit()
{
    //ofstream writeData("ratings_new.txt");
    ofstream writeData("ratings.txt");
    if(!writeData.is_open())
    {
        cout << "Error" << endl;//i think this function works
    }
    
    for(int i=0; i<numusers; i++)
    {
        writeData << users[i].getName() << ",";
        for(int m=0; m < numbooks; m++)
        {
            writeData << users[i].getRatingAt(m) << " ";
        }
        writeData << endl;
    }
    cout << "Data successfully saved. Goodbye!" << endl;

}