#include <iostream>

using namespace std;
class CSet
{
private:
    int bufor[100];
    int index;
public:
    CSet()
    {
        index = 0;
        bufor[index] = 0;
    }
    virtual ~CSet()
    {

    }
    void add(int value)
    {
        bufor[index]=value;
        index++;
    }
    virtual double calculate()=0;
    int getIndex()
    {
        return index;
    }
    int getTab(int i)
    {
        return bufor[i];
    }
};
class CSetMean: public CSet
{
public:
    double calculate()
    {
        int pom=0;
        for (int i=0;i<getIndex();i++)
        {
            pom=pom+getTab(i);
        }
        return double(pom)/(getIndex());
    }
};
class CSetMax: public CSet
{
public:
    double calculate()
    {
        int pom=getTab(0);
        for(int i=0;i<getIndex();i++)
        {
            if(pom<getTab(i)) pom=getTab(i);
        }
        return pom;
    }
    void add(int value)
    {
        if(getIndex()>100)
        {
            this->add(value);
        }
        else
        {
            cout<<"brak miejsca w tablicy"<<endl;
        }
    }
};

int main()
{
    CSet ***tab;
    tab = new CSet**[8];
    for(int k=0;k<8;k++)
{
    tab[k] = new CSet*[4];
    for(int i=0;i<2;i++)
    {
        tab[k][i] = new CSetMean();
        for(int j=0;j<5;j++)
        {
            tab[k][i]->add(j);
        }
        cout<<tab[k][i]->calculate()<<endl;
    }
    for(int i=2;i<4;i++)
    {
        tab[k][i] = new CSetMax();
        for(int j=0;j<5;j++)
        {
            tab[k][i]->add(j);
        }
        cout<<tab[k][i]->calculate()<<endl;
    }
}
}
