//
// Created by lukas on 29.10.2023.
//

#ifndef LAB3_3_ZPO_LO_MYARRAY_H
#define LAB3_3_ZPO_LO_MYARRAY_H
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class MyArray {
private:
    T* elements;
    int maxSize;
    int currentIndex;

public:
    MyArray(int size)
    {
        elements =  new T[size];
        maxSize = size;
        currentIndex = 0;
    };
    MyArray()
    {
        elements = new T[10];
        maxSize = 10;
        currentIndex = 0;
    };
    ~MyArray()
    {
        delete[] elements;
    };

    void sortArray()
    {
        sort(elements,elements + currentIndex);
    };
    T getMaxElement()
    {
        T maxElement = elements[0];
        for(int i = 0; i<currentIndex; i++)
        {
            if(elements[i] > maxElement)
            {
                maxElement = elements[i];
            }
        }
        return maxElement;
    };
    void display()
    {
        for (int i = 0; i<currentIndex; i++) {
            cout<<elements[i]<<" ";
        }
        cout<<endl;
    };
    void addElement(T element)
    {
        if (currentIndex < maxSize)
        {
            elements[currentIndex] = element;
            currentIndex++;
        } else {
            cout<<"Tablica jest pełna. Nie można dodać więcej elementów."<<endl;
        }
    };
    T getElementAtIndex(int index)
    {
        if (index >= 0 && index < currentIndex) {
            return elements[index];
        } else {
            cout<<"Indeks poza zakresem tablicy."<<endl;
            return T();
        }
    };
};
template<>
void MyArray<string>::sortArray()
{
    sort(elements, elements + currentIndex, [](const string& a, const string& b) {
        return a.length() < b.length();
    });
}
template <>
string MyArray<string>::getMaxElement() {
    if (currentIndex == 0) {
        return "";
    }
    string maxElement = elements[0];
    for (int i = 1; i < currentIndex; i++) {
        if (elements[i].length() > maxElement.length()) {
            maxElement = elements[i];
        }
    }
    return maxElement;
}

#endif //LAB3_3_ZPO_LO_MYARRAY_H
