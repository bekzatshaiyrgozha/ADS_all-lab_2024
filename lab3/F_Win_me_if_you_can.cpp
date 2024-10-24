#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric> 

using namespace std;

int binarySearch(const vector<int>& competitors, int markPower) {
    int left = 0;
    int right = competitors.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2; 
        if (competitors[mid] <= markPower) {
            left = mid + 1; 
        } else {
            right = mid; 
        }
    }
    
    return left; 
}

int main() {
    int n; cin >> n; 
    vector<int> competitors(n); 
    
    for(int i = 0; i < n; i++) {
        cin >> competitors[i];
    }
    
    sort(competitors.begin(), competitors.end()); 
    
    int rounds;cin >> rounds; 
    
    while (rounds--) {
        int markPower; cin >> markPower; 
        
        int count = binarySearch(competitors, markPower);
        
        int sum = accumulate(competitors.begin(), competitors.begin() + count, 0);
        
        cout << count << " " << sum << endl;
    }
    
}
