#include <iostream>
#include <vector>

using namespace std;

void minHeap(vector<int> &arr, int n, int i)
{
    int larges = i;
    int right = 2 * i + 1;
    int left = 2 * i + 2;

    if (arr[left] < arr[larges] && left < n)
    {
        larges = left;
    }
    if (arr[right] < arr[larges] && right < n)
    {
        larges = right;
    }

    if (larges != i)
    {
        swap(arr[i], arr[larges]);
        minHeap(arr, n, larges);
    }
}

void buildMinHeap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeap(arr, n, i);
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

    buildMinHeap(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}