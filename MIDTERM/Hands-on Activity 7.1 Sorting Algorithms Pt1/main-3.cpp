#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int size = 100;

void displayArray(int arr[]);
int main(){
    //create an array with unsorted list with 100 maximum size
    int arr[size];
    // use time (0) as seed for random values
    srand(time(0));
    //populate the array
    for(int i = 0; i<size; i++){
        arr[i] = rand()%100;
    }
    //display the random generated array
    std::cout << "unsorted array" << std::endl;
    displayArray(arr);
    
    // std::cout << "bubble sort" << std::endl;
    // bubbleSort(arr, size);
    // displayArray(arr);

    // std::cout << "selection sort" << std::endl;
    // selectionSort(arr,size);
    // displayArray(arr);

    // std::cout << "insertion sort" << std::endl;
    // insertionSort(arr, size);
    // displayArray(arr);

    return 0;
}

void displayArray(int arr[]){
    for(int i = 0; i<size; i++){
        std::cout << arr[i] <<" ";
    }
    std::cout << std::endl;
}