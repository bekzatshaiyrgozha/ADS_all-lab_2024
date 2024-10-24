#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    string votes;
    cin >> votes;

    queue<int> sakayanagi, katsuragi;

    for (int i = 0; i < n; i++) {
        if (votes[i] == 'S')
            sakayanagi.push(i);
        else
            katsuragi.push(i);
    }

    while (!sakayanagi.empty() && !katsuragi.empty()) {
        int s = sakayanagi.front();
        int k = katsuragi.front();
        sakayanagi.pop();
        katsuragi.pop();

        if (s < k) {
            sakayanagi.push(s + n); 
        } else {
            katsuragi.push(k + n); 
        }
    }

    if (!sakayanagi.empty()) {
        cout << "SAKAYANAGI" << endl;
    } else {
        cout << "KATSURAGI" << endl;
    }

    return 0;
}
