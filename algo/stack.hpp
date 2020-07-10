#ifndef STACK_HPP
#define STACK_HPP

#include "linkedlist/lldata.hpp"
#include "linkedlist.hpp"

namespace randydsa
{
    const int stack_size = 10;

    class stack_array
    {
    private:
        int top;        
        char data[stack_size];

    public:
        stack_array();
        bool is_full() const;
        bool is_empty() const;
        int count() const;
        char push(char);
        char pop();
        void clear();
    };

    class stack_linkedlist
    {
    private:
        linkedlist stack;

    public:
        stack_linkedlist();
        bool is_empty() const;
        char get_top() const;
        char push(char);
        char pop();
        void free_memory();
    };
}

#endif