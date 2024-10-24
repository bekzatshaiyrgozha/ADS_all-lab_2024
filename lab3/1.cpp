#include <iostream>
using namespace std;

struct node {
    node* next;
    int data;

    node(int value) {
        next = nullptr;
        data = value;
    }
};

class LinkedList {
private:
    node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertBegin(int value) {
        node* newNode = new node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertLast(int value) {
        node* newNode = new node(value);
        // Если список пуст
        if (head == nullptr) {
            head = newNode;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) { 
            temp = temp->next;
        }
        temp->next = newNode; 
    }
    void reverse(){
        node* prev = nullptr;
        node* current = head;
        node* next = nullptr;

        while (current!=nullptr)
        {
            next = current->next;

        }
    }
    void addValuePos(int value,int pos){
        if(pos<=0){
            cout<<"error:";
            return;
        }
        if(pos == 0){
            insertBegin(value);
            return;
        }
        node* newNode = new node(value);
        node* temp = head;


    }

    void deletevalue(int value){
        if(head == nullptr){
            cout<<"errror:";
            return;
        }
        if(head->data ==value){
            node* temp = head;
            head = head->next;
            delete temp ;
            return;

        }
        node* current = head;
        while(current->next != nullptr && current->next->data==value){
            current = current->next;
        }
        if(current == nullptr){
            cout<<"not";
            return;
        }
        node* temp = current->next;
        current->next= temp->next;
        delete temp;



    }
    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertBegin(1);
    list.insertLast(2);
    list.insertLast(3);
    list.addValuePos(3,4);
    list.deletevalue(2);
    
    list.display();  // Ожидаемый вывод: 1 2 3

    return 0;
}
