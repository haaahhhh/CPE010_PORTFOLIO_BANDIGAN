#include <iostream>
#include "C_queuell.h"

int main(){
    Printer printer;

    printer.addJob(Job(1,"Christian",3));
    printer.addJob(Job(2,"Topher",1));
    printer.addJob(Job(3,"Acquila",3));
    printer.addJob(Job(4,"Gianne",5));

    printer.display();
    printer.processJob();
    printer.processJob();

    printer.addJob(Job(5,"Justin",4));
    printer.addJob(Job(6,"Carlito",7));
    printer.addJob(Job(7,"Brylle",3));
    printer.addJob(Job(8,"Louis",2));
    printer.display();

    printer.processJob();
    printer.processJob();
    printer.display();

    return 0;
}