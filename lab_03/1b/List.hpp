#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"

class List
{
public:
    List();
    bool IsEmpty() const;
    int Count() const;
    Node *InsertNode(Node *);
    Node *InsertNode(Node *, int);
    Node *InsertNode(int);
    Node *InsertNode(int, int);
    Node *GetNodeAtIndex(int);
    Node DeleteNodeAtIndex(int);
    void DisplayList() const;

private:
    int count;
    Node *head;
};

#endif