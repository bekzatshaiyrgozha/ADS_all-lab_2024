#include <iostream>
using namespace std;

// Структура для узла двусвязного списка
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// Класс для двусвязного списка
class DoublyLinkedList {
private:
    Node* head;  // Указатель на голову списка
    Node* tail;  // Указатель на хвост списка
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Вставка в начало списка
    void insertBegin(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;  // Если список пуст, голова и хвост указывают на новый узел
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Вставка в конец списка
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;  // Если список пуст, голова и хвост указывают на новый узел
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Удаление узла с определенным значением
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "Список пуст, удаление невозможно\n";
            return;
        }

        Node* current = head;

        // Поиск узла с заданным значением
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        // Если узел не найден
        if (current == nullptr) {
            cout << "Элемент " << value << " не найден\n";
            return;
        }

        // Если удаляемый узел — голова
        if (current == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;  // Если список становится пустым
            }
        }
        // Если удаляемый узел — хвост
        else if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        // Если узел находится между головой и хвостом
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;  // Удаляем узел
    }

    // Отображение списка слева направо
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Отображение списка справа налево
    void displayBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Вставка элементов в начало и конец
    list.insertBegin(10);
    list.insertBegin(20);
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Список слева направо: ";
    list.displayForward();  // Ожидаемый вывод: 20 10 30 40

    cout << "Список справа налево: ";
    list.displayBackward();  // Ожидаемый вывод: 40 30 10 20

    // Удаление элементов
    list.deleteNode(30);
    cout << "После удаления элемента 30: ";
    list.displayForward();  // Ожидаемый вывод: 20 10 40

    list.deleteNode(20);
    cout << "После удаления элемента 20: ";
    list.displayForward();  // Ожидаемый вывод: 10 40

    return 0;
}
