#include <iostream>
#include <cmath>
using namespace std;

double funkcja(double x)
{
    return sin(x)-(x/2);
}
double pochodna(double x)
{
    return cos(x) - 0.5;
}
void newton(double e)
{
    double x = 1.2,i=0;
    while(abs(funkcja(x))>e)
    {
        i++;
        if(i>100)
        {
            cout<<"Zbyt dlugi czas obliczania"<<endl;
            break;
        }
        x = x - (funkcja(x) / pochodna(x));
        cout<<"k = "<<i<<"    x = "<<x<<"    f(x) = "<<funkcja(x)<<endl;
    }
    cout<<"Iteracji: "<<i<<endl;
    cout<<"f("<<x<<") = "<<funkcja(x)<<endl;
}
double wielomian(double x)
{
    return pow(x,4)+(5*pow(x,2))-(3*x)-15;
}
void bisekcja(int aa,int bb,double e)
{
    double s,a,b;
    a=aa;
    b=bb;
    int i=0,pom=0;
    while(pom==0)
    {
        i++;
        s = (a + b) / 2.0;
        if(abs(wielomian(s))<e)
        {
            pom=1;
        }
        if((wielomian(a)* wielomian(s))<0)
        {
            b=s;
        } else
        {
            a=s;
        }
        if(i>100)
        {
            pom=1;
        }
        cout<<"k = "<<i<<"    s = "<<s<<"    f(x) = "<<wielomian(s)<<endl;
    }
    cout<<"Iteracji: "<<i<<endl;
    cout<<"f("<<s<<") = "<< wielomian(s)<<endl;


}
int main()
{
    double e;

    //Newton
    cout<<"Podaj epsilon"<<endl;
    cin>>e;
    newton(e);
    cout<<endl;

    //Bisekcja
    cout<<"Podaj epsilon"<<endl;
    cin>>e;
    bisekcja(0,2,e);

    return 0;
}
