#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Min-heap (default priority queue in C++)
    priority_queue<int, vector<int>, greater<int>> pq;

    // Элементтерді қосу
    pq.push(10);
    pq.push(5);
    pq.push(15);
    pq.push(20);

    // Элементтерді шығару
    cout << "Priority Queue элементтері (ең кіші элемент бірінші): " << endl;
    while (!pq.empty()) {
        cout << pq.top() << " "; // Ең кіші элемент
        pq.pop(); // Элементті шығару
    }
    cout << endl;
}
