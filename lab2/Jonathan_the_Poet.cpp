#include <iostream>
#include <string>

using namespace std;

struct node {
    string val;
    node* next;
    node* prev;

    node(string x) {
        val = x;
        next = prev = nullptr;
    }
};

struct dll {
    private:
        node* head;
        node* tail;
        int len;

    public:
        dll() {
            head = tail = nullptr;
            len = 0;
        }

        void insert(string value) {
            node* newNode = new node(value);
            if (len == 0) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            len++;
        }

        void cyclic_left(int k) {
            if (len == 0 || k % len == 0) return;

            k = k % len;  
            node* newTail = head;
            for (int i = 0; i < k - 1; i++) {
                newTail = newTail->next;
            }

            node* newHead = newTail->next;

            newHead->prev = nullptr;
            tail->next = head;
            head->prev = tail;
            newTail->next = nullptr;
            tail = newTail;
            head = newHead;
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
    int n, k;
    cin >> n >> k;

    dll poem;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        poem.insert(word);
    }

    poem.cyclic_left(k);

    poem.print();

}
