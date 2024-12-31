#include <iostream>
using namespace std;

// Массивті біріктіру функциясы
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Бірінші бөліктің өлшемі
    int n2 = right - mid;    // Екінші бөліктің өлшемі

    // Уақытша массивтер
    int leftArray[n1], rightArray[n2];

    // Берілген массивті уақытша массивтерге көшіру
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0, j = 0; // Сол жақ және оң жақ массив индекстері
    int k = left;     // Негізгі массив индексі

    // Екі уақытша массивті біріктіру
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Қалған элементтерді қосу
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Merge Sort функциясы
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Массивті екіге бөлу
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Екі бөлікті біріктіру
        merge(arr, left, mid, right);
    }
}

void merge(int arr,int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int arr1[n1],arr2[n2];

    for(int i =0;i<n1;i++){
        arr1[i] = arr[left + i];
    }
    for(int i =0;i<n2;i++){
        arr2[i] = arr[i + mid + 1];
    }
    int i =0,j =0,k = left;

    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            i++;
        }else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < n1 ){
        arr[k] = arr1[i];
        i++;
        k++; 

    }
    while(j < n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int left,int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid + 1,right);
        merge(arr,left,mid,right);
    }
}




void merge(int arr[],int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int arr1[n1],arr2[n2];

    for(int i =0;i<n1;i++){
        arr1[i] = arr[i + left];
    }
    for(int i =0;i<n2;i++){
        arr2[i] = arr[mid + 1 + i];

    }

    int i =0,j =0,k = left;

    while(i < n1 && j <n2){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        }else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int left,int right){
    if(left < right){
        int mid = left + (right - left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}