#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int larges = i;

    if (left < n && arr[left] > arr[larges])
    {
        larges = left;
    }
    if (right < n && arr[right] > arr[larges])
    {
        larges = right;
    }

    if (larges != i)
    {
        swap(arr[larges], arr[i]);
        heapify(arr, larges, n);
    }
}

void heapSort(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
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
    cout << endl;
    cout << "Max and min elem:" << arr[n - 1] << " " << arr[0];
    cout << endl;
    if (n % 2 == 0)
    {
        double avg = (arr[n / 2 - 1] + arr[n / 2]) / 2;
        cout << "Average:" << avg;
    }
    else if (n % 2 == 1)
    {
        int avg = (arr[n / 2]);
        cout << "Average:" << avg;
    }
}