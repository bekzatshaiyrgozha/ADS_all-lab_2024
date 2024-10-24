#include <iostream>
#include <cmath>
using namespace std;

struct node {
    int val;
    node* next;

    node(int x) {
        val = x;
        next = nullptr;
    }
};

struct LinkedList {
    private:
        node* head;  
        int len;   

    public:
        LinkedList() {
            head = nullptr;
            len = 0;
        }

        void insert(int x) {
            node* newNode = new node(x);
            if (head == nullptr) {
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

        int find_nearest(int x) {
            if (head == nullptr) return -1;  

            int nearestIndex = 0;
            int minDifference = abs(head->val - x);

            node* current = head;
            int index = 0;

            while (current != nullptr) {
                int currentDifference = abs(current->val - x);

                if (currentDifference < minDifference) {
                    minDifference = currentDifference;
                    nearestIndex = index;
                }

                current = current->next;
                index++;
            }

            return nearestIndex;
        }

        void printList() {
            node* current = head;
            while (current != nullptr) {
                cout << current->val << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main() {
    int n;
    cin >> n;
    
    LinkedList ll;  
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        ll.insert(value);
    }
    
    int x; cin >> x;
    
    int nearestIndex = ll.find_nearest(x);
    
    cout << nearestIndex;
}
