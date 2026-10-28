#include <iostream>
#include "B4searchingAlgo.h"

const int maxSize = 10;

int main(){
    int arr[maxSize] = {3,5,6,8,11,12,14,15,17,18};

    binarySearchArr(arr,maxSize -1, 0,8);

    return 0;
}