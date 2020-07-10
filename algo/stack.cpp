#include "stack.hpp"

namespace randydsa
{
    stack_array::stack_array()
    {
        top = -1;        
    }

    bool stack_array::is_full() const
    {
        return top == (stack_size - 1);
    }

    bool stack_array::is_empty() const
    {
        return top == -1;
    }

    int stack_array::count() const
    {
        return top + 1;
    }

    char stack_array::push(char c)
    {
        if (!is_full())
        {
            ++top;            
            data[top] = c;
        }

        return data[top];
    }

    char stack_array::pop()
    {
        char c = -1;
        if (!is_empty())
        {
            c = data[top];
            --top;
        }

        return c;
    }

    void stack_array::clear()
    {
        for (int i = top; i > -1; --i)
        {
            pop();            
        }
    }
}