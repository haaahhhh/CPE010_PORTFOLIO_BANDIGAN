#include <iostream>

class Triangle{
    private:
        double totalAngle, angleA, angleB, angleC;
    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
        //A function that determines whether the triangle is acute-angled, obtuse-angled or ‘others.’
        int triangleType();
};

//A function to compute for the area of a triangle
float triangleArea(float base, float height);

//A function to compute for the perimeter of a triangle
float trianglePerimeter(float side1, float side2, float side3);


int main(){
    Triangle set1(40, 30, 110);
    if(set1.validateTriangle()){
        std::cout << "\nThe shape is a valid triangle. \n";
    }else{
        std::cout << "\nThe shape is NOT a valid triangle. \n";
    }
    
    set1.setAngles(40,40,100);
    if(set1.validateTriangle()){
        std::cout << "The shape is a valid triangle. \n\n";
    }else{
        std::cout << "The shape is NOT a valid triangle. \n\n";
    }

    std::cout << "The area of a triangle where it's base is equal to 10 and height is equal to 8: "<< triangleArea(10,8) << std::endl;    

    std::cout << "\nThe perimeter of a triangle where the length of it's sides are all 8: " << trianglePerimeter(8,8,8) << std::endl;

    if(set1.triangleType() == 1){
        std::cout << "The given triangle is obtuse-angled.";
    }else if(set1.triangleType() == 2){
        std::cout << "The given triangle is acute-angled.";
    }else if(set1.triangleType() == 3){
        std::cout << "The given triangle is a right triangle.";
    }else{
        std::cout << "The given shape is NOT a valid triangle.";
    }
    
    return 0;
}

Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}
void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle(){
    return (totalAngle <=180);
}

float triangleArea(float base, float height){
    float area;

    area = 0.5*(base*height);
    
    return area;
}

float trianglePerimeter(float side1, float side2, float side3){
    return side1 + side2 + side3;
}

int Triangle::triangleType(){
    double angles[3] = {angleA, angleB, angleC};
    if(totalAngle <=180){
       for(int i = 0;i <=3; i++){
        if(angles[i] > 90){
            return 1;
        }
        else if(angles[i] == 90){
            return 3;
        }
    }
    return 2; 
    }
    return 0;
}