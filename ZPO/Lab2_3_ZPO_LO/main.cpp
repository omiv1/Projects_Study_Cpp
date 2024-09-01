#include <iostream>
#include "Bufor.h"
#include "MeanBufor.h"
#include "MaxBufor.h"

using namespace std;
int main() {
    Bufor* buf1 = new MeanBufor(5);
    Bufor* buf2 = new MaxBufor(5);

    buf1->add(10);
    buf1->add(20);
    buf1->add(30);
    buf1->add(40);
    buf1->show();
    buf2->add(20);
    buf2->add(15);
    buf2->add(65);
    buf2->add(35);
    buf2->add(45);
    buf2->show();
    buf2->add(55);
    buf2->show();
    cout << "MeanBufor Calculate: " << buf1->calculate() << endl;
    cout << "MaxBufor Calculate: " << buf2->calculate() << endl;

    delete buf1;
    delete buf2;
    return 0;
}
