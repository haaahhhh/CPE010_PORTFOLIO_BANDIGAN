#include <iostream>
#include <string>

#define maxCap 100
char stackArr[maxCap];
int top = -1;
std::string newData;

void push(char symbol);
void pop();
bool match(char open,char close);

int main(){
    std::cout << "Enter Expression:" << std::endl;
    std::getline(std::cin, newData);

    for(char c: newData){
        if(c == '(' || c == '[' || c== '{'){
            push(c);
        }else if (c == ')' || c == ']' || c== '}'){
            if(top == -1){
                std::cout <<"Error: Stack is empty." << std::endl;
                break;
            }else{
                if(match(stackArr[top],c)){
                    pop();
                }else{
                    std::cout <<"Error: Symbol not matched." << std::endl;
                }
            }
        }else{
            continue;
        }
    }
    if(top != -1){
        std::cout <<"Missing Closing Symbol." << std::endl;
    }else{
        std::cout << "Expression has balanced Symbols"<<std::endl;
    }

    return 0;
}

void push(char symbol){
    if(top == maxCap - 1){
        std::cout << "Stack Overflow" << std::endl;
        return;
    }
    stackArr[++top] = symbol;
}

void pop(){
    if(top == -1){
        std::cout << "Stack Underflow" << std::endl;
        return;
    }
    top--;
}

bool match(char open, char close){
    if(open == '(' && close == ')' || open == '[' && close == ']' || open == '{' && close == '}'){
        return true;
    }else return false;
}