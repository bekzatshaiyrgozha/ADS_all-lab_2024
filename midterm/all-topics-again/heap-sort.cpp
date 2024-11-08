#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;  // сол жақ баласы
    int right = 2 * i + 2; // оң жақ баласы

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Егер largest өзгерген болса, онда элементтерді ауыстырып, heapify-ды қайтадан шақыру
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // рекурсивті түрде heapify
    }
}

void heapSort(vector<int> &arr, int n)
{
    // Алдымен үйінді құру
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Элементтерді сұрыптау
    for (int i = n - 1; i >= 1; i--)
    {
        // Үйіндінің түпкі элементін ең соңғы элементке ауыстырып, heapify-ды қайтадан қолдану
        swap(arr[0], arr[i]);
        heapify(arr, i, 0); // соңғы элементсіз heapify
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    // Пайдаланушыдан массив енгізу
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // HeapSort алгоритмін қолдану
    heapSort(arr, n);

    // Нәтижені шығару
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
