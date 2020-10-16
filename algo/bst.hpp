#ifndef BST_HPP
#define BST_HPP

#include "bst/bstnode.hpp"

namespace randydsa
{
    class bst
    {
    private:
        bstnode *root;
        void destroy_tree(bstnode *&);
        void insert_into_tree(bstnode *&, char);
        void remove_from_tree(bstnode *&, char);
        void find_in_tree(bstnode *, char &, bool &) const;

    public:
        bst();
        ~bst();
        bool is_empty() const;        
        void try_find(char &, bool &) const;
        int node_count() const;
        void insert(char);
        void remove(char);
    };
}

#endif