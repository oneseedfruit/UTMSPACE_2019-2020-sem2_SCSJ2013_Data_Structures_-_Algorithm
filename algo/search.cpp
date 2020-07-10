#include "search.hpp"

namespace randydsa
{
    // Sequential Search (simply loop through the whole array and see if searched == an element in the array)
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

    // Works on (ascendingly) sorted data only!
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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Binary Search (split the array in half in each iteration then see if searched == the middle element at the current iteration,
    //                if not, split the array in half again, then look through which half (left half or right half based on whether 
    //                                                                                     searched is less than or
    //                                                                                     greater than the current middle),
    //                                                            while the other half is simply discarded (not needed anymore)
    //                repeat until searched == the current middle)
    //
    // All Cases: log<sub>2</sub>n

    // Works on (ascendingly) sorted data only!
    int search::binary_search_sorted(int search_for, int data[], int count)
    {        
        int found = -1;
        
        // Need to maintain left marker l, middle marker m, right marker r throughout the iterations
        //      l starts at beginning of array, index 0, but will be moved towards the right of the current middle (moved a lot to the right)
        //      r starts at end of array, count - 1, but will be moved towards the left of the current middle (moved a lot to the left)
        for (int l = 0, m, r = count - 1; l <= r; )
        {
            m = (l + r) /  2; // move the middle marker according to the current l and r
            
            if (search_for == data[m]) // it's always about seeing if the element at the middle matches
            {
                found = m; // get the index if a match is found
                break; // then stop searching
            }
            else if (search_for < data[m]) // if searched is less than the current middle
            {
                r = m - 1; // move the right marker by one index to the left of the current middle (array split in half, then check the left half)
                           //                                     (imagine moving the right marker drastically to the left, split when m is moved)
                           //                                     (we don't place it at m because m already doesn't match)
            }
            else // if searched is greater than the current middle element
            {
                l = m + 1; // move the left marker by one index to the right of the current middle (array split in half, then check the right half)
                           //                                     (imagine moving the left marker drastically to the right, split when m is moved)
                           //                                     (we don't place it at m because m already doesn't match)
            }
        }

        return found; // return the result as the index of the found data in the data set
    }
}