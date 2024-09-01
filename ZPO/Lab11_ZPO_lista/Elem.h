//
// Created by lukas on 08.01.2024.
//

#ifndef LAB11_ZPO_LISTA_ELEM_H
#define LAB11_ZPO_LISTA_ELEM_H


#include <iostream>
#include <memory>

class Elem {
public:
    std::shared_ptr<Elem> next;
    std::shared_ptr<Elem> prev;
    int data;

    Elem(int val);

    ~Elem();
};


#endif //LAB11_ZPO_LISTA_ELEM_H
