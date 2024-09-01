//
// Created by lukas on 08.01.2024.
//

#include "elem.h"

Elem::Elem(int val) : data(val) {
    std::cout << "Konstruktor Elem: " << data << std::endl;
}

Elem::~Elem() {
    std::cout << "Destruktor Elem: " << data << std::endl;
}
