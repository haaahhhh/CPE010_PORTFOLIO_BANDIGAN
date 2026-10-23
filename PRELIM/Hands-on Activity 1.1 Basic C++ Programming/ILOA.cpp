#include<iostream>
//used for typeid function that checks the data type
#include<typeinfo>

//Create a function that will take two numbers and display the sum
int sumOfTwoNum(int fNum, int sNum);

//Create a function that will return whether variable A is greater than variable B
int greaterThan(int varA, int varB);

//Create a function that will take two Boolean values and display the result of all logical operations then return true if it was a success.
template <typename T> T logicOperations(T fVal, T sVal);

int main(){

    std::cout << "The sum of two numbers is: "<< sumOfTwoNum(6,7) << std::endl;

    if(greaterThan(7,5) == 1){
        std::cout << "\nfirst variable is greater than the second variable\n" << std::endl;
    }else{
        std::cout << "\nfirst variable is not greater than the second variable\n" << std::endl;
    }

    if(logicOperations(3,4)){
        std::cout << "\nSuccess!" << std::endl;
    }else{
        std::cout << "Failed. The given values are not boolean values \n";
    }

    return 0;
}

int sumOfTwoNum(int fNum, int sNum){

    int sum = fNum + sNum;

    return sum;
}

int greaterThan(int varA, int varB){

    int answer = varA > varB;

    if(answer == 1){
        return 1;
    }else{
        return 0;
    }
}

template <typename T> T logicOperations(T fVal, T sVal){
    if(typeid(fVal) != typeid(bool) && typeid(sVal)!= typeid(bool)){
        return false;
    }

    bool And = fVal && sVal;
    bool Or = fVal || sVal;
    bool Not = !(fVal && sVal);

    std::cout <<"Result of AND operato: "<< And << std::endl;
    std::cout << "Result of OR operator: " << Or << std::endl;
    std::cout << "Result of NOT operator: " << Not << std::endl;

    return true;
}