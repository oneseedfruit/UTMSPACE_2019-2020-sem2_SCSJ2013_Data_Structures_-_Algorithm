#include <iostream>
#include "sort/sort.hpp"
using randydsa::sort;

int main(int argc, char **argv)
{
    const int count = 10;
    int data_set[count] = { 10, 9, 20, 21, 4, 99, 6, 100, 1, 5 };
    
    std::cout << "Unsorted: ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << data_set[i] << " ";
    }
    std::cout << "\n";

    sort::insertion_sort(data_set, count);

    std::cout << "Sorted: ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << data_set[i] << " ";
    }
    std::cout << "\n";

    return 0;
}