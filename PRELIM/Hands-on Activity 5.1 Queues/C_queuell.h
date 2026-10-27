#ifndef C_QUEUELL_H
#define C_QUEUELL_H
#include <string>

class Job{
    public:
        int Id;
        std::string name;
        int pages;
        Job(int newId = 0,std::string newName = "", int newPages = 0){
            Id = newId;
            name = newName;
            pages = newPages;
        }
};

class qNode{
    public:
        Job data;
        qNode* next;
};

qNode* new_Node(Job newData){
    //allocate  a space for the new node
    qNode* newNode = new qNode;

    //store the newData to the newNode
    newNode->data = newData;

    //point the newNode next to null
    newNode->next = nullptr;

    return newNode;
}

class Printer{
    private:
        qNode* front;
        qNode* back;
    public:
        Printer(){
            front = nullptr;
            back = nullptr;
        }

        bool isEmpty(){
            if (front== nullptr && back==nullptr){
                return true;
            }else{
                return false;
            }
        }
        //enqueue
        void addJob(Job job){
            //create a new node
            qNode* newNode = new_Node(job);

            //check if the queue is empty
            if(isEmpty()){
                front = newNode;
                back = newNode;
                return;  
            }
            //if not then insert at the back
            back->next = newNode; //LINKS the current back to the new node
            back = newNode;//ASSIGNs the backPtr to the new node
        }
        //dequeue
        void processJob(){
            // check empty
            if(isEmpty()){
                std::cout << "No jobs to print." << std::endl;
                return;
            }
            //create a temporary vatiable to store the new node to be deleted
            qNode* temp = nullptr;
            //assigns the current front to the deleteTemp
            temp = front;
            //display job being printed
            std::cout <<std::endl;
            std::cout << "Printing:" << std::endl;
            std::cout << "Job ID: " << front->data.Id<< std::endl;
            std::cout << "User: " << front->data.name << std::endl;
            std::cout << "Pages: " << front->data.pages << std::endl;
            
            //check if the queue has only one item
           if(front->next == nullptr && back->next==nullptr){
                //means only one item is in the queue
                front = nullptr;
                back = nullptr;
                delete temp;
                return;
            }
            front = front->next;
            temp->next = nullptr;

            //delete node
            delete temp;
            std::cout << "Job Printed." << std::endl;
        }

        void display(){
            if(isEmpty()){
                std::cout << "The queue is empty" << std::endl;
                return;
            }
            qNode* temp = front;
            std::cout << "================ Current Queue ================"<< std::endl;
            while(temp != nullptr){
                //PRINT data OF n
                std::cout << "Job ID: " << temp->data.Id << "      User: " << temp->data.name << "      Pages: " << temp->data.pages << std::endl;
                //GO TO NEXT NODE n := next
                temp= temp->next;
            }
        }
};
#endif