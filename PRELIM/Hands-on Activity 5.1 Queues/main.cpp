#include <iostream>
#include "queueArr.h"

int main(){

    //creting an object
    queueArr<int> q(5);

    //enqueue 10,20,30,40,50
    q.Enqueue(1);

    std::cout << "Front: " <<q.front()<<std::endl;
    std::cout << "Back: " <<q.back()<<std::endl;
    std::cout << "Size: " <<q.Size()<<std::endl;

    q.Enqueue(2);
    std::cout << "Front: " <<q.front()<<std::endl;
    std::cout << "Back: " <<q.back()<<std::endl;
    std::cout << "Size: " <<q.Size()<<std::endl;
    q.Enqueue(3);
    q.Enqueue(4);
    std::cout << "Front: " <<q.front()<<std::endl;
    std::cout << "Back: " <<q.back()<<std::endl;
    std::cout << "Size: " <<q.Size()<<std::endl;
    q.Enqueue(5);
    std::cout << "Front: " <<q.front()<<std::endl;
    std::cout << "Back: " <<q.back()<<std::endl;
    std::cout << "Size: " <<q.Size()<<std::endl;
    q.Enqueue(6);

    std::cout <<"removed: "<< q.Dequeue()<< std::endl;
    std::cout <<"removed: "<< q.Dequeue()<< std::endl;
    
    q.Clear();
    std::cout << "is the queue empty? " << (q.Empty() ? "yes":"no")<<std::endl;

    return 0;
}