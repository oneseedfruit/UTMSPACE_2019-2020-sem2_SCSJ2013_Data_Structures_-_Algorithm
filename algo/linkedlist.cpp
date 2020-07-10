#include "linkedlist.hpp"

namespace randydsa
{
    linkedlist::linkedlist()
    {
        head = NULL;
        node_count = 0;
    }

    bool linkedlist::is_empty() const
    {
        return head == NULL;
    }

    node *linkedlist::insert_node(node *_node)
    {
        if (head == NULL)
        {
            _node->next = head;
            head = _node;
            ++node_count;
            return _node;
        }
        
        node *currentNode = head;
        node *previousNode = NULL;

        while (currentNode != NULL /* && insert comparison condition here to insert ascendingly/descendingly */)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }        

        _node->next = previousNode->next;
        _node->previous = previousNode;
        previousNode->next = _node;
        ++node_count;
        return _node;
    }

    node *linkedlist::remove_node(node *_node, bool freemem)    
    {
        if (_node->previous == NULL)
        {
            head = _node->next;
            head->previous = NULL;
            --node_count;

            if (freemem)
            {
                delete _node;
                _node = NULL;
            }
            return _node;
        }

        if (_node->next == NULL)
        {
            _node->previous->next = NULL;
            --node_count;

            if (freemem)
            {
                delete _node;
                _node = NULL;
            }
            return _node;
        }
        
        node *prevNode = _node->previous;
        node *nextNode = _node->next;

        prevNode->next = nextNode;
        nextNode->previous = prevNode;

        --node_count;
        
        if (freemem)
        {
            delete _node;
            _node = NULL;
        }
        return _node;
    }

    node *linkedlist::remove_node_at_index(int index)
    {
        node *_node = get_node_at_index(index);        
        return remove_node(_node);
    }    

    node *linkedlist::get_node_at_index(int index) const
    {
        node *currentNode = head;

        for (int i = 0; currentNode != NULL && i != index; ++i)
        {
            currentNode = currentNode->next;
        }

        return currentNode != NULL ? currentNode : NULL;
    }

    int linkedlist::get_index_of_node(node *_node) const
    {
        node *currentNode = head;
        
        for (int i = 0; currentNode != NULL; ++i)
        {
            if (currentNode == _node)
            {
                return i;
            }

            currentNode = currentNode->next;
        }

        return -1;
    }
}