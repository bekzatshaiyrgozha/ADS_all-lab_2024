#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long sum = 0; 

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;

        if (command == "insert") {
            int cookies;
            cin >> cookies;

            if (minHeap.size() < k) {
                minHeap.push(cookies);
                sum += cookies;
            } else if (cookies > minHeap.top()) {
                sum -= minHeap.top(); 
                minHeap.pop();
                minHeap.push(cookies);
                sum += cookies;
            }
        } else if (command == "print") {
            cout << sum << endl;
        }
    }

}
