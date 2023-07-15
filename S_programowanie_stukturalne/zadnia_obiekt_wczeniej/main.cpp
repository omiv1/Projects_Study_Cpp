#include <iostream>

using namespace std;
class Student
{
private:
    string imie;
    string nazwizko;
    int wiek;
public:
    Student(string imie,string nazwizko,int wiek)
    {
        this->imie=imie;
        this->nazwizko=nazwizko;
        this->wiek=wiek;
    }
    Student()
    {

    }
    ~Student()
    {

    }
    string getImie()
    {
        return imie;
    }
    string getNazwisko()
    {
        return nazwizko;
    }
    int getWiek()
    {
        return wiek;
    }
    void show()
    {
        cout<<imie<<" "<<nazwizko<<" "<<wiek<<endl;
    }
};
class Kolo
{
private:
    string nazwa;
    int rozmiar;
    Student *studenci;
    int ile;
public:
    Kolo(string nazwa,int rozmiar)
    {
        this->nazwa=nazwa;
        this->rozmiar=rozmiar;
        studenci = new Student[rozmiar];
        ile=0;
    }
    ~Kolo()
    {

    }
    void add(Student s)
    {
        studenci[ile]=s;
        ile++;
    }
    void show_students()
    {
        for(int i=0;i<ile;i++)
        {
            studenci[i].show();
        }
    }
    void show()
    {
        cout<<nazwa<<" "<<ile<<endl;
    }
};
int main()
{
    Student s1("jan","kowlaski",21);
    Student s2("jana","kosdska",43);
    Student s3("krzy","kowsdki",23);
    Kolo k1("kolo1",10);
    k1.add(s1);
    k1.add(s2);
    k1.add(s3);
    s1.show();
    k1.show_students();
    k1.show();
}
