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

	bool IsEmpty() const;
	Node *InsertNode(std::string, std::string, std::string, float);
	Node *GetNextNodeFromIndex(int) const;
    int FindNextNodeWith(float) const;
	int FindNextNodeWith(std::string) const;    
	int DeleteNextNodeWith(std::string);
	void DisplayList(void) const;

private:
	Node *head;
};

#endif