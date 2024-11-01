#include <iostream>
using namespace std;

int partition(int arr[], int low, int hight)
{
    int pivot = arr[hight];
    int i = low - 1;

    for (int j = low; j <= hight - 1; j++)
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

void quickSort(int arr[], int low, int hight)
{
    if (low < hight)
    {
        int pi = partition(arr, low, hight);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, hight);
    }
}

void printelem(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size = 17;
    int arr[] = {3, 2, 6, 4, 8, 6, 3, 2, 8, 67, 45, 56, 34, 56, 78, 34, 45};

    quickSort(arr, 0, size - 1);
    printelem(arr, size);
}