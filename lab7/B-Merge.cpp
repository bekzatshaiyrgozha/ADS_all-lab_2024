#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[i + left];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (n1 > i && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main()
{
    int n1;
    cin >> n1;
    vector<int> arr;
    for (int i = 0; i < n1; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }
    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        int s;
        cin >> s;
        arr.push_back(s);
    }

    mergeSort(arr, 0, n1 + n2 - 1);

    for (int i = 0; i < n1 + n2; i++)
    {
        cout << arr[i] << " ";
    }
}