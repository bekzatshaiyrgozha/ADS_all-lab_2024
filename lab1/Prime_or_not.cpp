#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=1){
        cout<<"NO";
       return 0;
    }
    bool isprime=true;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            isprime=false;
            break;
        }
        
    }
    if(isprime){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    
}