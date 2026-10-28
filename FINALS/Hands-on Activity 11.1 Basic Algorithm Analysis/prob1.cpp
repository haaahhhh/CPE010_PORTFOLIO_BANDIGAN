#include <iostream>
#include <chrono>

bool Unique(int A[], int size);
void Experimental(int size);

int main(){
  Experimental(1000);
  Experimental(10000);
  Experimental(100000);

  return 0;
}

bool Unique(int A[], int n){
  for(int i = 0; i<n-1;i++){
    for(int j = i+1; j<n; j++){
      if(A[i] == A[j]){
        return false;
      }
    }
  }
  return true;
}

void Experimental(int size){
  int* arr = new int[size]; 

  for(int i = 0; i < size;i++){
    arr[i] = i;
  }
  auto start = std::chrono::high_resolution_clock::now();
  std::cout << "Array is Unique?: " << Unique(arr,size)<< std::endl;

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count();
  std::cout << "Runtime: " << duration << " milliseconds\n";
}