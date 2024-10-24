#include <iostream>
#include <string>
#include <vector>
using namespace std;

int partition(vector<char>& myvector, int low, int high) {
    char pivot = myvector[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (myvector[j] < pivot) {
            i++;
            swap(myvector[i], myvector[j]);
        }
    }
    swap(myvector[i + 1], myvector[high]);
    return i + 1;
}

void quickSort(vector<char>& myvector, int low, int high) {
    if (low < high) {
        int pi = partition(myvector, low, high);
        quickSort(myvector, low, pi - 1);
        quickSort(myvector, pi + 1, high);
    }
}

void printElements(const vector<char>& myvector) {
    for (int i=0;i<myvector.size();i++) {
        cout << myvector[i] ;
    }
}

int main() {
    string n;
    cin >> n;
    int size = n.size();

    vector<char> myvector(size);

    for (int i = 0; i < size; i++) {
        myvector[i] = n[i];  
    }

    quickSort(myvector, 0, size - 1);

    printElements(myvector);
}
