#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
T znajdzMinimalnyElement(const T* tablica, int rozmiar) {

    return *min_element(tablica, tablica + rozmiar);
}

int main() {
    int tablicaInt[] = {5, 2, 9, 1, 7};
    int rozmiarInt = sizeof(tablicaInt) / sizeof(tablicaInt[0]);

    double tablicaDouble[] = {3.14, 2.71, 1.618, 0.577};
    int rozmiarDouble = sizeof(tablicaDouble) / sizeof(tablicaDouble[0]);

    int minInt = znajdzMinimalnyElement(tablicaInt, rozmiarInt);
    cout << "Minimalny element w tablicy int: " << minInt << endl;

    double minDouble = znajdzMinimalnyElement(tablicaDouble, rozmiarDouble);
    cout << "Minimalny element w tablicy double: " << minDouble << endl;

    return 0;
}
