#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    string name;
    int x = rand()%100;

    cin>>name;
    if (name == "!rasist")
    {
        cout<<"Rasista "<<x<<"%"<<endl;
    }

}
