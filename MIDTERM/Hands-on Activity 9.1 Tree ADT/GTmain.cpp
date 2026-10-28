#include <iostream>
#include "GT.h"

int main(){
    GeneralTree<char>* root = new GeneralTree<char>('A');

    root->insertChild('B');
    root->insertChild('C');
    root->insertChild('D');
    root->insertChild('E');
    root->insertChild('F');
    root->insertChild('G');

    root->getChild('D')->insertChild('H');
    root->getChild('E')->insertChild('I');
    root->getChild('E')->insertChild('J');
    root->getChild('F')->insertChild('K');
    root->getChild('F')->insertChild('L');
    root->getChild('F')->insertChild('M');
    root->getChild('G')->insertChild('N');
    root->getChild('E')->getChild('J')->insertChild('P');
    root->getChild('E')->getChild('J')->insertChild('Q');
    
    std::cout << "Pre-Order" << std::endl;
    root->preOrder();

    std::cout << "\nPost-Order" << std::endl;
    root->postOrder();

    std::cout << "\nIn-Order" << std::endl;
    root->inOrder();

    root->getChild('G')->insertChild('O');
    root->findData(1,'O');
    root->findData(2,'O');
    root->findData(3,'O');
    return 0;
}   