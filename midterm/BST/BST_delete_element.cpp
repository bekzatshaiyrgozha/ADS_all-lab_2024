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
    Node *find_Min(Node *node)
    {
        while (node && node != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    Node *deleteNode(Node *node, int delete_elem)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (delete_elem < node->data)
        {
            node->left = deleteNode(node->left, delete_elem);
        }
        else if (delete_elem > node->data)
        {
            node->right = deleteNode(node->right, delete_elem);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = find_Min(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, delete_elem);
        }
        return node;
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
    tree.insert(tree.root, 28);
    tree.insert(tree.root, 22);
    tree.insert(tree.root, 50);

    tree.inorder(tree.root);
    cout << endl;

    int delete_elem = 45;

    tree.root = tree.deleteNode(tree.root, delete_elem);

    tree.inorder(tree.root);
}