#include <cstddef>
#include <utility>
#include <iostream>
#ifndef SORTINGALGO_H
#define SORTINGALGO_H

template <typename T>
void bubbleSort(T arr[], size_t arrSize){
    //step 1L for i = 0 to N-1 repeat inner loop
    for(int i = 0; i <arrSize; i++){
        //step 2 inner loop that foe K = i+1 to N-i repeat
        for(int j = i+1; j < arrSize; j++){
            //step 3: swap if the arr[j] > arr[i]
            if(arr[i] > arr[j]){
                std::swap(arr[i],arr[j]);
            }
        }
    }
}

template <typename T>
//array, current position, size of array
int routineSmallest(T arr[],int K, const int arrSize){
    int position;
    T smallestElem = arr[K];

    for(int j = K+1; j <arrSize; j++){
        if(arr[j] < smallestElem){
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], size_t arrSize){
    int POS, temp, pass;
    for(int i = 0; i < arrSize; i++){
        POS = routineSmallest(arr, i, arrSize);
        //swapping: 
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
        //verification and counting the number of passes that was done;
        pass++;
    }
}

template <typename T>
void insertionSort(T arr[], size_t arrSize){
    int K = 1, J;
    T temp;

    while(K<arrSize){
        temp = arr[K];
        J =K-1;

        while(temp <= arr[J] && J>=0){
            arr[J+1] = arr[J];
            J--;
        }
        arr[J+1] = temp;
        K++;
    }
}

template <typename T>
void shellSort(T arr[],size_t size){
    int gap = size/2;
    T temp;
    while(gap > 0){
        int i  = gap;
        while(i < size){
            int temp = arr[i];
            int j = i;
            while(j>= gap && arr[j -gap] > temp){
                arr[j] = arr[j - gap];
                j-= gap;
            }
            arr[j] = temp;
            i++; 
        }
        gap /= 2;
    }
}

template <typename T>
void merge(T arr[], int left , int mid, int right){
    int n1 = mid - left +1;
    int n2 = right - mid;
    T L[100];
    T R[100];

    for(int i = 0; i <n1; i++){
        L[i] = arr[left + i];
    }
    for(int j = 0;j<n2;j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while(i<n1&& j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(T arr[], int left, int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr,left,mid);
    mergeSort(arr, mid + 1, right);
    merge(arr,left,mid,right); 
}

template <typename T>
int partition(T arr[], int low , int high){
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

template <typename T>
void quickSort(T arr[], int low , int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
#endif