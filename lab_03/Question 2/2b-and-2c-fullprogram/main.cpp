#include <iostream>
#include "Node.hpp"
#include "List.hpp"

int main()
{
    List list;
    list.InsertNode(5);
    list.InsertNode(10);
    list.InsertNode(8);

    list.DisplayList();
    std::cout << "\n";

    // 2. b.
    Node *newNode = new Node(23);
    list.InsertNodeAtHead(newNode);

    list.DisplayList();
    std::cout << "\n";

    // 2. c.
    list.DeleteNodeAtTail();

    list.DisplayList();
    std::cout << "\n";

    list.ClearListAndFreeMemory();

    return 0;
}