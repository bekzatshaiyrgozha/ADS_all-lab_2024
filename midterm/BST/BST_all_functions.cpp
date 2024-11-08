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
            return new Node(value);
        if (node->data > value)
        {
            node->left = insert(node->left, value);
        }
        else if (node->data < value)
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void print(Node *node)
    {
        if (node == nullptr)
            return;
        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }

    int MinHeap(Node *node)
    {
        if (node == nullptr){
            return nullptr;
        }

        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node->left;
    }
};

int main()
{
    BST tree;
    tree.root = tree.insert(tree.root, 10);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 23);
    tree.insert(tree.root, 12);
    tree.insert(tree.root, 34);
    tree.insert(tree.root, 45);
    tree.insert(tree.root, 26);
    tree.insert(tree.root, 78);
    tree.insert(tree.root, 45);
    tree.insert(tree.root, 65);

    tree.print(tree.root);
    tree.MinHeap(tree.root);
    tree.print(tree.root);
}