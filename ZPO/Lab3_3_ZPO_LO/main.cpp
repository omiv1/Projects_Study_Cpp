#include <iostream>
#include "MyArray.h"

using namespace  std;

int main() {

    MyArray<int> intArray(5);
    intArray.addElement(3);
    intArray.addElement(1);
    intArray.addElement(5);
    intArray.addElement(2);
    intArray.addElement(4);

    cout << "Tablica int przed sortowaniem:" << endl;
    intArray.display();

    intArray.sortArray();
    cout << "Tablica int po sortowaniu:" << endl;
    intArray.display();

    int maxInt = intArray.getMaxElement();
    cout << "Maksymalny element w tablicy int: " << maxInt << endl;

    MyArray<string> stringArray(5);
    stringArray.addElement("apple");
    stringArray.addElement("banana");
    stringArray.addElement("cherry");
    stringArray.addElement("date");
    stringArray.addElement("fig");

    cout << "Tablica string przed sortowaniem:" << endl;
    stringArray.display();

    stringArray.sortArray();
    cout << "Tablica string po sortowaniu:" << endl;
    stringArray.display();

    string maxString = stringArray.getMaxElement();
    cout << "Najdluzszy napis w tablicy string: " << maxString << endl;

    return 0;
}
