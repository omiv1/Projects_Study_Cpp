//
// Created by lukas on 08.01.2024.
//

#ifndef LAB11_ZPO_LISTA_TWOWAYLINKEDLIST_H
#define LAB11_ZPO_LISTA_TWOWAYLINKEDLIST_H


#include "elem.h"

class TwoWayLinkedList {
private:
    std::shared_ptr<Elem> head;
    std::shared_ptr<Elem> tail;

public:
    TwoWayLinkedList();
    ~TwoWayLinkedList();

    void addToFront(int val);
    void addToEnd(int val);
    void removeFromFront();
    void removeFromEnd();
    void displayList();
    bool isEmpty();


};


#endif //LAB11_ZPO_LISTA_TWOWAYLINKEDLIST_H
