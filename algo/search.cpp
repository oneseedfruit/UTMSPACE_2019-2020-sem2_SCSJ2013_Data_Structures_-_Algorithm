#include "search.hpp"
#include "sort.hpp"

namespace randydsa
{
    // Sequential Search
    //
    // Worst Case: O(n)     // if searched data is not found yet, need to keep traverse the array of data n times
    // Best Case: O(1)      // if searched data is found at the start of the array, no need to traverse array

    // Works on both sorted and unsorted data
    int search::sequential_search_unsorted(int search_for, int data[], int count)
    {        
        int found = -1; // initialize found index to -1, means not found

        for (int i = 0; i < count; ++i) // loop through every element
        {
            if (search_for == data[i]) // if a matching data is found
            {
                found = i; // get its index
                break;     // then break out of the loop, done searching
            }
        }

        return found; // return the result as the index of the found data in the data set
    }

    // Works on sorted data only!
    int search::sequential_search_sorted(int search_for, int data[], int count)
    {
        int found = -1; // initialize found index to -1, means not found

        for (int i = 0; i < count; ++i) // loop through every element
        {
            if (search_for < data[i]) // if searched data is less than current element
            {
                break; // break out of the loop, don't continue searching
            }
            else if (search_for == data[i]) // if a matching data is found
            {
                found = i; // get its index
                break;     // then break out of the loop, done searching
            }
        }

        return found; // return the result as the index of the found data in the data set
    }
}