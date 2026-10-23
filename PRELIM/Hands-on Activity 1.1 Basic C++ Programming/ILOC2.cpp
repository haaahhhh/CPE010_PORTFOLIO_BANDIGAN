#include <iostream>

//Create a C++ program that has a function to convert temperature in Kelvin to Fahrenheit.
float kelvinToFahrenheit(float kelvin);

int main(){
    float kelvin;
    float fahrenheit;

    std::cout << "=======Kelvin to Fahrenheit Converter======= \n" ;
    std::cout << "Input Kelvin Temperature: ";
    std::cin >> kelvin;
    
    fahrenheit = kelvinToFahrenheit(kelvin);

    std::cout << "Converted to Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}

float kelvinToFahrenheit(float kelvin){
    float fahrenheit;

    fahrenheit = (((kelvin - 273.15)*1.8) + 32);

    return fahrenheit;
}