#include <iostream>
#include <iomanip>
#include "List.hpp"

List::List()
{
    head = NULL;
}

bool List::IsEmpty() const
{
    return head == NULL; 
}

Node* List::InsertNode(std::string name, std::string matric, std::string program, float cgpa)
{		
	int currIndex = 0;
	Node *currNode = head;
	Node *prevNode = NULL;
	
	while (currNode != NULL && matric.compare(currNode->data.matric) > 0)
	{
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}

	Node *newNode = new Node;	
    newNode->data.name = name;
    newNode->data.matric = matric;
    newNode->data.program = program;
	newNode->data.cgpa = cgpa;

	if (currIndex == 0) 
	{
		newNode->next = head;
		head = newNode;
		std::cout << "\n\t>>> Operation [INSERT] at empty or front of the list:\n";
        newNode->DisplayNode(1);
	}
	else 
	{
		newNode->next = prevNode->next;
		prevNode->next = newNode;
		std::cout << "\n\t>>> Operation [INSERT] at middle or back of the list:\n";
        newNode->DisplayNode(1);
	}

	return newNode;
}

Node *List::GetNextNodeFromIndex(int index) const
{
	int currIndex = 0;
	Node *currNode = head;

	while (currNode && currIndex != index) 
	{
		currNode = currNode->next;
		currIndex++;
	}

	return currNode != NULL ? currNode : NULL;	
}

void List::DisplayList() const
{
	int num = 0;
	Node *currNode = head;

    std::cout << "\n\n=================================================\n";
	std::cout << "Content of the list:\n";

	while (currNode != NULL)
	{			
        currNode->DisplayNode();
		currNode = currNode->next;
		num++;
	}

	std::cout << "\nNumber of nodes in the list: " << num;
    std::cout << "\n=================================================\n\n";
}

int List::FindNextNodeWith(float CGPA) const
{
	int currIndex =	0;
	Node *currNode = head;

	while (currNode && currNode->data.cgpa != CGPA) 
	{
		currNode = currNode->next;
		currIndex++;
	}

	return currNode ? currIndex : -1;
}

int List::FindNextNodeWith(std::string query) const
{
	int currIndex =	0;
    Node *currNode = head;

	while (currNode && currNode->data.matric != query)
	{
		currNode = currNode->next;
		currIndex++;
	}
	
	return currNode ? currIndex : -1;
}

int List::DeleteNextNodeWith(std::string matric)
{	
	int currIndex =	FindNextNodeWith(matric);
	Node *prevNode = currIndex > 0 ? GetNextNodeFromIndex(currIndex - 1) : NULL;
	Node *currNode = GetNextNodeFromIndex(currIndex);

	if (currNode) 
	{
		if (prevNode)
		{
			prevNode->next = currNode->next;
			std::cout << "\n\t>>> Operation [DELETE] at the back or middle of the list:\n";            
        }
        else
		{
			head = currNode->next;
            std::cout << "\n\t>>> Operation [DELETE] at the front of the list:\n";
		}

		currNode->DisplayNode(1);
		delete currNode;
		currNode = NULL;

		return currIndex;
	}

	return 0;
}