#include <iostream>

using namespace std;

class CStudent
{
private:
    int id;
    string name;
public:
    CStudent(int id,string name)
    {
        this->id=id;
        this->name=name;
    }
    void setid(int id)
    {
        this->id=this->id+id;
    }
    void setname(string name)
    {
        this->name=this->name+name;
    }
    int getid()
    {
        return id;
    }
    string getname()
    {
        return name;
    }
    void show()
    {
        cout<<"id: "<<id<<" name: "<<name<<endl;
    }
};
class CNumeber
{
private:
    static int number;
public:
    static void next()
    {
        number=number+1;
    }
    static int getnumber()
    {
        return number;
    }
};
int CNumeber::number=0;
int main()
{
    CStudent *s[30];
    for(int i=0;i<30;i++)
    {
        s[i]=new CStudent(CNumeber::getnumber(),"nazwa");
        s[i]->show();
        CNumeber::next();
    }
}
