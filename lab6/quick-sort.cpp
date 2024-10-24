#include <iostream>
using namespace std;

int partition(int arr[],int low,int hight){
    int pivot = arr[hight];
    int i = low - 1;

    for(int j = low;j<=hight-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[hight]);
    return i+1;
}

void quickSort(int arr[],int low,int hight){
    if(low<hight){
        int pi = partition(arr,low,hight);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,hight);
    }
    
}

void printElements(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i] << " ";
    }
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    quickSort(arr,0,n-1);

    printElements(arr,n);
}