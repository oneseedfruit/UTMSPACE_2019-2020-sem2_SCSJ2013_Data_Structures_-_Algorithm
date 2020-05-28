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
	
	while (currNode != NULL && 
           matric.compare(currNode->data.matric) > 0)
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
        std::cout << "\t>>> ---------------------------------------------\n";
        std::cout << "\t>>> Student name: " << name << "\n";
        std::cout << "\t>>> Matric number: " << matric << "\n";
        std::cout << "\t>>> Program: " << program << "\n";
        std::cout << "\t>>> CGPA: " << cgpa << "\n";
        std::cout << "\t>>> ---------------------------------------------\n";
	}
	else 
	{
		newNode->next = prevNode->next;
		prevNode->next = newNode;
		std::cout << "\n\t>>> Operation [INSERT] at middle or back of the list:\n";
        std::cout << "\t>>> ---------------------------------------------\n";
        std::cout << "\t>>> Student name: " << name << "\n";
        std::cout << "\t>>> Matric number: " << matric << "\n";
        std::cout << "\t>>> Program: " << program << "\n";
        std::cout << "\t>>> CGPA: " << cgpa << "\n";
        std::cout << "\t>>> ---------------------------------------------\n";
	}

	return newNode;
}

Node *List::GetNextNodeFromIndex(int index) const
{
	Node *currNode = head;
	int currIndex = 0;

	while (currNode && currIndex != index) 
	{
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode != NULL)
	{
		return currNode;
	}
	else
	{
		return NULL;
	}
}

void List::DisplayList()
{
	int num = 0;
	Node *currNode = head;

    std::cout << "\n\n=================================================\n";
	std::cout << "Content of the list:\n";

	while (currNode != NULL)
	{	
        std::cout << "\n---------------------------------------------\n";
        std::cout << "| Node " << num + 1 << ":\n|\n";
		std::cout << "| Student name: " << currNode->data.name << "\n";
        std::cout << "| Matric number: " << currNode->data.matric << "\n";
        std::cout << "| Program: " << currNode->data.program << "\n";
        std::cout << std::setprecision(2) << std::fixed;
        std::cout << "| CGPA: " << currNode->data.cgpa;
        std::cout << "\n---------------------------------------------\n";
		currNode = currNode->next;
		num++;
	}

	std::cout << "\nNumber of nodes in the list: " << num;
    std::cout << "\n=================================================\n\n";
}

int List::FindNextNodeWith(float x)
{
	Node *currNode = head;
	int currIndex =	0;

	while (currNode && currNode->data.cgpa != x) 
	{
		currNode = currNode->next;
		currIndex++;
	}

	if (currNode)
	{
		return currIndex;
	}
	else
	{
		return -1;
	}
}

int List::FindNextNodeWith(std::string query)
{
    Node *currNode = head;
	int currIndex =	0;

	while (currNode &&            
			currNode->data.matric != query)
	{
		currNode = currNode->next;
		currIndex++;
	}

	if (currNode)
	{
		return currIndex;
	}
	else
	{
		return -1;
	}
}

int List::DeleteNextNodeWith(std::string matric)
{	
	Node *prevNode = NULL;
	int currIndex =	FindNextNodeWith(matric);
	Node *currNode = GetNextNodeFromIndex(currIndex);

	if (currIndex > 0)
	{
		prevNode = GetNextNodeFromIndex(currIndex - 1);
	}

	if (currNode) 
	{
		if (prevNode) 
		{
			prevNode->next = currNode->next;
			std::cout << "\n\t>>> Operation [DELETE] at the back or middle of the list:\n";
            std::cout << "\t>>> ---------------------------------------------\n";
            std::cout << "\t>>> Student name: " << currNode->data.name << "\n";
            std::cout << "\t>>> Matric number: " << currNode->data.matric << "\n";
            std::cout << "\t>>> Program: " << currNode->data.program << "\n";
            std::cout << "\t>>> CGPA: " << currNode->data.cgpa << "\n";
            std::cout << "\t>>> ---------------------------------------------\n";
			delete currNode;
			currNode = NULL;
        }
        else
		{
			head = currNode->next;
            std::cout << "\n\t>>> Operation [DELETE] at the front of the list:\n";
            std::cout << "\t>>> ---------------------------------------------\n";
            std::cout << "\t>>> Student name: " << currNode->data.name << "\n";
            std::cout << "\t>>> Matric number: " << currNode->data.matric << "\n";
            std::cout << "\t>>> Program: " << currNode->data.program << "\n";
            std::cout << "\t>>> CGPA: " << currNode->data.cgpa << "\n";
            std::cout << "\t>>> ---------------------------------------------\n";
			delete currNode;
			currNode = NULL;			
		}

		return currIndex;
	}

	return 0;
}