#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Max-Heap құру (әдепкі priority_queue)
    priority_queue<int> maxHeap;

    // Элементтерді қосу
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(15);
    maxHeap.push(20);

    // Элементтерді шығару
    cout << "Max-Heap элементтері (ең үлкен элемент бірінші): " << endl;
    while (!maxHeap.empty())
    {
        cout << maxHeap.top() << " "; // Ең үлкен элемент
        maxHeap.pop();                // Элементті шығару
    }
    cout << endl;

    return 0;
}
