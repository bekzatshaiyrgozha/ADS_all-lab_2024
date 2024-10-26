#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<pair<int, vector<int>>> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<int, vector<int>>> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i].first > rightArr[j].first ||
            (leftArr[i].first == rightArr[j].first && leftArr[i].second < rightArr[j].second))
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

void mergeSort(vector<pair<int, vector<int>>> &arr)
{
    int n = arr.size();
    for (int size = 1; size < n; size *= 2)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);
            if (mid < right)
            {
                merge(arr, left, mid, right);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, vector<int>>> rows(n);

    for (int i = 0; i < n; i++)
    {
        vector<int> row(m);
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> row[j];
            sum += row[j];
        }
        rows[i] = {sum, row};
    }

    mergeSort(rows);

    for (int i = 0; i < rows.size(); i++)
    {
        for (int j = 0; j < rows[i].second.size(); j++)
        {
            cout << rows[i].second[j] << " ";
        }
        cout << endl;
    }
}
