// Prepared by : Pn Nor Bahiah Hj. Ahmad
// Prepared by : Nor Bahiah Hj. Ahmad
// School of Computing, Faculty of Engineering
// Universiti Teknologi Malaysia
// e-mail : bahiah@utm.my
//
// Reference : data Structure & Problem Solving with C++
// Frank M. Carrano, Pearson International Edition
// IMPROVED BUBBLE SORT

// Modified by Randy Tan Shaoxian
// - Removed unused headers.
// - Removed mixing C and C++ code.
// - Fixed/added code to show time taken to run an algorithm.

#include <iostream>
#include <chrono>

using namespace std;

// Sorts the items in an array into ascending order.
void ImprovedBubbleSort(int data[], int n)
{
    int pass, compare = 0, swap = 0;
    int temp;
    bool sorted = false;  // false when swaps occur

    auto before = chrono::high_resolution_clock::now();

    for (pass = 1; (pass < n) && !sorted; ++pass)
    {
        sorted = true;  // assume sorted
        for (int x = 0; x < n-pass; ++x)
        {
            compare++;

            if (data[x] > data[x + 1]) { // exchange items
              // swap(theArray[index], theArray[nextIndex]);
              temp = data[x];
              data[x] = data[x + 1];
              data[x + 1] = temp;
              sorted = false; // signal exchange
              swap++;
            }
        }
    }

    auto after = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(after - before).count();

    cout << "\n\nTime taken to sort the data: " << duration << " microseconds";
    cout << "\n\nTotal pass in improved bubble sort:  " << pass - 1;
    cout << "\nTotal comparison occur:  " << compare;
    cout << "\nTotal number to exchange data:  " << swap;
}

int main()
{
    int size = 10;
    int x;
    int data[]={12,9,20,18,7,5,15,17,11,25};  // Average Case

    cout << "Content of the array before sort  :" ;
    for (int x = 0; x < size; x++)
        cout << data[x] << "  ";

    ImprovedBubbleSort(data,size);

    cout << "\n\nContent of the array after sort  : ";
    for (int x = 0; x < size; x++)
        cout << data[x] << "  ";

    return 0;
}
