#include <iostream>
#include <cstdlib>
#include <time.h>
#include "searchingAlgo.h"

const int max_size = 50;

int main(){

    // int dataset[max_size];
    // srand(time(0));
    // for(int i =0; i<max_size; i++){
    //     dataset[i] = rand();
    //     std::cout << dataset[i]<< " ";
    // }
    // std::cout<<std::endl;

    // std::cout <<"What number to find: "; 
    // int choice;

    // std::cin >> choice;
    // linearSearchAR(max_size, 10, dataset);

    //CREATE A NODE FOR YOUR NAME

    //Create a Node
    // Node<char> *name1 = new_node('C');
    // Node<char> *name2 = new_node('H');
    // Node<char> *name3 = new_node('R');
    // Node<char> *name4 = new_node('I');
    // Node<char> *name5 = new_node('S');
    // Node<char> *name6 = new_node('T');
    // Node<char> *name7 = new_node('I');
    // Node<char> *name8 = new_node('A');
    // Node<char> *name9 = new_node('N');

    // // //Connect the Nodes
    // name1->next = name2;
    // name2->next = name3;
    // name3->next = name4;
    // name4->next = name5;
    // name5->next = name6;
    // name6->next = name7;
    // name7->next = name8;
    // name8->next = name9;

    // linearSearchLL(name1, 'A');

    //generate a sorted array: (use for loop)
    int newArrr[max_size];
    for(int i = 0; i <max_size; i++){
        newArrr[i] = i;
    }
    binarySearchArr(newArrr,max_size,77);

    // Node<int> *name1 = new_node(10);
    // Node<int> *name2 = new_node(11);
    // Node<int> *name3 = new_node(12);
    // Node<int> *name4 = new_node(13);
    // Node<int> *name5 = new_node(14);
    // Node<int> *name6 = new_node(15);
    // Node<int> *name7 = new_node(16);

    // //Connect the Nodes
    // name1->next = name2;
    // name2->next = name3;
    // name3->next = name4;
    // name4->next = name5;
    // name5->next = name6;
    // name6->next = name7;

    // binarySearchLL(name1,10);

    return 0;
}
