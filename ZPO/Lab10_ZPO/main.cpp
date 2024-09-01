#include <iostream>
#include <algorithm>

using namespace std;


void print(char x) {
    cout << x << "|";
}

char toUpper(char ch) {
    if ((ch >= 'a' and ch <= 'z')) return ch - 32;

}

int main() {
    string line1 = "Programowanie";
    string line2("Programowanie");

    cout << "Podaj slowo: " << endl;
    cin >> line1;
    cin.clear();
    cin.ignore();
    cout << "Wczytane slowo: " << line1 << endl;
    getline(cin, line2);
    cout << "Zdanie: " << line2 << endl;
    if (line1 == line2)
        cout << "Napisy sa takie same" << endl;
    else
        cout << "Napisy roznia sie" << endl;
    line1 = line1 + " " + line2;
    cout << "Napis: " << line1 << endl;
    cout << "Druga litera: " << line1[1] << endl;
    cout << "Napis w for: " << endl;
    for (int i = 0; i < line1.length(); i++) {
        cout << line1[i];
    }
    cout << endl;
    line1.append(" i psa");
    cout << "Napis po append: " << line1 << endl;
    int ind = line1.find('a');
    cout << "Pierwsze wystapienie znkau 'a' " << ind << endl;
    ind = line1.find('a', 7);
    cout << "Pierwsze wystapienie znkau 'a' po 7 pozycji "
         << ind << endl;
    ind = line1.find_last_not_of("kgtoa");
    cout << "Ostatnie wystepienie litery ktora nie jest kgtoa:" << ind << endl;
    line2 = line1.substr(0, 3);
    cout << "Substr(0,3): " << line2 << endl;
    line1.insert(line1.begin(), '*');
    line1.push_back('*');
    cout << "Napis po insert i push_back: " << line1 << endl;
    for (string::iterator it = line1.begin();
         it != line1.end(); it++)
        cout << *it;
    string::iterator del;
    del = line1.erase(line1.begin() + 0, line1.begin() + 5);
    cout << *del << endl;
    cout << "Napis po erase: " << line1 << endl;

    cout << "Transform" << endl;
    line1 = "Cos";
    transform(line1.begin(), line1.end(), line1.begin(), toUpper);
    cout << line1 << endl;
    cout << "find" << endl;
    del = find(line1.begin(), line1.end(), 'K');
    cout << *del << endl;
    cout << "for_each" << endl;
    for_each(line1.begin(), line1.end(), print);
    return 0;
}
