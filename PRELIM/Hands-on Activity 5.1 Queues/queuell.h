#ifndef QUEUELL_H
#define QUEUELL_H

//create a class node
template <typename T>
class qNode{
    public:
        T data;
        qNode* next;
};
//new node creator
template <typename T>
qNode<T>* new_Node(T newData){
    //allocate  a space for the new node
    qNode<T>* newNode = new qNode<T>;

    //store the newData to the newNode
    newNode->data = newData;

    //point the newNode next to null
    newNode->next = nullptr;

    return newNode;
}
//enqueue
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    //create a new node
    qNode<T>* newNode = new_Node(newData);

    //check if the queue is empty
    if((*frontPtr)==nullptr && (*backPtr)==nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;  
    }

    //if not then insert at the back
    (*backPtr)->next = newNode; //LINKS the current back to the new node
    (*backPtr) = newNode;//ASSIGNs the backPtr to the new node
}

//dequeue
template<typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    //check if the queue is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout << "The queue is empty" << std::endl;
        return;
    }
    //create a temporary vatiable to store the new node to be deleted
    qNode<T>* deleteTemp = nullptr;

    //assigns the current front to the deleteTemp
    deleteTemp = (*frontPtr);

    //check if the queue has only one item
    if((*frontPtr)->next == nullptr && (*backPtr)->next==nullptr){
        //means only one item is in the queue
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteTemp;
        return;
    }

    (*frontPtr) = (*frontPtr)->next;
    deleteTemp->next = nullptr;

    //delete node
    delete deleteTemp;
}

//isEmpty
template <typename T>
bool isEmpty(qNode<T>* frontPtr, qNode<T>* backPtr){
    if (frontPtr== nullptr && backPtr==nullptr){
        return true;
    }else{
        return false;
    }
}

//diplayAll
template <typename T>
void display(qNode<T>* frontPtr, qNode<T>* backPtr){
    if(frontPtr == nullptr && backPtr==nullptr){
        std::cout << "The queue is empty" << std::endl;
        return;
    }

    while(frontPtr != nullptr){
        //PRINT data OF n
        std::cout << frontPtr->data;
        if(frontPtr->next != nullptr){
            std::cout << " ";
        }
        //GO TO NEXT NODE n := next
        frontPtr= frontPtr->next;
    }
    std::cout <<std::endl;
}

#endif