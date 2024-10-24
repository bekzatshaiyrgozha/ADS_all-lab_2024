#include <iostream>
#include <vector>
using namespace std;

int values(vector<int> myvector){
    int right = myvector.size()-1;
    int left = 0;
    while(left<=right){
        int mid = left + (right-left)/2;
        if (myvector[mid] < myvector[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }


}

int main(){
    vector<int> myvector;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int k; cin >> k;
        myvector.push_back(k);
    }

    int output = values(myvector);
    cout << output;

}