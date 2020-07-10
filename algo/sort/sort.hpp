#ifndef SORT_HPP
#define SORT_HPP

namespace randydsa
{
    class sort
    {
        private:
            static void swap(int &, int &);

        public:
            static void bubble_sort(int[], int);
            static void bubble_sort_improved(int[], int);
            static void selection_sort(int[], int);
            static void insertion_sort(int[], int);            
    };
}

#endif