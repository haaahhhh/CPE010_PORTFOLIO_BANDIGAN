#include "node.h"

#ifndef B3SEARCHINGALGO_H
#define B3SEARCHINGALGO_H

template <typename T>
void linearSearchAR(int size, T dataFind, T array[]){
//    //while loop
//     int i=0;
//     while(i< size){
//         if(dataFind == array[i]){
//             std::cout <<"Searching is successful\n";
//             return;
//         }
//         i++;
//     }

//     std::cout <<"Searching is unsuccessful\n";

    //for loop implementation
    for(int j=0;j<size; j++){
        if(dataFind == array[j]){
            std::cout <<"Searching is successful\n";
            return;
        }
    }
    std::cout <<"Searching is unsuccessful\n";
}

template <typename T>
void linearSearchLL(Node <T> *nodes, T datafind){
    //repeat the loop until the currrent node is not NULL
    while(nodes != nullptr){
        // check if the item = currrent node data
        if(nodes->data == datafind){
            std::cout <<"The data: "<<nodes->data<< " was found successfully \n";
            return;
        }
        //move onto the next node
        nodes = nodes->next;
    }
    std::cout << "Searching is unsuccessful \n";
}

template <typename T>
bool binarySearchArr(T data[], int high, int low, T dataFind){
    if(low > high){
        std::cout << "the data was not found\n";
        return false;
    }
    int middle = (int((low+high)/2));
    if(dataFind == data[middle]){
        std::cout << "the data was found\n";
        return true;
    }
    else if(dataFind< data[middle]){
        return binarySearchArr(data, middle - 1, low, dataFind);
    }
    else{
        return binarySearchArr(data,high, middle + 1, dataFind);
    } 
}

//middle funnction getter
template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;

    //continue until fast reaches tthe end or the last node of the currrent search range
    while(fast != last  && fast-> next != last){
        //moce slow one step
        slow = slow->next;
        //move fast two steps
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){
    //step 1: set start to the  head of the list and set last to null
    Node<T>* last = nullptr;

    while(start != last){
        Node<T>* middle = getMiddle(start, last);

        //if the middle element is same as the key to be searched, we return it.
        if(middle->data == dataFind){
            std::cout << "searching is successful\n";
            return;
        }
        else if(middle->data > dataFind){
            last = middle;
        }
        else{
            start = middle->next;
        }
    }
    std::cout << "Searching is unsuccesssful\n";
}

#endif