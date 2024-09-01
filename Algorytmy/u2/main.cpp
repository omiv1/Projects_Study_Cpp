#include <iostream>
#include "Bufor.h"
#include "MeanBufor.h"
#include "MaxBufor.h"
using namespace std;
int main() {
    //Bufor b1(10);
    MeanBufor m1(4);
    //m1.add(4);
    for(int i =0;i<m1.getSize();i++)
    {
        m1.add(i);
    }
    m1.show();
    //cout<<m1.getIndex()<<endl;
    cout<<m1.calculate()<<endl;

    MaxBufor m2(10);
    for(int i =0;i<m2.getSize();i++)
    {
        m2.add(i);
    }
    m2.setTab(5,15);
    m2.show();
    cout<<m2.calculate()<<endl;

    m2.sortt();
    m2.show();
    return 0;
}
