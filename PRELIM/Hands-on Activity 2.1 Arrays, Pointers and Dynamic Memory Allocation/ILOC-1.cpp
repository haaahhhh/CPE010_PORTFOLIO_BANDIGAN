#include <iostream>
#include <string.h>

class Fruit{
    private:
        std::string name;
        float price;
        int quantity;
    public:
        //constructor
        Fruit(std::string newName="apple", float newPrice = 20, int newQuan=1);
        //destructor
        ~Fruit();
        //copy constructor
        Fruit(const Fruit &copyFruit);
        //copy assignment operator
        Fruit& operator=(const Fruit& copyFruit);
        void printDetails();
        float getTotal();
};
class Vegetable{
    private:
        std::string name;
        float price;
        int quantity;
    public:
        //constructor
        Vegetable(std::string newName = "eggplant", float newPrice=20, int newQuan=1);
        //destructor
        ~Vegetable();
        //copy constructor
        Vegetable(const Vegetable &copyVegie);
        //copy assignment operator
        Vegetable& operator=(const Vegetable& copyVegie);
        void printDetails();
        float getTotal();
};

float totalSum(Fruit fruits[], Vegetable veggies[], int size);

int main(){
    const size_t j = 2;
    int veg_size = 2;

    Fruit* grocery_fruit = new Fruit[j]{Fruit("Apple", 10,7),Fruit("Banana",10,8)};
    Vegetable* grocery_vegie = new Vegetable[j]{Vegetable("Broccoli",60,12),Vegetable("Lettuce",50,10)};

    std::cout << "----Jenna's Grocery List----" << std::endl;
    for(int i = 0;i<2;i++){
        grocery_fruit[i].printDetails();
    }
    for(int i = 0;i<2;i++){
        grocery_vegie[i].printDetails();
    }

    std::cout << "--------------------" << std::endl;
    std::cout << "Total Price: PHP"<<totalSum(grocery_fruit,grocery_vegie,j)<<std::endl; 

    Vegetable* temp = new Vegetable[veg_size - 1];

    temp[0] = grocery_vegie[0];

    delete[] grocery_vegie;

    grocery_vegie = temp;
    veg_size--;
    
    delete[] grocery_fruit;
    delete[] grocery_vegie;

    return 0;
}

Fruit::Fruit(std::string newName, float newPrice, int newQuan){
    //std::cout << "constructor" <<std::endl;
    name = newName;
    price = newPrice;
    quantity = newQuan;
}
Fruit::~Fruit(){
    //std::cout << "destructor" << std::endl;
}
Fruit::Fruit(const Fruit &copyFruit){
    //std::cout << "copy constructor" << std::endl;
    name = copyFruit.name;
    price = copyFruit.price;
    quantity = copyFruit.quantity;
}
Fruit& Fruit::operator=(const Fruit& copyFruit){
    if (this != &copyFruit){
        //std::cout << "copy assignment operator" << std::endl;
        name = copyFruit.name;
        price = copyFruit.price;
        quantity = copyFruit.quantity;
    }
    return *this;
}
void Fruit::printDetails(){
    std::cout << this->name << " PHP" << this->price <<" x"<< this->quantity << std::endl;
}

float Fruit::getTotal(){
    return price *quantity;
}

Vegetable::Vegetable(std::string newName, float newPrice, int newQuan){
   //std::cout << "constructor" <<std::endl;
    name = newName;
    price = newPrice;
    quantity = newQuan;
}
Vegetable::~Vegetable(){
    //std::cout << "destructor" << std::endl;
}
Vegetable::Vegetable(const Vegetable &copyVegie){
    //std::cout << "copy constructor" << std::endl;
    name = copyVegie.name;
    price = copyVegie.price;
    quantity = copyVegie.quantity;
}
Vegetable& Vegetable::operator=(const Vegetable& copyVegie){
    if (this != &copyVegie){
        //std::cout << "copy assignment operator" << std::endl;
        name = copyVegie.name;
        price = copyVegie.price;
        quantity = copyVegie.quantity;
    }
    return *this;
}
void Vegetable::printDetails(){
    std::cout << this->name << " PHP" << this->price <<" x"<< this->quantity << std::endl;
}

float Vegetable::getTotal(){
    return price *quantity;
}

float totalSum(Fruit fruits[], Vegetable veggies[], int size){
    float total = 0;
    
    for(int i = 0; i <size; i++){
        total += fruits[i].getTotal();
        total += veggies[i].getTotal();
    }
    return total;
}
