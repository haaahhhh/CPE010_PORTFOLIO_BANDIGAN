#include <iostream>
#include <queue>

void display(std::queue<char> Q);

int main(){

    //create an object:
    std::queue<char> myQ;
    std::queue<char> test;

    //use the enqueue operation
    myQ.push('C');
    myQ.push('H');
    myQ.push('R');
    myQ.push('I');
    myQ.push('S');
    

    std::cout << "current front is: "<<myQ.front()<<std::endl;
    std::cout << "current back is: "<< myQ.back()<<std::endl;
    
    display(myQ);
    
    //use the dequeue operation
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    
    return 0;
}
void display(std::queue<char> Q){
    std::queue<char> temp = Q;
    std::cout<<"\nThe contents of the queue:"<<std::endl;
    while(temp.size() != 0){
        std::cout << temp.front()<<" ";
        temp.pop();
    }
}