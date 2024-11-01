#include <iostream>
#include <vector>
using namespace std;

void heapSort(vector<int> &arr, int n)
{
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
}