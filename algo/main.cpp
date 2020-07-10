#include <iostream>
#include "sort.hpp"
#include "search.hpp"
#include "linkedlist/lldata.hpp"
#include "linkedlist/node.hpp"
#include "linkedlist.hpp"
#include "stack.hpp"
#include "queue.hpp"
using randydsa::sort;
using randydsa::search;
using randydsa::lldata;
using randydsa::node;
using randydsa::linkedlist;
using randydsa::stack_array;
using randydsa::stack_linkedlist;
using randydsa::queue_array;
using randydsa::queue_linkedlist;

void display_linkedlist_content_char(linkedlist);
void display_linkedlist_content_name(linkedlist);

int main(int argc, char **argv)
{
    std::cout << "==================\n";
    std::cout << "Sort and Search: \n";
    std::cout << "==================\n\n";

    const int count = 10;
    int data[count] = { 10, 9, 20, 21, 4, 6, 100, 1, 5, 99 };
    
    std::cout << "Data set: ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Sort
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sort::insertion_sort(data, count);

    std::cout << "Sort: ";
    for (int i = 0; i < count; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
    
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
    lldata linkedlist_data[lldata_count];
    linkedlist_data[0].name = "Deviljho";
    linkedlist_data[1].name = "Brachydios";
    linkedlist_data[2].name = "Tigrex";
    linkedlist_data[3].name = "Zinogre";
    linkedlist_data[4].name = "Glavenus";

    // Nodes
    node *node1_deviljho = new node(linkedlist_data[0]);
    node *node2_brachydios = new node(linkedlist_data[1]);
    node *node3_tigrex = new node(linkedlist_data[2]);
    node *node4_zinogre = new node(linkedlist_data[3]);
    node *node5_glavenus = new node(linkedlist_data[4]);

    // Linked list
    linkedlist list;

    std::cout << "==================\n";
    std::cout << "Linked List: \n";
    std::cout << "==================\n\n";

    // Insert nodes
    list.insert_node(node1_deviljho);
    list.insert_node(node2_brachydios);
    list.insert_node_at_head(node3_tigrex);
    list.insert_node(node4_zinogre);
    list.insert_node(node5_glavenus);    
    
    display_linkedlist_content_name(list);

    std::cout << "\n";

    // Removing a node
    std::cout << "Removing node: " << node2_brachydios->data.name << "\n\n";
    list.remove_node(node2_brachydios);
    display_linkedlist_content_name(list);

    std::cout << "\n";

    // Removing a node by index
    int remove_index = 3;
    std::cout << "Removing node at index: " << remove_index << "\n\n";
    list.remove_node_at_index(remove_index);
    display_linkedlist_content_name(list);

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

    std::cout << "==================\n";
    std::cout << "Stack (Array): \n";
    std::cout << "==================\n\n";

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

    std::cout << "Stack content popped out: ";
    for (int i = 0; !stack.is_empty(); ++i)
    {
        // Pop data from the stack
        std::cout << stack.pop();
    }
    std::cout << "\nStack size after popped: " << stack.count() << "\n";

    std::cout << "\n";

    // Stack implemented using linked list
    stack_linkedlist stackll;

    std::cout << "======================\n";
    std::cout << "Stack (Linked List): \n";
    std::cout << "======================\n\n";
    
    // Push data into the stack
    stackll.push('p');
    stackll.push('m');
    stackll.push('o');
    stackll.push('h');
    stackll.push('c');
    stackll.push('r');
    stackll.push('a');
    stackll.push('g');

    // Get the top of the stack
    std::cout << "Repetitively get the top of the stack: ";
    std::cout << stackll.get_top();
    std::cout << stackll.get_top();
    std::cout << stackll.get_top();
    std::cout << "\nIs stack empty? " << stackll.is_empty() << "\n";

    std::cout << "Stack content popped out: ";
    while (!stackll.is_empty())
    {
        // Pop data from stack
        std::cout << stackll.pop();
    }
    std::cout << "\nIs stack empty? " << stackll.is_empty() << "\n";    

    stackll.free_memory();

    std::cout << "\n";

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Queue
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Queue implemented using array
    queue_array queue_arr;

    std::cout << "==================\n";
    std::cout << "Queue (Array): \n";
    std::cout << "==================\n\n";

    queue_arr.enqueue('r');
    queue_arr.enqueue('a');
    queue_arr.enqueue('t');
    queue_arr.enqueue('h');
    queue_arr.enqueue('a');
    queue_arr.enqueue('l');
    queue_arr.enqueue('o');
    queue_arr.enqueue('s');
    std::cout << "Front: " << queue_arr.get_front() << "; Back: " << queue_arr.get_back() << "\n";
    std::cout << "Is queue empty? " << queue_arr.is_empty() << "\n";

    while (!queue_arr.is_empty())
    {        
        std::cout << "Front: " << queue_arr.get_front() 
                  << "; Back: " << queue_arr.get_back() 
                  << "; Calling dequeue()... Dequeued: " << queue_arr.dequeue() << "\n";        
    }
    std::cout << "Is queue empty? " << queue_arr.is_empty() << "\n";

    std::cout << "\n";

    return 0;
}

void display_linkedlist_content_char(linkedlist list)
{
    std::cout << "Current linked list nodes: \n";
    for (int i = 0; i < list.count(); ++i)
    {
        node *n = list.get_node_at_index(i);
        if (n != NULL)
        {
            std::cout << (n->previous != NULL ? n->previous->data.c : ' ') << " <- "
                      << "[" << n->data.c << "]"
                      << " -> " << (n->next != NULL ? n->next->data.c : ' ')
                      << "\n";
        }            
    }
}

void display_linkedlist_content_name(linkedlist list)
{
    std::cout << "Current linked list nodes: \n";
    for (int i = 0; i < list.count(); ++i)
    {
        node *n = list.get_node_at_index(i);
        if (n != NULL)
        {
            std::cout << "\t" << (n->previous != NULL ? n->previous->data.name : "N/A") << " <- "
                      << "[" << n->data.name << "]"
                      << " -> " << (n->next != NULL ? n->next->data.name : "N/A")
                      << "\n";
        }            
    }
    std::cout << "Head: " << list.get_node_at_head()->data.name << "\n";
    std::cout << "Tail: " << list.get_node_at_tail()->data.name << "\n";
}