#include <iostream>
using namespace std;

// Екі элементті орнын ауыстыру функциясы
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Үйінді реттеу функциясы (heapify)
void heapify(int arr[], int n, int i) {
    int largest = i; // Жоғары мәнді индекс
    int left = 2 * i + 1; // Сол жақ баланың индексі
    int right = 2 * i + 2; // Оң жақ баланың индексі

    // Сол жақ баланың мәні үлкен болса
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Оң жақ баланың мәні үлкен болса
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Егер ең үлкен элемент түйіннен емес болса, орнын ауыстыру
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Реттеуді жалғастыру
        heapify(arr, n, largest);
    }
}

// Heap Sort функциясы
void heapSort(int arr[], int n) {
    // Үйіндіні қалыптастыру
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Элементтерді шығару
    for (int i = n - 1; i >= 0; i--) {
        // Үйіндінің түбірін (ең үлкен элементті) шығару
        swap(arr[0], arr[i]);

        // Қалған үйіндіні реттеу
        heapify(arr, i, 0);
    }
}

// Массивті шығару
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Берілген массив: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Реттелген массив: ";
    printArray(arr, n);

    return 0;
}
