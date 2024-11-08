#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int hight)
{
    int i = low - 1;
    int pivot = arr[hight];

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

vector<int> deleteDuplicates(vector<int> &arr, int n)
{
    vector<int> arr2;
    arr2.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr2.push_back(arr[i]);
        }
    }
    return arr2;
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

    cout << endl;

    vector<int> arr2 = deleteDuplicates(arr, n);

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
}