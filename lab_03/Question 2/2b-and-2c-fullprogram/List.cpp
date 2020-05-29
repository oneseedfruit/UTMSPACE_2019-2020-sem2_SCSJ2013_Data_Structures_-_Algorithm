#include <iostream>
#include "List.hpp"

List::List()
{
    count = 0;
    head = NULL;
}

bool List::IsEmpty() const
{
    return head == NULL;
}

int List::Count() const
{
    return count;
}

Node *List::InsertNode(Node *node)
{
    return InsertNode(node, count);
}

Node *List::InsertNode(Node *node, int at)
{
    bool emptyHead = true;    

    int currIndex = 0;
    Node *prevNode = NULL;
    Node *currNode = head;

    while (currNode != NULL && at > currIndex)
    {
        prevNode = currNode;
        currNode = currNode->next;
        emptyHead = false;
        ++currIndex;
    }
    
    ++count;

    if (emptyHead)
    {
        node->prev = head;
        node->next = head;
        head = node;
    }
    else
    {
        node->prev = prevNode;
        node->next = prevNode->next;
        prevNode->next = node;
    }    

    return node;
}

Node *List::InsertNodeAtHead(Node *node)
{
    return InsertNode(node, 0);
}

Node *List::InsertNode(int value)
{    
    return InsertNode(value, count);
}

Node *List::InsertNode(int value, int at)
{    
    Node *newNode = new Node(value);
    return InsertNode(newNode, at);
}

Node *List::InsertNodeAtHead(int value)
{
    return InsertNode(value, 0);
}

Node *List::GetNodeAtIndex(int at)
{
    int currIndex = 0;
    Node *currNode = head;

    if (head != NULL)
    {
        while (currNode && currIndex != at)
        {            
            currNode = currNode->next;
            ++currIndex;
        }
    }

    return currNode;
}

Node List::DeleteNodeAtIndex(int at)
{
    bool emptyHead = true;    

    int currIndex = 0;
    Node *prevNode = NULL;
    Node *currNode = head;

    while (currNode != NULL && at != currIndex)
    {
        prevNode = currNode;
        currNode = currNode->next;
        emptyHead = false;
        ++currIndex;
    }
    
    if (emptyHead)
    {
        currNode->prev = head;
        currNode->next = head;
        head = currNode;
    }
    else
    {
        currNode->prev = prevNode;
        prevNode->next = currNode->next;        
    }    

    Node n(*currNode);
    delete currNode;
    currNode = NULL;

    --count;

    return n;
}

Node List::DeleteNodeAtTail()
{
    return DeleteNodeAtIndex(count - 1);
}

void List::DisplayList() const
{
    Node *currNode = head;

    if (head != NULL)
    {
        while (currNode)
        {
            std::cout << currNode->value << "\n";
            currNode = currNode->next;    
        }
    }
}

void List::ClearListAndFreeMemory()
{	
	Node* currNode = head;	

	if (head)
	{
		currNode = head->next;
		delete head;
		head = NULL;
		--count;
	}
	
	while (currNode)
	{
		Node *delNode = currNode;
		currNode = currNode->next;
		delete delNode;
		delNode = NULL;
		--count;
	}
}