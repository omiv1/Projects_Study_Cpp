#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream in("C://Users//lukas//CLionProjects//bazy");
    ofstream out("wynik.txt");
    string linia;
    for(int i=0;i<110;i++)
    {
        in>>linia;
        cout<<linia<<endl;
    }
    in.close();
    out.close();
    return 0;
}
