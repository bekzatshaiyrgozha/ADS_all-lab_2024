#include <iostream>
using namespace std;

struct Node
{
    Node *right;
    Node *left;
    int data;

    Node(int value)
    {
        right = left = nullptr;
        data = value;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = nullptr;
    }

    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool searchElem(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == value)
        {
            return true;
        }
        else if (value < node->data)
        {
            return (node->left, value);
        }
        else
        {
            return (node->right, value);
        }
    }

    void print(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }
};

int main()
{
    BST tree;

    tree.root = tree.insert(tree.root, 20);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 23);
    tree.insert(tree.root, 12);
    tree.insert(tree.root, 34);
    tree.insert(tree.root, 45);
    tree.insert(tree.root, 26);
    tree.insert(tree.root, 78);
    tree.insert(tree.root, 45);
    tree.insert(tree.root, 65);

    tree.searchElem(tree.root, 12);

    tree.print(tree.root);
    cout << endl;

    if (tree.searchElem(tree.root, 12))
    {
        cout << 12 << " have";
    }
    else
    {
        cout << "Not find";
    }
}