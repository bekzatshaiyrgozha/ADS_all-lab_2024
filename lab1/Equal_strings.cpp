#include <iostream>
#include <string>
using namespace std;

int main() {
    string soz1, soz2;
    
    cin >> soz1 >> soz2;
    
    
    string result1;
    for (char ch : soz1) {
        if (ch == '#' && !result1.empty()) {
            result1.pop_back();  
        } else if (ch != '#') {
            result1.push_back(ch); 
        }
    }
    
    string result2;
    for (char ch : soz2) {
        if (ch == '#' && !result2.empty()) {
            result2.pop_back();  
        } else if (ch != '#') {
            result2.push_back(ch); 
        }
    }
    

    if (result1 == result2) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    
}
