#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k; 
    cin >> n >> k; 
    vector<int> children(n);
    
    int maxChildren = 0; 

    for (int i = 0; i < n; i++) {
        cin >> children[i]; 
        maxChildren = max(maxChildren, children[i]);
    }

    int left = 1; 
    int right = maxChildren; 
    int result = maxChildren; 

    while (left <= right) {
        int mid = left + (right - left) / 2; 
        int totalFlights = 0;

        for (int i = 0; i < n; i++) {
            totalFlights += (children[i] + mid - 1) / mid; 
        }

        if (totalFlights <= k) {
            result = mid; 
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }

    cout << result << endl; 
}
