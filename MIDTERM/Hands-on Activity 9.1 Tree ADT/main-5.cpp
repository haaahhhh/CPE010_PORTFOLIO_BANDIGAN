#include <iostream>
#include "BST.h"

int main(){
    //create the root node
    BinarySearchTree<int> tree('K');

    // tree.insert(3);
    // tree.insert(9);
    // tree.insert(18);
    // tree.insert(0);
    // tree.insert(1);
    // tree.insert(4);
    // tree.insert(5);

    tree.insert('E');
    tree.insert('P');
    tree.insert('B');
    tree.insert('H');
    tree.insert('M');
    tree.insert('T');
    tree.insert('A');
    tree.insert('S');
    // tree.insert(80);

    std::cout<< "preOrder: "; 
    tree.preOrder();

    std::cout << std::endl;
    std::cout << "inOrder: ";
    tree.inOrder();
    std::cout << std::endl;

    std::cout << "postOrder: ";
    tree.postOrder();
     

    return 0;
}