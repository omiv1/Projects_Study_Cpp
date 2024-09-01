//
// Created by lukas on 08.01.2024.
//

#include "twoWayLinkedList.h"

TwoWayLinkedList::TwoWayLinkedList() : head(nullptr), tail(nullptr) {}

void TwoWayLinkedList::addToFront(int val) {
    std::shared_ptr<Elem> newElem = std::make_shared<Elem>(val);

    if (!head) {
        head = newElem;
        tail = newElem;
    } else {
        newElem->next = head;
        head->prev = newElem;
        head = newElem;
    }
}

void TwoWayLinkedList::addToEnd(int val) {
    std::shared_ptr<Elem> newElem = std::make_shared<Elem>(val);

    if (!tail) {
        head = newElem;
        tail = newElem;
    } else {
        newElem->prev = tail;
        tail->next = newElem;
        tail = newElem;
    }
}

void TwoWayLinkedList::removeFromFront() {
    if (!head) {
        std::cout << "Lista jest pusta, nie można usunąć z początku." << std::endl;
    } else {
        std::shared_ptr<Elem> temp = head;
        head = head->next;

        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
    }
}

void TwoWayLinkedList::removeFromEnd() {
    if (!tail) {
        std::cout << "Lista jest pusta, nie można usunąć z końca." << std::endl;
    } else {
        std::shared_ptr<Elem> temp = tail;
        tail = tail->prev;

        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
    }
}

void TwoWayLinkedList::displayList() {
    std::shared_ptr<Elem> current = head;

    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

bool TwoWayLinkedList::isEmpty() {
    return head == nullptr;
}

TwoWayLinkedList::~TwoWayLinkedList() {
    std::cout << "Destruktor TwoWayLinkedList" << std::endl;
}
