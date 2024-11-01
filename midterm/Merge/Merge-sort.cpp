#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> arrleft(n1), arrright(n2);

    for (int i = 0; i < n1; i++)
    {
        arrleft[i] = arr[i + left];
    }
    for (int i = 0; i < n2; i++)
    {
        arrright[i] = arr[i + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while (n1 > i && n2 > j)
    {
        if (arrleft[i] < arrright[j])
        {
            arr[k] = arrleft[i];
            i++;
        }
        else
        {
            arr[k] = arrright[j];
            j++;
        }
        k++;
    }
    while (n1 > i)
    {
        arr[k] = arrleft[i];
        i++;
        k++;
    }
    while (n2 > j)
    {
        arr[k] = arrright[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printelem(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
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
    mergesort(arr, 0, arr.size() - 1);

    printelem(arr);
}