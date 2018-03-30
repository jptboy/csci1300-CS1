void bubbleSort(int arr[], int size)
{
    bool sort = false;
    int check = 0;
    int holder = 0;
    int swap = 0;
    int passes = size - 1;
    
    while(sort==false)
    {
        sort = true;
        for(int i=0; i < passes; i++)
        {
            if(arr[i+1] < arr[i])
            {
                holder = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = holder;
                sort = false;
                swap++;
            }
            check++;
        }
        passes--;
    }
    
    cout <<"Bubble Sort: " << endl;
    for(int i=0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout <<"Number of comparisons: " << check  << endl;
    cout <<"Number of swaps: " << swap  << endl;
}

void cocktailSort(int arr[], int size)
{
    bool sort = false;
    int check = 0;
    int holder = 0;
    int swap = 0;
    int epos = size-1;
    int spos = 0;
    
    while(sort==false)
    {
        sort = true;
        
        for(int i=spos; i < epos; i++)
        {
            if(arr[i+1] < arr[i])
            {
                holder = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = holder;
                sort = false;
                swap++;
            }
            check++;
        }
        
        epos--;
        if(sort==true)
        {break;}
        sort = true;
        
        for(int i=epos; i > spos; i--)
        {
            if(arr[i] < arr[i-1])
            {
                holder = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = holder;
                sort = false;
                swap++;
            }
            check++;
        }
        
        
        spos++;
        
    }
    //cout << passes << " " << passes2 << endl;
    cout <<"Cocktail Sort: " << endl;
    for(int i=0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout <<"Number of comparisons: " << check  << endl;
    cout <<"Number of swaps: " << swap  << endl;
}
