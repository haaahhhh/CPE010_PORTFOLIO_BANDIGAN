#include <iostream>

//global declarations
#define maxCap 10
int stackArr[maxCap];
int top = -1, newData;

//prototype functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void displayStack();

int main(){
//main driver
int choice;
    while(true){
        std::cout << "================================================================="<< std::endl;
        std::cout << "Stack Operations \n";
        std::cout << "1. PUSH 2. POP 3. TOP 4. isEmpty 5. isFull 6.displayStack 7. exit" <<std::endl;
        std::cout << "================================================================="<< std::endl;
        std::cin>>choice;
        
        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout<<"is the stack empty? " << isEmpty()<<std::endl;
            break;
            case 5: std::cout <<"is the stack full? " << isFull()<<std::endl;
            break;
            case 6: displayStack();
            break;
            case 7: return 0;
            break;
            default: std::cout<< "Invalid Choide" << std::endl;
            break;
        }
    }
    return 0;
}

//function definition
bool isEmpty(){
    if(top == -1) return true;
    return false;
}

bool isFull(){
    if(top == maxCap - 1) return true;
    return false;
}

void push(){
    //error checking
    if(isFull()){
        std::cout << "Stack overflow"<<std::endl;
        return;
    }
    //pushing the stack
    std::cout << "Enter  a new value: " <<std:: endl;
    std::cin >> newData;
    //how do we insert the data into the stack?
    stackArr[++top] = newData;
}

void pop(){
    if(isEmpty()){
        std::cout << "Stack underflow" <<std::endl;
        return;
    }

    //display the value that we are going to pop
    std::cout << "Popping: " << stackArr[top] << std::endl;
    //decrement the top value from the stack
    top--;
}
void Top(){
    if(isEmpty()){
        std::cout << "The stack is empty"<<std::endl;
        return;
    }
    std::cout<<"The value at the top of the stack: "<<stackArr[top] << std::endl;
}
void displayStack(){
    int temp[maxCap];
    int tempv = -1;
    if(isEmpty()){
        std::cout << "The stack is empty" <<std::endl;
        return;
    }
    std::cout << "Contents of stack" << std::endl;
    while(top != -1){
        temp[++tempv] = stackArr[top];
        std::cout << stackArr[top] << " ";
        top--;
    }
    while(tempv != -1){
        stackArr[++top] = temp[tempv];
        tempv--;
    }
    std::cout<<std::endl;
}