#include <iostream>
#include <string>
#include <stack>

bool match(char open,char close);

int main(){
    std::stack<char> stack1;
    std::string newData;
    std::cout << "Enter Expression:" << std::endl;
    std::getline(std::cin, newData);

    for(char c: newData){
        if(c == '(' || c == '[' || c== '{'){
            stack1.push(c);
        }else if (c == ')' || c == ']' || c== '}'){
            if(stack1.empty()){
                std::cout <<"Error: Stack is empty." << std::endl;
                break;
            }else{
                if(match(stack1.top(),c)){
                    stack1.pop();
                }else{
                    std::cout <<"Error: Symbol not matched." << std::endl;
                }
            }
        }else{
            continue;
        }
    }
    if(!stack1.empty()){
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