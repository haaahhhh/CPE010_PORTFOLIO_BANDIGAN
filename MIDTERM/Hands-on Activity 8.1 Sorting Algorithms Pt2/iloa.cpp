#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int size = 100;
void displayArray(int arr[]);

int main(){
    int arr[size];
    srand(time(0));
    for(int i = 0; i<size; i++){
        arr[i] = rand()%100;
    }
    displayArray(arr);

    std::cout <<"Sorted Array"<< std::endl;
    // shellSort(arr,size);
    // displayArray(arr);

    // mergeSort(arr,0, size-1);
    // displayArray(arr);

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