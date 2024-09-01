#include "BufferArr.h"

using namespace std;

BufferArr::BufferArr(int bufferSize) : size(bufferSize), count(0) {
    array = new int[size];
    cout << "Konstruktor klasy BufferArr" << endl;
}

BufferArr::~BufferArr() {
    delete[] array;
    cout << "Destruktor klasy BufferArr" << endl;
}

void BufferArr::add(int a) {
    if (count < size) {
        array[count++] = a;
    } else {
        cout << "Tablica jest pelna. Nie mozna dodac elementu." << endl;
    }
}

void BufferArr::write() {
    cout << "Elementy tablicy BufferArr:" << endl;
    for (int i = 0; i < count; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int BufferArr::getSize() const {
    return size;
}

void BufferArr::setSize(int newSize) {
    size = newSize;
}

int BufferArr::getCount() const {
    return count;
}

void BufferArr::setCount(int newCount) {
    count = newCount;
}
