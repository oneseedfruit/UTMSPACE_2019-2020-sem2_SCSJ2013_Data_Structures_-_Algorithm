#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "linkedlist/node.hpp"

namespace randydsa
{
    class linkedlist
    {
    private:
        node *head;
        node *tail;
        int node_count;

    public:
        linkedlist();
        bool is_empty() const;
        int count() const;        
        node *insert_node(node *);
        node *insert_node_at_head(node *);
        node *remove_node(node *, bool freemem = false);
        node *remove_node_at_index(int, bool freemem = false);
        node *get_node_at_index(int) const;
        node *get_node_at_head() const;
        node *get_node_at_tail() const;
        int get_index_of_node(node *) const;
        void free_memory();
    };
}

#endif