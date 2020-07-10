#ifndef SEARCH_HPP
#define SEARCH_HPP

namespace randydsa
{
    class search
    {
    public:
        static int sequential_search_unsorted(int, int[], int);
        static int sequential_search_sorted(int, int[], int);
        static int binary_search_sorted(int, int[], int);
    };
}

#endif