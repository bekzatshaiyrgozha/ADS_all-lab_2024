#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int larges = i;

    if (arr[left] > arr[larges] && left < n)
    {
        larges = left;
    }
    if (arr[right] > arr[larges] && right < n)
    {
        larges = right;
    }

    if (larges != i)
    {
        swap(arr[i], arr[larges]);
        heapify(arr, n, larges);
    }
}

void heapSort(vector<int> &arr, int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}