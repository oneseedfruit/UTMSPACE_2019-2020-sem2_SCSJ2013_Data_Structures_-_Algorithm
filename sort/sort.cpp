#include <iostream>

void swap(int &from, int &to)
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
// Swaps:
//      Worst Case: O(n^2)
//      Best Case: O(1)

void bubble_sort(int data[], int count)
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

void bubble_sort_improved(int data[], int count)
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
// Worst Case: O(n^2)
// Best Case: O(n^2)

void selection_sort(int data[], int count)
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

int main(int argc, char **argv)
{
    const int count = 7;
    int data_set[count] = { 10, 9, 20, 21, 4, 99, 6 };
    
    std::cout << "Unsorted: ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << data_set[i] << " ";
    }
    std::cout << "\n";

    selection_sort(data_set, count);

    std::cout << "Sorted: ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << data_set[i] << " ";
    }
    std::cout << "\n";

    return 0;
}