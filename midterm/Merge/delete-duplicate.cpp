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
        arrright[i] = arr[mid + 1 + i];
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
    cout << endl;

    vector<int> arr2 = deleteDuplicates(arr, n);

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
}