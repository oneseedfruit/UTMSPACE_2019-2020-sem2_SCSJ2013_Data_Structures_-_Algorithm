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
	Node *InsertNode(std::string, std::string, std::string, float, bool verbose = false);
	Node *InsertNode(Node *, bool verbose = false);
	Node *GetNextNodeFromIndex(int) const;
    int FindNextNodeWith(float, bool verbose = false) const;
	int FindNextNodeWith(std::string, bool verbose = false) const;
	int DeleteNextNodeWith(int, bool verbose = false);
	int DeleteNextNodeWith(std::string, bool verbose = false);
	void ClearList(bool verbose = false);
	void DisplayList(bool verbose = false) const;
	int Count() const;

private:
	int count;
	Node *head;
};

#endif