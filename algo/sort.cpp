#include "sort.hpp"

namespace randydsa
{
    void sort::swap(int &from, int &to)
    {
        int temp = from;
        from = to;
        to = temp;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Bubble Sort
    //
    // Compares:
    //      Worst Case: O(n^2)
    //      Best Case: O(n)
    // Swaps / Element Shifts:
    //      Worst Case: O(n^2)
    //      Best Case: O(1)

    void sort::bubble_sort(int data[], int count)
    {
        for (int i = 0; i < count - 1; ++i) // loop through every element until right BEFORE the last element
        {
            for (int j = 0; j < count - i; ++j)
            {
                if (data[j] > data[j + 1]) // if this element is greater than the next element
                {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }

    void sort::bubble_sort_improved(int data[], int count)
    {
        bool sorted = false; // flag to stop looping through every element again if already sorted
        for (int i = 0; i < count - 1 && !sorted; ++i) // loop through every element until right BEFORE the last element
        {
            sorted = true;
            for (int j = 0; j < count - i; ++j)
            {
                if (data[j] > data[j + 1]) // if this element is greater than the next element
                {
                    swap(data[j], data[j + 1]);
                    sorted = false;
                }
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Selection Sort
    //
    // Compares:
    //      Worst Case: O(n^2)
    //      Best Case: O(n^2)
    // Swaps / Element Shifts:
    //      Worst Case: O(n)
    //      Best Case: O(n)

    void sort::selection_sort(int data[], int count)
    {
        for (int i = count - 1; i >= 0; --i) // loop through every element descendingly
        {
            int largest = 0; // keep track of the index of the largest element

            for (int j = 0; j <= i; ++j)
            {
                if (data[j] > data[largest]) // if this element is greater than the element with the largest value
                {
                    largest = j; // re-determine the largest value, re-assign its index
                }
            }

            if (largest != i) // no need to swap if index is the same
                swap(data[largest], data[i]); // swap the largest value with the current value
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Insertion Sort
    //
    // Compares:
    //      Worst Case: O(n^2)
    //      Best Case: O(n)
    // Swaps / Element Shifts:
    //      Worst Case: O(n^2)
    //      Best Case: O(1)

    void sort::insertion_sort(int data[], int count)
    {
        for (int i = 0, item, insert_at; i < count - 1; ++i) // loop through every element until right BEFORE the last element
        {
            item = data[i + 1];
            insert_at = i + 1;

            while (insert_at > 0 && data[insert_at - 1] > item)       
            {
                data[insert_at] = data[insert_at - 1];
                --insert_at;
            }

            data[insert_at] = item;
        }
    }
}