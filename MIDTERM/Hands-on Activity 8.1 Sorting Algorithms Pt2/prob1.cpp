#include <iostream>
#include <cstdlib>
#include <ctime>

const int size = 50;
void displayArray(int arr[]);
int partition(int arr[], int low , int high);
void quickSort(int arr[], int low , int high);
void insertionSort(int arr[], int high, int low);

int main(){
    int arr[size];
    srand(time(0));
    for(int i = 0; i<size; i++){
        arr[i] = rand()%100;
    }
    displayArray(arr);

    std::cout << "Modified Quick Sort:" << std::endl;
    quickSort(arr,0, size-1);
    displayArray(arr);

    return 0;
}
void displayArray(int arr[]){
    for(int i = 0; i<size; i++){
        std::cout << arr[i] <<" ";
    }
    std::cout << std::endl;
}
int partition(int arr[], int low , int high){
    int pivot = arr[high];
    int i = low -1;
    for(int j = low; j<high; j++){
        if(arr[j]<= pivot){
            i++;
            std::swap(arr[i],arr[j]);
        }
    }
    std::swap(arr[i+1],arr[high]);
    return i +1;
}
void insertionSort(int arr[], int high, int low){
    int K = low +1, J;
    int temp;

    while(K<=high){
        temp = arr[K];
        J =K-1;

        while(temp <= arr[J] && J>=low){
            arr[J+1] = arr[J];
            J--;
        }
        arr[J+1] = temp;
        K++;
    }
}
void quickSort(int arr[], int low , int high){
    if(low < high){
        int pi = partition(arr,low,high);
        insertionSort(arr,pi-1,low);
        insertionSort(arr,high,pi+1);
    }
}
