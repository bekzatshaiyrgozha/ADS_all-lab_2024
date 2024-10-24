#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main(){

    int n,k; cin >> n >> k;

    priority_queue <int> freeSeets;

    long long counter = 0;

    for(int i=0;i<n;i++){
        int number; cin >> number;
        freeSeets.push(number);
    }

    for(int i=0;i<k;i++){
        counter+=freeSeets.top();
        int san = freeSeets.top();
        san=san - 1;
        freeSeets.pop();
        freeSeets.push(san);
    }

    cout<<counter;
    




}