#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    priority_queue <int> elements;

    for(int i=0;i<n;i++){
        int number; cin >> number;
        elements.push(number);
    }

    while(elements.size()>1){
        int first = elements.top();
        elements.pop();
        int second = elements.top();
        elements.pop();
        if(first - second > 0){
            elements.push(first - second);
        }
    }
    if(elements.empty()){
        cout << 0;
    }else{
        cout << elements.top();
    }
    
}
