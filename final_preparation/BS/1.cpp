#include <iostream>
using namespace std;

// Бинарлы іздеу функциясы
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Орта индексті табамыз

        // Егер орта элемент табылса
        if (arr[mid] == target) {
            return mid; // Индексті қайтарамыз
        }
        // Егер ізделетін элемент орта элементтен кіші болса
        else if (arr[mid] > target) {
            right = mid - 1; // Сол жақ бөлікте іздейміз
        }
        // Егер ізделетін элемент орта элементтен үлкен болса
        else {
            left = mid + 1; // Оң жақ бөлікте іздейміз
        }
    }
    return -1; // Егер элемент табылмаса, -1 қайтарамыз
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};  // Сұрыпталған массив
    int size = sizeof(arr) / sizeof(arr[0]);  // Массивтің өлшемі
    int target = 70;  // Ізделетін элемент

    // Бинарлы іздеуді шақыру
    int result = binarySearch(arr, size, target);

    // Нәтижені шығару
    if (result != -1) {
        cout << "Элемент " << target << " индексінде орналасқан: " << result << endl;
    } else {
        cout << "Элемент " << target << " табылмады." << endl;
    }

    return 0;
}
