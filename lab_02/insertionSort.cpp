// Selection Sort Program
//
// Prepared by : Pn Nor Bahiah Hj. Ahmad
// Prepared by : Nor Bahiah Hj. Ahmad
// School of Computing, Faculty of Engineering
// Universiti Teknologi Malaysia
// e-mail : bahiah@utm.my
//
// Reference : Data Structure & Problem Solving with C++
// Frank M. Carrano, Pearson International Edition

// Modified by Randy Tan Shaoxian
// - Removed unused headers.
// - Removed mixing C and C++ code.
// - Fixed/added code to show time taken to run an algorithm.
// - Added an array containing arrays of values for given worst case, average case, and best case.

#include <iostream>
#include <chrono>

using namespace std;

void isihanSelitan(int data[],int n)
{   
    int item;
    bool sorted;
    int banding = 0;
    int laluan, titik_selitan, alih = 0;

    auto before = chrono::high_resolution_clock::now();
     
    for(laluan = 1; laluan < n; ++laluan)
    {  
        item = data[laluan];
        titik_selitan = laluan;
        sorted = false;

        while (titik_selitan > 0 && !sorted)
        {   
            sorted = true;
            banding++;

            if(data[titik_selitan - 1] > item)
            {
                //menyediakan ruangan untuk selitan
                cout << "\nSwap item "<< data[titik_selitan] << " and " << data[titik_selitan - 1];
                data[titik_selitan] = data[titik_selitan - 1];
                titik_selitan--;
                alih++;
                sorted = false;
            }
        }

        data[titik_selitan] = item;
        //insert item at the correct place
    } //end for

    auto after = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(after - before).count();

    cout << "\n\nTime taken to sort the data: " << duration << " microseconds";
    cout << "\n\nTotal pass to sort 10 data using insertion sort:  " << (laluan - 1);
    cout << "\nTotal number of data comparison:  " << banding;
    cout << "\nTotal number of data swapping:  " << alih;
}  // end insertionSort()

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
        isihanSelitan(data[i], size);        
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