#include <iostream>
#include <stack>

int main(){
    std::stack<int> newStack;
    std::stack<int> newStack2;
    
    newStack.push(3); //Adds 3 to the stack
    newStack.push(8);
    newStack.push(15);

    //returns a boolean response depending on if the stack is empty or not
    std::cout << "Stack Size: " << newStack.empty() << std::endl;

    //returns the size  of the stack itself
    std::cout << "Stack Size: " << newStack.size() << std::endl;

    //returns the topmost element of the stack
    std::cout << "Top Element of the Stack: " << newStack.top() << std::endl;

    //removes the top most element of the stack
    newStack.pop();

    std::cout << "Top Element of the Stack: " << newStack.top() << std::endl;

    std::cout << "Stack Size: " << newStack.size() << std::endl;

    //emplace
    newStack.emplace(20);
    std::cout << "The element at the top of the stack is: "<<newStack.top()<<std::endl;
    std::cout << "The size of the stack is: " << newStack.size()<< std::endl;

    //swap
    std::cout<< "is stack2 empty? "<<newStack2.empty()<<std::endl;
    std::cout<<"Swapping stack1 and stack2"<<std::endl;
    newStack.swap(newStack2);
    std::cout<< "is stack2 empty? "<<newStack2.empty()<<std::endl;
    std::cout << "The element at the top of stack2 is: "<<newStack2.top()<<std::endl;
    std::cout<< "is stack1 empty? "<<newStack.empty()<<std::endl;

    return 0;
}