#include <iostream>
#include "singly_ll.h"

int main(){
    //step 1
    SingleList<char>* head =  nullptr;
    SingleList<char>* second =  nullptr;
    SingleList<char>* third =  nullptr;
    SingleList<char>* fourth =  nullptr;
    SingleList<char>* fifth =  nullptr;
    SingleList<char>* last =  nullptr;
    
    //step 2
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;
    fifth = new SingleList<char>;
    last = new SingleList<char>;

    //step 3
    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = fourth;

    fourth->data = '0';
    fourth ->next = fifth;
 
    fifth ->data = '1';
    fifth ->next = last;

    last ->data = '0';
    last ->next = nullptr;

    std::cout <<"Testing of Traversal: " <<std::endl;
    ListTraversal(head);

    std::cout << "Testing of sslinsertHead: " << std::endl;
    sllinsertHead('G',&head);
    ListTraversal(head);
    
    std::cout << "Testing of sslGeneralInsert: " << std::endl;
    sslGeneralInsert('E',head->next->next);
    ListTraversal(head);

    // std::cout << "Testing of sslInsertEnd: " << std::endl;
    // sslInsertEnd('U', &head);
    // ListTraversal(head);

    sslGeneralInsert('B',head->next->next->next->next->next->next);
    ListTraversal(head);

    std::cout << "Testing of deleteing the node: " << std::endl;
    sslDeleteNode('C', &head);
    ListTraversal(head);
    sslDeleteNode('P', &head);
    ListTraversal(head);
    // sslDeleteNode('Q', &head);
    // ListTraversal(head);

    std::cout << "Deleteing all nodes: " << std::endl;
    sllDeleteList(&head);
    ListTraversal(head);

    return 0;
}   