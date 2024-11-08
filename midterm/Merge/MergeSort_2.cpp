#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> arr1(n1), arr2(n2);
    for (int i = 0; i < n1; i++)
    {
        arr1.push_back(arr[i] + i);
    }
    for (int i = 0; i < n2; i++)
    {
        arr2.push_back(mid + 1 + i);
    }

    int i = 0, j = 0, k = left;
    while (n1 > i && n2 > j)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (n1 > i)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (n2 > j)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}