#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr1[i];
    }

    vector<int> arr2(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> arr2[i];
    }

    quickSort(arr1, 0, n - 1);
    quickSort(arr2, 0, m - 1);

    vector<int> common;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            common.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    for (int r = 0; r < common.size(); r++)
    {
        cout << common[r] << " ";
    }
}
