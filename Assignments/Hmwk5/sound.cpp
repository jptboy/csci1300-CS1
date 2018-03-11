// Author: Ayush Khanal CS1300 Fall 2017
// Recitation: 204- Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/ayushkhanal/ayushkhanalcsci1300
// Homework 5 - Problem # 1
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

/*
Algorithim: Reverses adds echoes and normalizes a given sound file in the .wav format by using arrays storing the sound data
	1.As I obviously only wrote 3 functions out of the many in this file I will only talk about the ones I wrote because I am unsure as to what the rest of the program does.
	2.After the program takes in the file and makes sure that it is correct my reverse function reverses the sound.
	3.My add echo function then adds echoes to the sound.
	4.My normalize function then normalizes the sound.
    5.The sound file is now completely changed.
It would simply be more conducive to the understanding of the reader to just comment what each of my functions does by single line comments than it would be 
to write a block comment explaining the alogrithim to a file that I did not even write the majority of.
I will write the algorithims to each one of my individual functions above their definitions.
Input paramters: sound file
Output:Sound file
Return: Sound file
*/

void process(int samples[], int size)
{
   // Here, we make the sound three times as loud

   for (int i = 0; i < size; i++)
   {
      samples[i] = 3 * samples[i];
   }
}


/*
Algorithim: Reverses an array
    1.The sound format is just taken  in as an array so to reverse the sound you have to reverse the array that it is stored within.
    2. I simply did this by creating a new array of the same length and filling it with a backwards counting for loop from the first array.
    3. I then filled the first array back up with the elements from the second array.
*/
void reverse(int samples[], int size)
{
    int arr2[size];//declaring the second array of the same length
    int m = size - 1;// initialize this variable to count from the last element of the first array
    
    for(int i = 0; i < size; i++)
    {
        arr2[i] = samples[m];// I fill the 0+i element of the second array with the (size-1)-i of the first array to fill it backwards 
        m--;
    }
    
    
    for(int i=0; i < size; i++)
    {
        samples[i]=arr2[i]; // I fill the backwards array back into the first array and the sound is now reversed
    }
    
    
    
}


/*
Algorithim: Adds echoes to a sound
    1. All this function does is add the element that is the  delay*sample_rate back in the first array essentially adding older sounds to newer values to create an echo.
*/
void add_echo(int samples[], int size, int sample_rate, double delay)
{
    int samples2[size];//initializing the second array
    int foo = sample_rate*delay;//finding how many elements I have to go back
    for(int i=0; i < size; i++)
    {
        samples2[i] = samples[i];//putting things in the second array because not all elements of the second array are changed from the first depending on the size of foo
    }//this leaves the initital elements the same which might be needed depending on the delay and the sample rate
    for(int i=size-1; i-foo >= 0 ; i--)
    {
        samples2[i] = (samples[i]+samples[i-foo]);//until the counter-foo(how many indices to go back is 0) fill the last element of the second array with the last element minus the foo from the last element of the first array
    }
    
    for(int i=0; i < size; i++)
    {
        samples[i] = samples2[i];//refill the first array with the values from the second array and the sound now has echoes
    }
    
    
}

/*
Algorithim: Normalizes a sound
    1. All this function does is find the highest value in an array and divides each value times 36773 with the highest value.
*/
void normalize(int samples[],int size)
{
    int hval = 0;
    int currentval = 0;
    int bnum = 36773;//declaring variables for ease of use and to find the highest value
    for(int i=0; i<size; i++)
    {
        if(samples[i]>currentval)
        {
            currentval = samples[i];//finding the highest value
        }
    }
    
    hval = currentval;
    for(int i=0; i<size; i++)
    {
        samples[i] = (samples[i]*bnum)/(hval);//changing each element in the array to be the element times 36773 divided by the highest value
    }
    
}


int get_unsigned_int4(fstream& stream)
{
   int result = 0;
   int base = 1;
   for (int i = 0; i < 4; i++)
   {
      result = result + stream.get() * base;
      base = base * 256;
   }
   return result;
}


int get_unsigned_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   return lo + 256 * hi;
}


int get_signed_int2(fstream& stream)
{
   int lo = stream.get();
   int hi = stream.get();
   int result = lo + 256 * hi;
   if (result >= 32768) { result = result - 65536; }
   return result;
}


void put_signed_int2(fstream& stream, int value)
{
   if (value < 0) { value = value + 65536; }
   stream.put(value % 256);
   stream.put(value / 256);
}

int main()
{
   cout << "Please enter the file name: ";
   string filename;
   cin >> filename;

   fstream stream;

   // Open as a binary file
   stream.open(filename.c_str(), ios::in | ios::out | ios::binary);

   // Check that we can handle this file
   stream.seekg(20);
   int format_type = get_unsigned_int2(stream);
   if (format_type != 1)
   {
      cout << "Not an uncompressed sound file." << endl;
      return 1;
   }
   int num_channels = get_unsigned_int2(stream);
   if (num_channels != 1)
   {
      cout << "Not a mono sound file." << endl;
      return 1;
   }

   int sample_rate = get_unsigned_int2(stream);

   stream.seekg(34);
   int bits_per_sample = get_unsigned_int2(stream);
   if (bits_per_sample != 16)
   {
      cout << "Not a 16 bit sound file." << endl;
      return 1;
   }

   // Read data size and allocate data array
   stream.seekg(40);
   int data_size = get_unsigned_int4(stream) / 2; // 2 bytes per data
   int* samples = new int[data_size];

   // Read sound data
   for (int i = 0; i < data_size; i++) 
   {
      samples[i] = get_signed_int2(stream);
   }

   // Process sound data
   //process(samples, data_size);
   reverse(samples, data_size);

   // Replace "Process sound data" and the call to the process 
   // function with option A or option B below

   // A. Reverse
   // 1. Call the reverse function

   // B. Add echo
   // 1. Declare and initialize variable for echo delay
   double delay = 1;
   add_echo(samples, data_size, sample_rate, delay);
   // 3. Call the normalize function
   normalize(samples, data_size);


   // Write sound data
   stream.seekp(44);
   for (int i = 0; i < data_size; i++)
   {
      put_signed_int2(stream, samples[i]);
   }

   stream.close();

   delete[] samples;
     
   return 0;
}
