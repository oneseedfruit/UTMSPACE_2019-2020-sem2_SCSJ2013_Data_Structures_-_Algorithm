#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>
#include "Node.hpp"
#include "StudentInfo.hpp"

class List
{
public:
	List(void); // constructor
//	~List(void); // destructor

	bool IsEmpty();
	Node *InsertNode(std::string, std::string, std::string, float);	
    int FindNode(float);
	int FindNode(std::string);    
	int DeleteNode(std::string);
	void DisplayList(void);

private:
	Node *head;
};

#endif