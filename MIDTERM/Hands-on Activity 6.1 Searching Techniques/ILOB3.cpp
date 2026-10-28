#include <iostream>
#include "B3searchingAlgo.h"

const int maxSize = 10;
int main(){
    int arr[maxSize] = {3,5,6,8,11,12,14,15,17,18};

    binarySearchArr(arr,maxSize,8);
    
    return 0;
}