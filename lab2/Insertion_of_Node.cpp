#include <iostream>
using namespace std;

struct node {
    int val;  
    node* next;  

    node(int x) {  
        val = x;
        next = nullptr;
    }
};

struct ins {
    private:
        node* head;  
        int len;   

    public:
        ins() {  
            head = nullptr;
            len = 0;
        }

        void insert(int value) {
            node* newNode = new node(value);  
            if (len == 0) {
                head = newNode;  
            } else {
                node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;  
                }
                temp->next = newNode; 
            }
            len++;
        }

        void insert_at_position(int value, int position) {
            node* newNode = new node(value);
            if (position == 0) {
                newNode->next = head;
                head = newNode;
            } else {
                node* temp = head;
                for (int i = 0; i < position - 1 && temp != nullptr; i++) {
                    temp = temp->next;  
                }
                if (temp != nullptr) {
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
            }
            len++;
        }

      
        void print() {
            node* temp = head;
            while (temp != nullptr) {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    int n; cin >> n;
    ins list;  

   
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        list.insert(k); 
    }

    int valueToInsert, position; cin >> valueToInsert >> position; 

    list.insert_at_position(valueToInsert, position);  

    list.print();  

}
