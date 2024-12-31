#include <iostream>
using namespace std;

// Массивті біріктіру функциясы
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Бірінші бөліктің өлшемі
    int n2 = right - mid;    // Екінші бөліктің өлшемі

    // Уақытша массивтер
    int leftArray[n1], rightArray[n2];

    // Берілген массивті уақытша массивтерге көшіру
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0, j = 0; // Сол жақ және оң жақ массив индекстері
    int k = left;     // Негізгі массив индексі

    // Екі уақытша массивті біріктіру
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Қалған элементтерді қосу
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Merge Sort функциясы
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Массивті екіге бөлу
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Екі бөлікті біріктіру
        merge(arr, left, mid, right);
    }
}

// Массивті шығару функциясы
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Берілген массив: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Сұрыпталған массив: ";
    printArray(arr, n);

    return 0;
}
