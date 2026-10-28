#include <iostream>
#include <thread>

int globalVar;

void add(int n);

int main(){

    std::thread th1(add,10);
    std::thread th2(add,6);
    std::thread th3(add,7);

    std::cout << globalVar << std::endl;
    th1.join();
    std::cout << globalVar << std::endl;
    th2.join();
    std::cout << globalVar << std::endl;
    th3.join();

    return 0;
}

void add(int n){
    globalVar += n;
    return;
}