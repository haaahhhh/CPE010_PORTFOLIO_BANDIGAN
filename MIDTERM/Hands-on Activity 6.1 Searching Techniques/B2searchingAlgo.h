#include "node.h"
#ifndef B2SEARCHINGALGO_H
#define B2SEARCHINGALGO_H

template <typename T>
void linearSearchAR(int size, T dataFind, T array[]){
    int repeat = 0;
    bool found = false;
    //for loop implementation
    for(int j=0;j<size; j++){
        if(dataFind == array[j]){
            repeat++;
            found = true;
        }
    }
    if(found == true){
        std::cout << "Searching is successful \n";
        std::cout << dataFind << " was found " << repeat << " time/s.\n";
    }else{
        std::cout <<"Searching is unsuccessful\n";
    }
}

template <typename T>
void linearSearchLL(Node <T> *nodes, T datafind){
    int repeat = 0;
    bool found = false;
    //repeat the loop until the currrent node is not NULL
    while(nodes != nullptr){
        // check if the item = currrent node data
        if(nodes->data == datafind){
            repeat++;
            found = true;
        }
        //move onto the next node
        nodes = nodes->next;
    }
    if(found == true){
        std::cout <<"The data: "<<datafind<< " was found successfully. \n";  
        std::cout << datafind << " was found " << repeat << " time/s.\n"; 
    }else{
        std::cout << "Searching is unsuccessful \n";
    }
}

#endif
