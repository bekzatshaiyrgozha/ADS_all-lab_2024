#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Сол жақ баланы тексеру
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    // Оң жақ баланы тексеру
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Егер largest өзгерсе, swap жасап, рекурсиялық түрде heapify орындау
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(vector<int> &arr, int n)
{
    int size = arr.size();

    // Max Heap құру
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    // Сұрыптау
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]); // Тамыр түйінді соңына ауыстыру
        heapify(arr, i, 0);   // Қалған элементтермен жаңа Max Heap құру
    }
}

int main()
{
    int n;
    cout << "Массив өлшемін енгізіңіз: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Массив элементтерін енгізіңіз: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "Heap Sort нәтижесі: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
