#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int calka,metoda;
    cout<<"ktora calka? podaj: (1,2,3)"<<endl;
    cin>>calka;
    cout<<"jak metoda? podaj: (1,2) (trapezy,simpson)"<<endl;
    cin>>metoda;
    int n;
    double a,b;
    cout<<"podaj liczbe wezlow:"<<endl;
    cin>>n;
    double x[n+1];
    double y[n+1];

    if(metoda == 1)
    {
        if(calka == 1)
        {
            a = 0;
            b = 1;
            double h = (b-a)/n;
            for(int i=0;i<=n;i++)
            {
                x[i] = a + (i*h);
                y[i] = sqrt(1+x[i]);
                //cout<<"x = "<<x[i]<<endl;
                //cout<<"y = "<<y[i]<<endl;
            }
            double suma=0;
            for(int i=0;i<=n-1;i++)
            {
                //cout<<"p = "<<((y[i]+y[i+1])*h)<<endl;
                suma = suma + ((y[i]+y[i+1])*h);
            }
            suma = suma / 2;
            cout<<"calka wynosi: "<<suma<<endl;

        }
        if(calka == 2)
        {
            a = 0;
            b = 2* M_PI;
            double h = (b-a)/n;
            cout<<"h = "<<h<<endl;
            for(int i=0;i<=n;i++)
            {
                x[i] = a + (i*h);
                y[i] = sin(x[i]);
                y[i] = pow(y[i],2) + 2;
                cout<<"x = "<<x[i]<<endl;
                cout<<"y = "<<y[i]<<endl;
            }
            double suma=0;
            for(int i=0;i<=n-1;i++)
            {
                cout<<"p = "<<((y[i]+y[i+1])*h)<<endl;
                suma = suma + ((y[i]+y[i+1])*h);
            }
            suma = suma / 2;
            cout<<"calka wynosi: "<<suma<<endl;
        }
        if(calka == 3)
        {
            a = 0;
            b = 2;
            double h = (b-a)/n;
            cout<<"h = "<<h<<endl;
            for(int i=0;i<=n;i++)
            {
                x[i] = a + (i*h);
                y[i] = sin(x[i]);
                y[i] = pow(M_E,x[i])*2* pow(x[i],3);
                cout<<"x = "<<x[i]<<endl;
                cout<<"y = "<<y[i]<<endl;
            }
            double suma=0;
            for(int i=0;i<=n-1;i++)
            {
                cout<<"p = "<<((y[i]+y[i+1])*h)<<endl;
                suma = suma + ((y[i]+y[i+1])*h);
            }
            suma = suma / 2;
            cout<<"calka wynosi: "<<suma<<endl;
        }
    }
    if(metoda == 2)
    {
        if(calka == 1)
        {
            a = 0;
            b = 1;
            double h = (b-a)/n;
            cout<<"h = "<<h<<endl;
            for(int i=0;i<=n;i++)
            {
                x[i] = a + (i*h);
                y[i] = sqrt(1+x[i]);
                //cout<<"x = "<<x[i]<<endl;
                //cout<<"y = "<<y[i]<<endl;
            }
            double suma=0;
            suma += y[0];
            suma += y[n];
            for(int i=1;i<=n-1;i++)
            {
                //cout<<"p = "<<((y[i]+y[i+1])*h)<<endl;

                if(i%2 == 0) suma += 2*y[i];
                if(i%2 != 0) suma += 4*y[i];
            }
            suma = suma * h;
            suma = suma / 3;
            cout<<"calka wynosi: "<<suma<<endl;

        }
        if(calka == 2)
        {
            a = 0;
            b = 2*M_PI;
            double h = (b-a)/n;
            cout<<"h = "<<h<<endl;
            for(int i=0;i<=n;i++)
            {
                x[i] = a + (i*h);
                y[i] = sin(x[i]);
                y[i] = pow(y[i],2) + 2;
                //cout<<"x = "<<x[i]<<endl;
                //cout<<"y = "<<y[i]<<endl;
            }
            double suma=0;
            suma += y[0];
            suma += y[n];
            for(int i=1;i<=n-1;i++)
            {
                //cout<<"p = "<<((y[i]+y[i+1])*h)<<endl;

                if(i%2 == 0) suma += 2*y[i];
                if(i%2 != 0) suma += 4*y[i];
            }
            suma = suma * h;
            suma = suma / 3;
            cout<<"calka wynosi: "<<suma<<endl;
        }
        if(calka == 3)
        {
            a = 0;
            b = 2;
            double h = (b-a)/n;
            cout<<"h = "<<h<<endl;
            for(int i=0;i<=n;i++)
            {
                x[i] = a + (i*h);
                y[i] = sin(x[i]);
                y[i] = pow(M_E,x[i])*2* pow(x[i],3);
                //cout<<"x = "<<x[i]<<endl;
                //cout<<"y = "<<y[i]<<endl;
            }
            double suma=0;
            suma += y[0];
            suma += y[n];
            for(int i=1;i<=n-1;i++)
            {
                //cout<<"p = "<<((y[i]+y[i+1])*h)<<endl;

                if(i%2 == 0) suma += 2*y[i];
                if(i%2 != 0) suma += 4*y[i];
            }
            suma = suma * h;
            suma = suma / 3;
            cout<<"calka wynosi: "<<suma<<endl;
        }


    }
}
