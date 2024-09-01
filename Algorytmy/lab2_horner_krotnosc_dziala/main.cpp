#include <iostream>

int silania(int n)
{
    int s=1;
    for(int i=1;i<=n;i++)
    {
        s = s * i;
    }
    return s;
}

using namespace std;
int main() {
    int stopien;
    cout<<"jakiego stopnia jest wielomian:";
    cin>>stopien;
    double *wielomian;
    wielomian = new double[stopien+1];
    for(int i=0;i<=stopien;i++)
    {
        cin>>wielomian[i];
    }
    cout<<"Podales wielomian:";
    for(int i=0;i<=stopien;i++)
    {
        cout<<wielomian[i]<<"x^"<<stopien-i<<" + ";
    }
    double punkt;
    cout<<endl<<"podaj punkt:";
    cin>>punkt;
    double pom = 0;
    cout<<endl;
    double pochodne[stopien];
    for(int i=0;i<=stopien;i++)
    {
        for (int j=0;j<=stopien-i;j++)
        {
            pom = punkt * pom + wielomian[j];
            wielomian[j] = pom;
        }
        //cout<<pom<<endl;
        pochodne[i]=pom;
        pom = 0;
    }
    cout<<endl;
    int ilosc=0;
    for(int i=0;i<=stopien;i++)
    {
        cout<<"pochodna rzedu: "<<i<<" w punkcie: "<<punkt<<" wynosi: ";
        cout<<pochodne[i]/silania(i)<<endl;
        if (pochodne[i]/silania(i) == 0) ilosc++;
        cout<<endl;
    }
    if(ilosc>0) cout<<"krotnosc wyniosi: "<<ilosc<<endl;
    else cout<<"podany punkt nie jest pierwiastkiem"<<endl;

    return 0;
}
