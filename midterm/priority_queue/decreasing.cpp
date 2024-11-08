#include <iostream>
#include <queue>

using namespace std;

int main()
{

    priority_queue<int> minHeap;
    minHeap.push(20);
    minHeap.push(0);
    minHeap.push(23);
    minHeap.push(78);
    minHeap.push(3);

    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}
