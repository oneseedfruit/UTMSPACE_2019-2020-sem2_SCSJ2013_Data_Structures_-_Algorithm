#include <iostream>
#include "sort.hpp"
#include "search.hpp"
#include "linkedlist/lldata.hpp"
#include "linkedlist/node.hpp"
#include "linkedlist.hpp"
#include "stack.hpp"
using randydsa::sort;
using randydsa::search;
using randydsa::lldata;
using randydsa::node;
using randydsa::linkedlist;
using randydsa::stack_array;

void display_linkedlist_content(linkedlist);

int main(int argc, char **argv)
{
    const int count = 10;
    int data[count] = { 10, 9, 20, 21, 4, 6, 100, 1, 5, 99 };
    
    std::cout << "Data set: ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n\n";

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Sort
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sort::insertion_sort(data, count);

    std::cout << "Data set (sorted): ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n\n";
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Search
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int search_for_this = 20;
    int found_at = search::binary_search_sorted(search_for_this, data, count);

    std::cout << "Search: " << search_for_this << " found at index " << found_at << " (zero indexed).\n\n";

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Linked List
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Node data
    const int lldata_count = 5;
    lldata lldata[lldata_count];
    lldata[0].name = "Deviljho";
    lldata[1].name = "Brachydios";
    lldata[2].name = "Tigrex";
    lldata[3].name = "Zinogre";
    lldata[4].name = "Glavenus";

    // Nodes
    node *node1_deviljho = new node(lldata[0]);
    node *node2_brachydios = new node(lldata[1]);
    node *node3_tigrex = new node(lldata[2]);
    node *node4_zinogre = new node(lldata[3]);
    node *node5_glavenus = new node(lldata[4]);

    // Linked list
    linkedlist list;

    // Insert nodes
    list.insert_node(node1_deviljho);
    list.insert_node(node2_brachydios);
    list.insert_node_at_head(node3_tigrex);
    list.insert_node(node4_zinogre);
    list.insert_node(node5_glavenus);
    
    display_linkedlist_content(list);

    std::cout << "\n";

    // Removing a node
    int remove_index = 3;
    std::cout << "Removed node at index: " << remove_index << "\n";
    std::cout << "Output from node removal: " << list.remove_node_at_index(remove_index) << "\n";
    std::cout << "\n";

    display_linkedlist_content(list);

    std::cout << "\n";

    // Finding a node
    node *node_to_find = node3_tigrex;
    int found_index = list.get_index_of_node(node_to_find);
    std::cout << "Find index by node... (looking for " << node_to_find->data.name << ")" << "\n";
    if (found_index > -1)
    {   
        std::cout << "Found at index: " << found_index << "\n";
        std::cout << "Content of node: " << list.get_node_at_index(found_index)->data.name << "\n";
    }
    else
    {
        std::cout << "Node not found!" << "\n";
    }
    
    std::cout << "\n";

    // Free all memory allocated by nodes added to the linked list
    list.free_memory();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Stack
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Stack implemented using array    
    stack_array stack;

    // Push data into the stack
    stack.push('p');
    stack.push('m');
    stack.push('o');
    stack.push('h');
    stack.push('c');
    stack.push('r');
    stack.push('a');
    stack.push('g');    
    std::cout << "Stack size after pushed: " << stack.count() << "\n";

    for (int i = 0; !stack.is_empty(); ++i)
    {
        // Pop data from the stack
        std::cout << stack.pop();
    }
    std::cout << "\nStack size after popped: " << stack.count() << "\n";

    std::cout << "\n";

    return 0;
}

void display_linkedlist_content(linkedlist list)
{
    std::cout << "Current linked list nodes: \n";
    for (int i = 0; i < list.node_count; ++i)
    {
        node *n = list.get_node_at_index(i);
        if (n != NULL)
        {
            std::cout << (n->previous != NULL ? n->previous->data.name : "N/A") << " <- "
                      << "[" << n->data.name << "]"
                      << " -> " << (n->next != NULL ? n->next->data.name : "N/A")
                      << "\n";
        }            
    }
}