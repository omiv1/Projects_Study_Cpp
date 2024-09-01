#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in("plik1.txt");
    double suma = 0;
    string linia;
    while (!in.eof())
    {
        getline(in,linia);
        cout<<linia<<endl;
    }
}
