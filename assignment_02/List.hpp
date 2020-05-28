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
    int FindNextNodeWith(float);
	int FindNextNodeWith(std::string);    
	int DeleteNextNodeWith(std::string);
	void DisplayList(void);

private:
	Node *head;
};

#endif