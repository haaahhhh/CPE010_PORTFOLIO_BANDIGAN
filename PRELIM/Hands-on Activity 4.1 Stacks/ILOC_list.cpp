#include <iostream>
#include <string>
#include "stackList.h"

bool match(char open,char close);

int main(){
    std::string newData;
    std::cout << "Enter Expression:" << std::endl;
    std::getline(std::cin, newData);

    for(char c: newData){
        if(c == '(' || c == '[' || c== '{'){
            push(c);
        }else if (c == ')' || c == ']' || c== '}'){
            if(isEmpty<char>()){
                std::cout <<"Error: Stack is empty." << std::endl;
                break;
            }else{
                if(match(head<char>->data,c)){
                    pop<char>();
                }else{
                    std::cout <<"Error: Symbol not matched." << std::endl;
                }
            }
        }else{
            continue;
        }
    }
    if(!isEmpty<char>()){
        std::cout <<"Missing Closing Symbol." << std::endl;
    }else{
        std::cout << "Expression has balanced Symbols"<<std::endl;
    }

    return 0;
}

bool match(char open, char close){
    if(open == '(' && close == ')' || open == '[' && close == ']' || open == '{' && close == '}'){
        return true;
    }else return false;
}