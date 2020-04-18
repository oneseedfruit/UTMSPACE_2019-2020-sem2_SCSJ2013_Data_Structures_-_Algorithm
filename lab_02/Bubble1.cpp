// Classical Bubble Sort
// Prepared by : Nor Bahiah Hj. Ahmad
// School of Computing, Faculty of Engineering
// Universiti Teknologi Malaysia
// e-mail : bahiah@utm.my
// 11 April 2020

// Modified by Randy Tan Shaoxian
// - Removed unused headers.
// - Removed mixing C and C++ code.
// - Fixed/added code to show time taken to run an algorithm.
// - Added an array containing arrays of values for given worst case, average case, and best case.

#include <iostream>
#include <chrono>

using namespace std;

void BubbleSort(int data[], int listSize)
{
   int pass, compare = 0, swap = 0;
   int x ;
   int tempValue;

   cout << "\n\nStart Sorting......\n";

   auto before = chrono::high_resolution_clock::now();

   for (pass = 1; pass < listSize; ++pass)
   {
       cout << "\nPass " << pass;    //pindah nilai besar ke atas tatasusunan

       for (x = 0; x < listSize - pass; x++)
       {
           compare++ ;
           if (data[x] > data[x + 1])
           {
               swap++;
               // Operasi penukaran unsur bersebelahan
               tempValue = data[x];
               data[x] = data[x + 1];
               data[x + 1] = tempValue;
               cout << "\nSwap between: " << data[x] << " and " << data[x + 1] << " in pass " << pass ;
           }
       }
   }

   auto after = chrono::high_resolution_clock::now();
   auto duration = chrono::duration_cast<chrono::microseconds>(after - before).count();

   cout << "\n\nTime taken to sort the data: " << duration << " microseconds";
   cout << "\n\nNumber of passes:  " << (pass - 1);
   cout << "\nNumber of data comparisons done:  " << compare;
   cout << "\nNumber of swapping among data:  " << swap;
}

int main()
{
    const int size = 10;
    int x;
    int data[3][size] = { 
        { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11 }, // Worst case
        { 12, 9, 20, 18, 7, 5, 15, 17, 11, 25 }, // Average case
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } // Best case
    };

    cout << "Content of the lists before sorting:\n\n" ;
    for (int x = 0; x < 3; x++)
    {       
        cout << "Case " << x + 1 << ": ";
        for (int y = 0; y < size; ++y) 
        {
    	    cout << data[x][y] << "  ";
        }
        cout << "\n";
    }

    cout << "\n===============================================\n";

    for (int i = 0; i < 3; ++i)
    {
        cout << "\n\n-----------------------------------------------\n";
        cout << "Case " << i + 1 << ":";
        BubbleSort(data[i], size);        
    }

    cout << "\n\n\n===============================================\n";

    cout << "\n\nContent of the lists after sorting:\n\n";
    for (int x = 0; x < 3; x++)    
    {        
        cout << "Case " << x + 1 << ": ";
        for (int y = 0; y < size; ++y) 
        {
    	    cout << data[x][y] << "  ";
        }
        cout << "\n";
    }

    return 0;
}