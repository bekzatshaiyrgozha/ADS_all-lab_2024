#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string soz;
    cin>>soz;
    stack <char> str;
    for(int i=0;i<soz.size();i++){
        if(!str.empty() && str.top()==soz[i]){
            str.pop();
        }else{
            str.push(soz[i]);
        }
    }
    if(str.empty()){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    
}
