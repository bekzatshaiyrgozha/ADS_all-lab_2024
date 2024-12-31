#include <iostream>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int data;

    Node(int data){
        this->next = nullptr;
        this->prev = nullptr;
        this->data = data;

    }
    void insertAtBeginning(int data){
        Node* newNode = new node(data);
        if(head != nullptr){
            head->prev = newNode;
        }
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            return;
        }

        Node *temp = head;
        while(temp->next != nullptr){
            temp = temp -> next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void deleteNode(int data){
        if(head == nullptr){
            return;
        }
        Node *temp = head;
        if(temp->data == data){
            head = temp->next;

            if(head != nullptr){
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
    }



}

int main()
{
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);

    cout << "Тізімді көрсету: ";
    list.display();

    cout << "Кері бағытта көрсету: ";
    list.displayReverse();

    list.deleteNode(20);
    cout << "20 түйінін жойғаннан кейін: ";
    list.display();

    return 0;
}
