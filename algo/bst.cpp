#include "bst.hpp"

namespace randydsa
{
    bst::bst()
    {
        root = __null;
    }

    bst::~bst()
    {
        destroy_tree(root);
    }

    void bst::destroy_tree(bstnode *&tree)
    {
        if (tree != __null)
        {
            destroy_tree(tree->left);
            destroy_tree(tree->right);
            delete tree;
        }
    }

    bool bst::is_empty() const
    {
        return root == __null;        
    }

    void bst::try_find(char &c, bool &found) const
    {
        find_in_tree(root, c, found);
    }

    void bst::find_in_tree(bstnode *tree, char &c, bool &found) const
    {
        if (tree == __null)
        {
            found = false;
        }
        else if (c < tree->c)
        {
            find_in_tree(tree->left, c, found);
        }
        else if (c > tree->c)
        {
            find_in_tree(tree->right, c, found);
        }
        else
        {
            found = true;
        }
    }

    void bst::insert(char c)
    {
        insert_into_tree(root, c);
    }

    void bst::insert_into_tree(bstnode *&tree, char c)
    {
        if (tree == __null)
        {
            tree = new bstnode;
            tree->right = __null;
            tree->left = __null;
            tree->c = c;
        }
        else if (c < tree->c)
        {
            insert_into_tree(tree->left, c);
        }
        else
        {
            insert_into_tree(tree->right, c);
        }
    }

    void bst::remove(char c)
    {
        remove_from_tree(root, c);
    }

    void bst::remove_from_tree(bstnode *&tree, char c)
    {
        
    }
}