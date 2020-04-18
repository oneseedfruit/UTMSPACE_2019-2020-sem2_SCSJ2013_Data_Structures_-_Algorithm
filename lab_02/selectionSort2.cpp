// Selection Sort Program
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

#include <iostream>
#include <chrono>

using namespace std;

void swapData(int& x, int& y)
{   
    int temp = x;
    x = y;   
    y = temp;
}  // end swap

void selectionSort(int data[],int n)
{  
    int p, largestIndex, last;
    int pass = 0, compare = 0, swap = 0;

    auto before = chrono::high_resolution_clock::now();

    for (last = n - 1; last > 0; --last)
    //ulang dari bahagian akhir 
    //tatasusunan hingga indek 0
    {
        pass++;
        largestIndex = 0;
        for (p = 1; p <= last; ++p)  {
            //mencari data terbesar
            //dlm laluan dari bawah tts
            compare++;
            if (data[p]>data[largestIndex] )
                largestIndex = p;
        }
        // swap value at last with the largest value
       
         cout << "\nSwap between value " << data[last] << " and " << data[largestIndex];
         swapData(data[last],data[largestIndex]);
         swap++;       
    }

    auto after = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(after - before).count();

    cout << "\n\nTime taken to sort the data: " << duration << " microseconds";
    cout << "\n\nTotal pass to sort 10 data using selection sort:  " << pass;
    cout << "\nTotal number of data comparison:  " << compare;
    cout << "\nTotal number of data swapping :  " << swap;

}

int main()
{
    int saiz = 10;
    int x;
    int data[]={12,9,20,18,7,5,15,17,11,25};   // Average Case
    //int data[]={11,12,13,14,15,16,17,18,19,20};   // Best Case

    cout << "Content of the array before sort  :" ;
    for (int x = 0; x < saiz; x++)
    	cout << data[x] << "  ";

    selectionSort(data,saiz);

    cout << "\n\nContent of the array after sort : ";
    for (int x = 0; x < saiz; x++)
    	cout << data[x] << "  ";

    return 0;
}
