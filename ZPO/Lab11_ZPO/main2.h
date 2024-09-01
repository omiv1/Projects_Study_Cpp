#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string name1, int age1) {
        name = name1;
        age = age1;
    }

    void info() {
        cout << name << " " << age << endl;
    }
};

void funDeleter(Person *p) {
    cout << "usunieta osoba: ";
    p->info();
    delete p;
}