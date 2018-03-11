#include <iostream>
using namespace std;

void shiftNums(int arr[], int length)
{
    int arr2[length];
    
    if(length >= 2)
    {
        for(int i = 0; i < length; i++)
        {
            arr2[i+1] = arr[i];
        }
        
        arr2[0] = arr[length-1];
        
        for(int i = 0; i < length; i++)
        {
            arr[i] = arr2[i];
        }
    }
}

int main()
{
    return 0;
}
