#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
#include "sortingAlgo.h"

const int size = 10000;

int main(){
  int arr[size];
  int arr2[size];
  srand(time(0));
  for(int i = 1; i < size; i++){
    arr[i] = i;
  }
  for(int i = 1; i < size; i++){
    arr2[i] =i;
  }

  std::reverse(std::begin(arr), std::end(arr));
  std::reverse(std::begin(arr2), std::end(arr2));

  std::thread th1(bubbleSort<int>,arr,size); 
  std::thread th2(insertionSort<int>,arr2,size);

  th1.join();
  th2.join();

  return 0;
}