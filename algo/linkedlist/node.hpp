#ifndef NODE_HPP
#define NODE_HPP

#include "lldata.hpp"

namespace randydsa
{
    class node
    {
    public:
        lldata data;
        node *next;
        node *previous;

        node(lldata);
    };
}

#endif