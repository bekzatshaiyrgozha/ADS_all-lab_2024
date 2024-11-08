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

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    if (n % 2 == 0)
    {
        cout << (arr[(n / 2)] + arr[(n / 2 - 1)]) / 2;
    }
    else
    {
        cout << arr[n / 2];
    }
}