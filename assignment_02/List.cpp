#include <iostream>
#include <iomanip>
#include "List.hpp"

List::List()
{
    head = NULL;
	count = 0;
}

bool List::IsEmpty() const
{
    return head == NULL;
}

Node* List::InsertNode(std::string name, std::string matric, std::string program, float cgpa, bool verbose)
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
	++count;

	if (currIndex == 0) 
	{
		newNode->next = head;
		head = newNode;
		if (verbose)
		{
			std::cout << "\n\t>>> Operation [INSERT] at empty or front of the list:\n";
        	newNode->DisplayNode(1);
		}
	}
	else 
	{
		newNode->next = prevNode->next;
		prevNode->next = newNode;
		if (verbose)
		{
			std::cout << "\n\t>>> Operation [INSERT] at middle or back of the list:\n";
        	newNode->DisplayNode(1);
		}
	}

	return newNode;
}

Node *List::InsertNode(Node *node, bool verbose)
{
	return InsertNode(node->data.name, node->data.matric, node->data.program, node->data.cgpa, verbose);
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

int List::FindNextNodeWith(float CGPA, bool verbose) const
{
	int currIndex =	0;
	Node *currNode = head;

    if (verbose)
    {
		std::cout << std::setprecision(2) << std::fixed;
        std::cout << "\n\t>>> Operation [FIND] node with CGPA \"" << CGPA << "\":\n";
    }

	while (currNode && currNode->data.cgpa != CGPA) 
	{
		currNode = currNode->next;
		currIndex++;
	}

	if (verbose)
	{
		if (currNode)
		{
			std::cout << "\t>>> Found!\n\n";
		}
		else
		{
			std::cout << "\t>>> Not found!\n\n";
		}
	}

	return currNode ? currIndex : -1;
}

int List::FindNextNodeWith(std::string matric, bool verbose) const
{
	int currIndex =	0;
    Node *currNode = head;

	if (verbose)
    {		
        std::cout << "\n\t>>> Operation [FIND] node with matric number \"" << matric << "\":\n";
    }

	while (currNode && currNode->data.matric != matric)
	{
		currNode = currNode->next;
		currIndex++;
	}

	if (verbose)
	{
		if (currNode)
		{
			std::cout << "\t>>> Found!\n\n";
		}
		else
		{
			std::cout << "\t>>> Not found!\n\n";
		}
	}
	
	return currNode ? currIndex : -1;
}

int List::DeleteNextNodeWith(int index, bool verbose)
{	
	int currIndex =	index;
	Node *prevNode = currIndex > 0 ? GetNextNodeFromIndex(currIndex - 1) : NULL;
	Node *currNode = GetNextNodeFromIndex(currIndex);

	if (currNode) 
	{
		if (prevNode)
		{
			prevNode->next = currNode->next;
			if (verbose)
			{
				std::cout << "\n\t>>> Operation [DELETE] at the back or middle of the list:\n";
			}
        }
        else
		{
			head = currNode->next;
			if (verbose)
			{
            	std::cout << "\n\t>>> Operation [DELETE] at the front of the list:\n";
			}
		}

		if (verbose)
		{
			currNode->DisplayNode(1);
		}

		delete currNode;
		currNode = NULL;
		--count;

		return currIndex;
	}

	return 0;
}

int List::DeleteNextNodeWith(std::string matric, bool verbose)
{	
	int currIndex =	FindNextNodeWith(matric, verbose);
	return DeleteNextNodeWith(currIndex, verbose);
}

void List::ClearList(bool verbose)
{		
	for (int i = 0; i < count; ++i)
	{
		DeleteNextNodeWith(i, verbose);
	}
}

void List::DisplayList(bool verbose) const
{	
	Node *currNode = head;
	if (verbose)
	{
		std::cout << "\n\t>>> Operation [SHOW ALL NODES]:\n";
	}
    std::cout << "\n=================================================\n";
	std::cout << "Content of the list: \n(sorted ascendingly by matric number)\n";

	while (currNode != NULL)
	{			
        currNode->DisplayNode(verbose);
		currNode = currNode->next;		
	}

	std::cout << "\nNumber of nodes in the list: " << count;
    std::cout << "\n=================================================\n\n";
}

int List::Count() const
{
	return count;
}