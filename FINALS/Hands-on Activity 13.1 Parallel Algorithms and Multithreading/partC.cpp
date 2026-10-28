#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int size = 100;

int main(){
    int arr[size];
    int arr2[size];

    srand(time(0));
    for(int i = 0; i < size; i++){
    arr[i] = rand()%100;
    arr2[i] = arr[i];
    }

    std::thread th1(shellSort<int>,arr,size);
    std::thread th2(quickSort<int>,arr2,0,size-1);   

    th1.join();
    th2.join();

    std::cout << "Shell Sort:"<<std::endl;
    for(int i = 0; i<size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Quick Sort:"<<std::endl;
    for(int i = 0; i<size; i++){
        std::cout << arr2[i]<< " ";
    }

    return 0;
}