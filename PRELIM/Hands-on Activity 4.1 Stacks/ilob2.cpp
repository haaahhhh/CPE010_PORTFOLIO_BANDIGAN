#include <iostream>
#include "stackList.h"

int main(){
    push(1);
    std::cout << "After the first PUSH top of the stack is: ";
    Top<int>();

    push(5);
    std::cout << "After the second PUSH top of the stack is: ";
    Top<int>();

    displayAll<int>();

    pop<int>();
    std::cout << "After the first POP operation, the top of stack is: ";
    Top<int>();

    pop<int>();
    std::cout << "After the second POP operation, the top of stack is: ";
    Top<int>();

    pop<int>();
    
    return 0;
}
