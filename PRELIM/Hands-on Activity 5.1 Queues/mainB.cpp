#include <iostream>
#include "queuell.h"


int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('C', &front, &back);
    std::cout <<"front: "<< front->data<<" back: "<<back->data<<std::endl;
    enqueue('H', &front, &back);
    std::cout <<"front: "<< front->data<<" back: "<<back->data<<std::endl;
    enqueue('R', &front, &back);
    std::cout <<"front: "<< front->data<<" back: "<<back->data<<std::endl;

    display(front,back);

    std::cout << "testing the dequeue operator: \n";
    dequeue(&front,&back);
    std::cout <<"front: "<< front->data<<" back: "<<back->data<<std::endl;
    dequeue(&front,&back);
    std::cout <<"front: "<< front->data<<" back: "<<back->data<<std::endl;
    dequeue(&front,&back);

    std::cout << "is the queue empty:" <<isEmpty(front,back)<<std::endl;

    return 0;
}