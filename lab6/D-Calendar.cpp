#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool comparator(string &s, string &t) {
    int years = stoi(s.substr(6, 4));
    int yeart = stoi(t.substr(6, 4));
    int months = stoi(s.substr(3, 2));
    int montht = stoi(t.substr(3, 2));
    int days = stoi(s.substr(0, 2));
    int dayt = stoi(t.substr(0, 2));
    if (years < yeart) return true;
    if (years == yeart && months < montht) return true;
    if (years == yeart && months == montht && days < dayt) return true;
    return false;
}

int partition(vector<string> &arr, int low, int high) {
    string pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (comparator(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<string> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printElements(vector<string> &arr) {
    for (auto &date : arr) {
        cout << date << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    printElements(arr);
    return 0;
}
