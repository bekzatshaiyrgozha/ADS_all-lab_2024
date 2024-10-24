#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<int> d;
    string command;
    
    while (cin >> command) {
        if (command == "+") {
            int n;
            cin >> n;
            d.push_front(n);
        } 
        else if (command == "-") {
            int n;
            cin >> n;
            d.push_back(n); 
        } 
        else if (command == "*") {
            if (d.empty()) {
                cout << "error" << endl;
            } else if (d.size() == 1) {
                cout << d.front() * 2 << endl; 
                d.pop_front(); 
            } else {
                int sum = d.front() + d.back(); 
                cout << sum << endl;
                d.pop_front(); 
                d.pop_back();  
            }
        } 
        else if (command == "!") {
            break; 
        }
    }
}
