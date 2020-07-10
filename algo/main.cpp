#include <iostream>
#include "sort.hpp"
#include "search.hpp"
using randydsa::sort;
using randydsa::search;

int main(int argc, char **argv)
{
    const int count = 10;
    int data[count] = { 10, 9, 20, 21, 4, 6, 100, 1, 5, 99 };
    
    std::cout << "Data set: ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n\n";

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Sort
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sort::insertion_sort(data, count);

    std::cout << "Data set (sorted): ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n\n";
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Search
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int search_for_this = 100;
    int found_at = search::sequential_search_unsorted(search_for_this, data, count);

    std::cout << search_for_this << " found at index " << found_at << " (zero indexed).\n\n";

    return 0;
}