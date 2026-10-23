#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* prev = nullptr;
        DoubleList<T>* next = nullptr;
};

//creating a node
template <typename T>
DoubleList<T> *CreateNewNode(T newData){
    //dynamically  allocate a new memory for the node
    DoubleList<T> *newNode = new DoubleList<T>;
    //store the data in the node
    newNode->data = newData;

    //point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

    //return the address of the newly creates node
    return newNode;
}

template<typename T>
void dllTraversal(DoubleList<T>* currentNode){
    //temp variable to store the last node visited
    DoubleList<T> *tail;
    //check if the list is empty
    if(currentNode == nullptr){
        std::cout << "The list is empty" <<std::endl;
        return;
    }
    std::cout << "Forwarding" << std::endl;
    //move forward
    while(currentNode != nullptr){
        std::cout << currentNode->data <<" ";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    //add a next line
    std::cout << std::endl;
    std::cout << "Backwarding" << std::endl;
    //move backward
    while(tail != nullptr){
        std::cout << tail->data<<" ";
        tail = tail->prev;
    }
    std::cout << std::endl;
}

// inserting at the head of the list
template<typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    //creating a new node 
    DoubleList<T>* newNode = CreateNewNode(newData); 
    //new node should point to the current head
    newNode->next = *currentHead;
    //current head should point back to the new node 
    (*currentHead)->prev = newNode;
    //update the pointer head
    *currentHead = newNode;
}

//inserting at the end of the list
template<typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead){
    //create a new node
    DoubleList<T>* newNode = CreateNewNode(newData);
    //traverse until we reach the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }
    //connect the last node to the new node
    currentHead->next = newNode;
    //connect the new node back to last node
    newNode->prev = currentHead;
}

//general insert
template<typename T>
void dllGeneralInsert(T newData, DoubleList<T>* preNode){
    if(preNode == nullptr){
        std::cout << "Previous value cannot be null" <<std::endl;
        return; 
    }
    DoubleList<T>* newNode = CreateNewNode(newData);

    newNode->next = preNode->next;
    newNode->prev = preNode;
    if(preNode->next != nullptr){
        preNode->next->prev = newNode;
    }
    preNode->next = newNode;
} 

//deleting a node
template<typename T>
void dllDeleteNode(T findData, DoubleList<T>** head){
    if(*head == nullptr)return;

    DoubleList<T>* currNode = *head;
    DoubleList<T>* preNode = nullptr;

    while(currNode != nullptr && currNode->data !=findData){
        preNode = currNode;
        currNode = currNode->next;
    }
    if(currNode == nullptr){
        std::cout << "Data is not found." << std::endl;
        return;
    }
    if(preNode == nullptr){
        *head = currNode->next;
        if(*head != nullptr){
            (*head)->prev = nullptr;   
        }
    }else{
        preNode->next = currNode->next;
        if(currNode->next !=nullptr){
            (currNode->next)->prev = preNode;
        }
    }
    delete currNode;
}

#endif
