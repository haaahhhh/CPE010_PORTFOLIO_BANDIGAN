#include <iostream>
#include <algorithm>

const int size = 100;
int memArr[size];

int getMinSteps(int n );

int main(){
  // initialize memoized array
    for (int i=0; i<=size; i++)
        memArr[i] = -1;

  std::cout << getMinSteps(3) << std::endl;
  std::cout << getMinSteps(11) << std::endl;

  return 0;
}

int getMinSteps (int n){
  if (n == 1) return 0; // base case
  if( memArr[n] != -1 ){ 
    return memArr[n]; // we have solved it already :)
  }
  int r = 1 + getMinSteps( n - 1 ); // '-1' step . 'r' will contain the optimal answer finally
  if( n%2 == 0 ) r = std::min( r , 1 + getMinSteps( n / 2 )); // '/2' step
  if( n%3 == 0 ) r = std::min( r , 1 + getMinSteps( n / 3 )) ; // '/3' step
  memArr[n] = r ; // save the result. If you forget this step, then its same as plain recursion.
  return r;
}
