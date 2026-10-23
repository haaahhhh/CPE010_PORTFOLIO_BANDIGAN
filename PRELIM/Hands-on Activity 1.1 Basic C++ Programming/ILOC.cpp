#include <iostream>

//Create a C++ program to swap the two numbers in different variables.
void numberSwapper();

//global variables
int  varA = 6;
int varB = 9;

int main(){

    std::cout << "The value of the variables: \n" ;
    std::cout << "Variable A: " << varA << std::endl;
    std::cout << "Variable B: " << varB << std::endl;

    numberSwapper();

    std::cout << "\nThe value of the variables after swapping: \n";
    std::cout << "Variable A: " << varA << std::endl;
    std::cout << "Variable B: " << varB << std::endl;

    return 0;
}

void numberSwapper(){
    int temp;
    temp = varA;
    varA = varB;
    varB = temp;
}