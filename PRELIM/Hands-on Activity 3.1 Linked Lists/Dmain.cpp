#include <iostream>
#include "doubly_ll.h"

int main(){
    //create a list 'C P E'
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    
    //treversal
    std::cout <<"Testing the DLL Traversal" << std::endl;
    dllTraversal(head);

    //testing the insert at the head
    std::cout << "Testing the insertion at the head node" << std::endl;
    dllInsertHead('X', &head);
    dllTraversal(head);

    //testing the insert at the end
    std::cout << "Testing the insertion at the end" <<std::endl;
    dllInsertEnd('0',head);
    dllTraversal(head);

    //testing general insert
    std::cout << "Testing General Insert" <<std::endl;
    dllGeneralInsert('1',head->next->next);
    dllTraversal(head);

    //testing deleting a node
    std::cout << "Testing delete a node" << std::endl;
    dllDeleteNode('X',&head);
    dllTraversal(head);
    dllDeleteNode('0',&head);
    dllTraversal(head);
    dllDeleteNode('1',&head);
    dllTraversal(head);


    return 0;
}