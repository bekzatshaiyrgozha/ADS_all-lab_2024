#include <iostream>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
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

    bool saerch(Node *node, int value)
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
            return saerch(node->left, value);
        }
        else
        {
            return saerch(node->right, value);
        }
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main()
{
    BST tree;

    tree.root = tree.insert(tree.root, 10);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 34);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 45);
    tree.insert(tree.root, 34);
    tree.insert(tree.root, 34);
    tree.insert(tree.root, 50);

    tree.inorder(tree.root);
    cout << endl;

    int searchElement = 100;
    if (tree.saerch(tree.root, searchElement))
    {
        cout << searchElement << " have";
    }
    else
    {
        cout << "Not find";
    }
}