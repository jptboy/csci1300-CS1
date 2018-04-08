// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Recitation 11 - Problem # 2
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> myvec;
    string input="2";
    int realin=-4234;
    bool errorbool=false;
    bool intbool = false;
    while(!(input=="q"||input=="Q"))
    {       

            if(errorbool==false&&intbool==false)
            {
                cout<<"Enter a positive integer or press q to quit:" << endl;
            }
            errorbool=false;
            intbool=false;
            cin >> input;
            if(input=="q"||input=="Q")
            {   
                break;
            }
            else
            {
                
                try{realin=stoi(input);}
                catch(std::invalid_argument)
                {
                    cout<<"Please enter a valid positive integer or press q to quit:"<<endl;
                    errorbool=true;
                }
                catch(std::out_of_range)
                {
                    cout<<"Don't enter that big of a number! Enter another positive integer instead:"<<endl;
                    errorbool=true;
                }
                if(errorbool==false)
                {
                    if(realin<1)
                    {
                        cout <<"Please enter a POSITIVE integer:" << endl;
                        intbool=true;
                    }
                }
                if(myvec.size()==0 && errorbool==false && intbool==false)
                {
                    myvec.push_back(realin);
                }
                else
                {
                    if(realin%5==0 && errorbool==false && intbool==false)
                    {
                        myvec.erase(myvec.begin() + 0);
                    }
                    else
                    {
                        if(realin%3==0 && errorbool==false && intbool==false)
                        {
                            myvec.pop_back();
                        }
                        else if(errorbool==false && intbool==false)
                        {
                            myvec.push_back(realin);
                        }
                    }
                }
            }
                
        }
    
    
    if(myvec.size()==0)
    {
        cout << "The vector is empty." << endl;
    }
    else
    {
        bool sort = false;
        int check = 0;
        int holder = 0;
        int swap = 0;
        int passes = myvec.size() - 1;
        
        while(sort==false)
        {
            sort = true;
            for(int i=0; i < passes; i++)
            {
                if(myvec[i+1] < myvec[i])
                {
                    holder = myvec[i];
                    myvec[i] = myvec[i+1];
                    myvec[i+1] = holder;
                    sort = false;
                    swap++;
                }
                check++;
            }
            passes--;
        }
        
        
        
        cout << "The elements in the vector are: ";
        for(int i=0; i < myvec.size();i++)
        {
            cout << myvec[i] << " ";
        }
        cout << endl;
        cout << "Max = " << myvec[myvec.size()-1] << endl;
        cout << "Min = " << myvec[0] << endl;
    }

    return 0;
}