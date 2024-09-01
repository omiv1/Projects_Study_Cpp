#include <iostream>
#include <cmath>

int znak(double liczba)
{
    if (liczba>0) return 1;
    else return -1;
}

using namespace std;
int main()
{
    double x1,x2;
    int a,b,c;
    cin>>a>>b>>c;
    cout<<a<<"x^2 + "<<b<<"x + "<<c<<endl;
    x1 = (-b/(2*a)) + (znak(-b/(2*a)) * sqrt(((b/(2*a))*(b/(2*a)))-(c/a)));
    x2 = c/(a*x1);
    cout<<"x1 = "<<x1<<endl<<"x2 = "<<x2;


    return 0;
}
