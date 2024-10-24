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
    public:
        Linkedlist() {
            head = nullptr;
        }

        void insert(int val) {
            node* Newnode = new node(val);
            Newnode->next = head;
            head = Newnode;
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
    ll.print();


}

