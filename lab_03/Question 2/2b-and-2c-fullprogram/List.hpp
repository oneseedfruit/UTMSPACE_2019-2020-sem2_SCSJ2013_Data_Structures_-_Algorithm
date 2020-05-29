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
    Node *InsertNodeAtHead(Node *);
    Node *InsertNode(int);
    Node *InsertNode(int, int);
    Node *InsertNodeAtHead(int);
    Node *GetNodeAtIndex(int);
    Node DeleteNodeAtIndex(int);
    Node DeleteNodeAtTail();
    void DisplayList() const;
    void ClearListAndFreeMemory();

private:
    int count;
    Node *head;
};

#endif