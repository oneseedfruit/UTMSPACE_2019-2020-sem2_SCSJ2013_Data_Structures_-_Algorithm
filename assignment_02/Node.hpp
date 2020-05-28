#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include "StudentInfo.hpp"

class Node
{
public:
	StudentInfo data; // data
	Node *next;	// pointer to next node
};

#endif