#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int x;
    cin >> x;
    
    int nearestIndex = 0;
    int minDifference = abs(arr[0] - x);
    
    for (int i = 1; i < n; i++) {
        int currentDifference = abs(arr[i] - x);
        
        if (currentDifference < minDifference) {
            minDifference = currentDifference;
            nearestIndex = i;
        }
    }
    
    cout << nearestIndex << endl;
    
}
