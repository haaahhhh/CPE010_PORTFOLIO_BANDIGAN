#include <iostream>
//for square root and power
#include <cmath>

//Create a C++ program that has a function that will calculate the distance between two points.
float distanceCalculator(float x1, float y1, float x2, float y2);

int main(){

    float x1, y1, x2,y2,distance;

    std::cout << "=======Distance Calculator======= \n";
    std::cout << "Enter Coordinate of first point: \n";
    std::cout << "x1: ";
    std::cin >> x1;
    std::cout << "y1: ";
    std::cin >> y1;

    std::cout << "\nEnter Coordinate of second point: \n";
    std::cout << "x2: ";
    std::cin >> x2;
    std::cout << "y2: ";
    std::cin >> y2;

    distance = distanceCalculator(x1,y1,x2,y2);

    std::cout << "\nThe distance between two points is: " << distance << std::endl;

    return 0;
}

float distanceCalculator(float x1, float y1, float x2, float y2){
    float distance;

    distance = sqrt((pow((x2-x1),2)) + (pow((y2-y1),2)));

    return distance;
}