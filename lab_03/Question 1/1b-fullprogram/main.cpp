#include <iostream>
#include "Node.hpp"
#include "List.hpp"

int main()
{
    List list;
    int sum = 0;

    list.InsertNode(10);
    list.InsertNode(15);
    list.InsertNode(20);
    list.InsertNode(35);
    list.InsertNode(12);

    Node *newNode1 = new Node(16);
    Node *newNode2 = new Node(50);

    list.DisplayList();

    std::cout << "\n";
    for (int i = 0; i < list.Count(); ++i)
    {
        sum += list.GetNodeAtIndex(i)->value;
    }    
    std::cout << "Average of " << list.Count() << " values with a sum of " << sum << " is: " << sum * 1.0 / list.Count() << "\n\n";
    sum = 0;

    std::cout << "\nInsert newNode1 at head...\n\n";
    list.InsertNode(newNode1, 0);

    list.DisplayList();

    std::cout << "\n";    
    for (int i = 0; i < list.Count(); ++i)
    {
        sum += list.GetNodeAtIndex(i)->value;
    }    
    std::cout << "Average of " << list.Count() << " values with a sum of " << sum << " is: " << sum * 1.0 / list.Count() << "\n\n";
    sum = 0;

    std::cout << "\nInsert newNode2 after 20...\n\n";
    list.InsertNode(newNode2, 4);

    list.DisplayList();

    std::cout << "\n";    
    for (int i = 0; i < list.Count(); ++i)
    {
        sum += list.GetNodeAtIndex(i)->value;
    }    
    std::cout << "Average of " << list.Count() << " values with a sum of " << sum << " is: " << sum * 1.0 / list.Count() << "\n\n";
    sum = 0;

    std::cout << "\nDelete 35...\n\n";
    list.DeleteNodeAtIndex(5);

    list.DisplayList();

    std::cout << "\n";    
    for (int i = 0; i < list.Count(); ++i)
    {
        sum += list.GetNodeAtIndex(i)->value;
    }    
    std::cout << "Average of " << list.Count() << " values with a sum of " << sum << " is: " << sum * 1.0 / list.Count() << "\n\n";
    sum = 0;

    list.ClearListAndFreeMemory();

    return 0;
}