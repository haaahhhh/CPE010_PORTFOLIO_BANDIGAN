#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
#include "searchingAlgo.h"

void ExperimentalLinear(int size);
void ExperimentalBinary(int size);

int main(){

  std::thread th1(ExperimentalLinear,100000);
  std::thread th2(ExperimentalBinary,100000);

  th1.join();
  th2.join();

  return 0;
}

void ExperimentalLinear(int size){
  int* arr = new int[size];

  for(int i = 1; i< size;i++){
    arr[i]= i;
  }
  auto start = std::chrono::high_resolution_clock::now();
  std::cout<< "\nStart Linear Search" <<std::endl;
  linearSearchAR(size,100001,arr);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count();
  std::cout << "Linear Search Runtime: " << duration << " milliseconds\n";
}

void ExperimentalBinary(int size){
  int* arr = new int[size];

  for(int i = 1; i< size;i++){
    arr[i]= i;
  }
  auto start = std::chrono::high_resolution_clock::now();
  std::cout<< "\nStart Binary Search" <<std::endl;
  linearSearchAR(size,100001,arr);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count();
  std::cout << "Binary Search Runtime: " << duration << " milliseconds\n";
}
