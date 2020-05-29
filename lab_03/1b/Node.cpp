#include <iostream>
#include "Node.hpp"

Node::Node()
{
    prev = NULL;
    next = NULL;    
}

Node::Node(int val)
{
    prev = NULL;
    next = NULL;
    value = val;
}