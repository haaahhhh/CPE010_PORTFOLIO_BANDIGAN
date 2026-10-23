#ifndef SINGLY_LL_H
#define SINGLY_LL_H

//node creation
template <typename T>
class SingleList{
    public:
        T data; //this contains the data to be stored in the node 
        SingleList<T>* next = nullptr;
};

template <typename T>
void ListTraversal(SingleList<T>* head){
    if(head == nullptr){
        std::cout << "The list is empty." << std::endl;
        return;
    }

    while(head != nullptr){
        //PRINT data OF n
        std::cout << head->data;
        if(head->next != nullptr){
            std::cout << " ";
        }
        //GO TO NEXT NODE n := next
        head = head->next;
    }
    std::cout <<std::endl;
}

template <typename T>
void sllinsertHead(T newData, SingleList<T>** currentHead){
    //1. Allocate memory for new node
    SingleList<T>*  newNode = new SingleList<T>;
    
    //2.Put our data in new node
    newNode->data = newData;

    //3.Set Next of the new node to point to the previous Head
    newNode -> next= *currentHead;

    //4. Reset Head to point to the new node
    *currentHead = newNode;
}

template <typename T>
void sslGeneralInsert(T newData, SingleList<T>* preNode){
    //1.Check if it is the head node (previous node is null)
    if(preNode == nullptr){
        //2.If null, print "Previous node cannot be null."
        std::cout << "Previous value cannot be null" << std::endl;
        return;
    } 
    //3.Allocate a new node
    SingleList<T>* newNode = new SingleList<T>;

    //4.Store data in the new node
    newNode->data = newData;

    //5.Point new node to the node previous node was pointing to
    newNode->next = preNode->next;

    //6.Point previous node to the new node
    preNode->next = newNode;
}

template <typename T>
void sslInsertEnd(T newData, SingleList<T>** head){
    //1.Allocate new node
    SingleList<T>* newNode = new SingleList<T>;
    //2. Dereference to head node
    SingleList<T>* currentNode = *head;
    //3.Store data in new node 
    newNode->data = newData;
    //4.Point next of new node to NULL
    newNode ->next = nullptr;
    //5.Traverse the list until next of the node is null
    while(currentNode->next != nullptr){
        currentNode = currentNode ->next;
    }

    //6. Point the next of the current node to the new node
    currentNode->next = newNode; 
}

template <typename T>
void sslDeleteNode(T findData, SingleList<T>** head){
    //if there is nothing to be deleted?
    if(*head == nullptr) return;

    SingleList<T>* currNode = *head;
    SingleList<T>* preNode = nullptr;
    
    //searching the node: 1. the node doesen't exist + we found the data
    while(currNode != nullptr && currNode ->data != findData){
        preNode = currNode;
        currNode = currNode ->next;
    }
    //if the data is not found currNode == nullptr in the while loop
    if(currNode == nullptr){
        std::cout << "The data is not found"<< std::endl;
        return;
    }

    //if data was found
    if(preNode == nullptr){
        *head = currNode->next;
    }else{
        preNode->next = currNode ->next;
    }

    delete currNode;
}

template <typename T>
void sllDeleteList(SingleList<T>** head){
    SingleList<T>* current = *head;

    while(current != nullptr){
        SingleList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}
#endif

