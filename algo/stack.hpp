#ifndef STACK_HPP
#define STACK_HPP

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
}

#endif