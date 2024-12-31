#include <iostream>

using namespace std;

struct Node
{
    Node *next;
    int data;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void deleteNode(int key)
    {
        Node *temp = head;
        Node *prev = nullptr;
        if (temp != nullptr && temp->data == key)
        {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList list;

    list.insertAtBeginning(5);
    list.insertAtEnd(6);
    list.display();
}