#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int> &arr, int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, n);
    }
}

void buildMaxHeap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, i, n);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildMaxHeap(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
