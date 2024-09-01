#include <iostream>
#include "TwoWayLinkedList.h"
#include "Elem.h"

int main() {
    TwoWayLinkedList list;

    list.addToFront(1);
    list.addToFront(2);
    list.addToEnd(3);

    list.displayList();

    list.removeFromFront();
    list.removeFromEnd();

    list.displayList();

    return 0;
}