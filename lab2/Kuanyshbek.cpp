#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;

    node(int x) {
        value = x;
        next = nullptr;
    }
};

struct Linkedlist {
    private:
        node* head;
        int len;
    public:
        Linkedlist() {
            head = nullptr;
            len = 0;
        }

        void insert(int val) {
            node* Newnode = new node(val);
            if (len == 0) {
                head = Newnode;  
            } else {
                node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = Newnode;
            }
            len++;
        }

        void deleteEverySecond() {
            if (!head || !head->next) return; 

            node* current = head;
            while (current && current->next) {
                node* nodeToDelete = current->next;
                current->next = nodeToDelete->next;
                delete nodeToDelete;
                current = current->next; 
            }
        }

        void print() {
            node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << " ";  
                temp = temp->next;
            }
           
        }
};

int main() {
    int n;
    cin >> n;
    Linkedlist ll;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        ll.insert(k);
    }

    ll.deleteEverySecond(); 
    ll.print();


}
