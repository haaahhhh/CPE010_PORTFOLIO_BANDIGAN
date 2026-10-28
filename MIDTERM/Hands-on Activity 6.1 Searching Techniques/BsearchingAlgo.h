#include "node.h"
#ifndef BSEARCHINGALGO_H
#define BSEARCHINGALGO_H

template <typename T>
void linearSearchAR(int size, T dataFind, T array[]){
    int comparison = 0;
    //for loop implementation
    for(int j=0;j<size; j++){
        comparison++;
        if(dataFind == array[j]){
            std::cout <<"Searching is successful\n";
            std::cout << "The data: " << dataFind << " was found after " << comparison << " comparisons. \n";
            return;
        }
    }
    std::cout <<"Searching is unsuccessful\n";
}

template <typename T>
void linearSearchLL(Node <T> *nodes, T datafind){
    int comparison = 0;
    //repeat the loop until the currrent node is not NULL
    while(nodes != nullptr){
        // check if the item = currrent node data
        comparison++;
        if(nodes->data == datafind){
            std::cout <<"The data: "<<nodes->data<< " was found successfully after "<<comparison << " comparisons.\n";
            return;
        }
        //move onto the next node
        nodes = nodes->next;
    }
    std::cout << "Searching is unsuccessful \n";
}



#endif