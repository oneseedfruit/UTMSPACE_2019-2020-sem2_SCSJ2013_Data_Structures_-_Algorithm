#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "linkedlist/node.hpp"

namespace randydsa
{
    class linkedlist
    {
    public:
        node *head;
        int node_count;

        linkedlist();

        bool is_empty() const;
        node *insert_node(node *);
        node *remove_node(node *, bool freemem = true);
        node *remove_node_at_index(int);
        node *get_node_at_index(int) const;
        int get_index_of_node(node *) const;
    };
}

#endif