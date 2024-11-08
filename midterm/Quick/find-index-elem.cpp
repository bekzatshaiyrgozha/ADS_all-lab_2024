#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int hight)
{
    int pivot = arr[hight];
    int i = low - 1;

    for (int j = low; j < hight; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[hight]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int hight)
{
    if (low < hight)
    {
        int pi = partition(arr, low, hight);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, hight);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    int need_elem;
    cin >> need_elem;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
    int index;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == need_elem)
        {
            index = i;
        }
        cout << arr[i] << " ";
    }
    cout << endl
         << index;
}