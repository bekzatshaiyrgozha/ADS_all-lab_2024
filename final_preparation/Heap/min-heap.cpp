#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Min-Heap құру (қосымша компаратор)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Элементтерді қосу
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(15);
    minHeap.push(20);

    // Элементтерді шығару
    cout << "Min-Heap элементтері (ең кіші элемент бірінші): " << endl;
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " "; // Ең кіші элемент
        minHeap.pop();                // Элементті шығару
    }
    cout << endl;

    return 0;
}
