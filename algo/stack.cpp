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

    // Reusing linked list code, top and head are interchangeable
    stack_linkedlist::stack_linkedlist()
    {
        
    }

    bool stack_linkedlist::is_empty() const
    {
        return stack.get_node_at_head() == NULL;
    }

    char stack_linkedlist::get_top() const
    {
        if (!is_empty())
        {
            node *top = stack.get_node_at_head();
            return top->data.c;
        }

        return -1;
    }

    char stack_linkedlist::push(char c)
    {
        lldata l;
        l.c = c;
        node *n = new node(l);
        stack.insert_node_at_head(n);
        return c;
    }

    char stack_linkedlist::pop()
    {
        if (!is_empty())
        {
            node *top = stack.get_node_at_head();
            return stack.remove_node(top)->data.c;
        }

        return -1;
    }

    void stack_linkedlist::free_memory()
    {
        stack.free_memory();
    }
}