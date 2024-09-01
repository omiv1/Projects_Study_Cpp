//
// Created by lukas on 23.10.2023.
//

#ifndef LAB3_1_ZPO_LO_ADDING_H
#define LAB3_1_ZPO_LO_ADDING_H
#include <iostream>
using namespace std;

template <typename T>
class Adding
{
private:
    T element;

public:
    Adding(T value);
    void add(T value);
    void show();
};

template <typename T>
Adding<T>::Adding(T value)
{
    element = value;
}

template <typename T>
void Adding<T>::add(T value)
{
    element = element + value;
}

template <typename T>
void Adding<T>::show()
{
    cout << "Element: " << element << endl;
}

#endif //LAB3_1_ZPO_LO_ADDING_H
