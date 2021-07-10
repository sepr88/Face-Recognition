#ifndef FACE_RECOGNITION_BINARY_TREE_H
#define FACE_RECOGNITION_BINARY_TREE_H
#include <iostream>
#include <string>

template <class T>
class binary_tree{
    struct node{
        T value;
        node *left, *right, *parent;

        node():left(nullptr), right(nullptr), parent(nullptr){}
        node(const T& value):value(value), left(nullptr), right(nullptr), parent(nullptr){}
        ~node(){delete left; delete right;}

    };

    node *_root;

    void print(const std::string &prefix, const node *node, bool is_left)
    {
        if(node)
        {
            std::cout << prefix;
            std::cout << (is_left ? "|---" : "'---");

            std::cout << node->value << std::endl;

            print( prefix + (is_left ? "|   " : "    "), node->left, true);
            print( prefix + (is_left ? "|   " : "    "), node->right, false);
        }
    }

    void print(const node *node){print("",node,false);}

    node* find(const T &value) {

        node *node = _root;

        while (node)
        {
            if (node->value == value)
            {
                return node;
            }
            else
            {
                if (value < node->value)
                {
                    if (node->left)
                    {
                        node = node->left;
                    }
                    else
                    {
                        return nullptr;
                    }
                }
                else
                {
                    if (node->right)
                    {
                        node = node->right;
                    }
                    else
                    {
                        return nullptr;
                    }
                }
            }
        }
    }

public:
    binary_tree():_root(nullptr){}
    ~binary_tree(){delete _root;}

    void clear(){delete _root; _root= nullptr;}

    void insert(const T &value)
    {
        if(!_root)
        {
            _root = new node(value);
        }
        else
        {
            node *n = _root;

            while(n)
            {
                if(value < n->value) // go left
                {
                    if(n->left)
                    {
                        n=n->left;
                    }
                    else
                    {
                        node *nn = new node(value);
                        nn->parent=n;
                        n->left = nn;
                    }

                }
                else if(value > n->value) // go right
                {
                    if(n->right)
                    {
                        n=n->right;
                    }
                    else
                    {
                        n->right=new node(value);
                    }
                }
                else // value exists
                {
                    return;
                }
            }
        }
    }

    void print(){print(_root);}

    bool contains(const T &value)
    {
        return find(value);
    }

};


#endif //FACE_RECOGNITION_BINARY_TREE_H
