#ifndef NODE_HPP
#define NODE_HPP

class Node
{
public:
    Node *prev;
    Node *next;
    int value;

    Node();
    Node(int);
};

#endif