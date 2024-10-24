#include <iostream> 
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std; 

int main(){
    ll n , k; cin >> n >> k;
    vector <ll > myvector(n);
    for(int i=0;i<n;i++){
        cin >> myvector[i];
    }
    sort(myvector.begin(), myvector.end());
    reverse(myvector.begin(), myvector.end());
    ll max = myvector[0];
    myvector[0]+=k;
    ll sum=0;
    ll quadradic = 0;
    for(int i=0;i<n;i++){
        sum+=myvector[i];
        quadradic+=myvector[i]*myvector[i];
    }
    ll result = (sum*sum-quadradic)/2;
    cout << result;


    
}