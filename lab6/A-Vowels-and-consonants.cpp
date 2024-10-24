//letters sort
#include <iostream>
#include <string>
using namespace std;

int partition(char arr[],int low,int hight){
    char pivot = arr[hight];
    int i = low - 1;

    for(int j=low;j<=hight-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[hight]);
    return i+1;
}

void quickSort(char arr[],int low,int hight){
    if(low<hight){
        int pi = partition(arr,low,hight);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,hight);
    }
    
    

}
void printElements(char arr[],int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
            cout << arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] != 'a' && arr[i] != 'e' && arr[i] != 'i' && arr[i] != 'o' && arr[i] != 'u'){
            cout << arr[i];
        }
    }
}

int main(){
    int n; cin >> n;
    char arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    quickSort(arr,0,n-1);

    printElements(arr,n);
}