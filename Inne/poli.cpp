#include <iostream>

using namespace std;
class Person
{
protected:
    string name;
    string surname;
    int age;
    
public:
    Person(string name1, string surname1, int age1)
    {
        name=name1;
        surname=surname1;
        age=age1;
        cout<<"Konstruktor klasy bazowej - Person"<<endl;
    }
    Person()
    {
        cout<<"Konstruktor bezparametrowy klasy bazowej - Person"<<endl;
    }
    virtual void poka()=0;
    void setName(string name1)
    {
        name=name1;
    }
    void setSurname(string surname1)
    {
        surname=surname1;
    }
    void setAge(int age1)
    {
        age=age1;
    }
    string getName()
    {
        return name;
    }
    string getSurname()
    {
        return surname;
    }
    int getAge()
    {
        return age;
    }
    bool is_18()
    {
        if(age>=18)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
     virtual void show() //metoda show klasy bazowej Person
    {
        cout<<"Imie: "<<name<<" nazwisko: "<<surname<<" wiek: "<<age<<endl;
    }

    virtual~Person() // destruktor
    {
        cout<<"Destruktor Person"<<endl;
    }

};

//klasa dziedziczaca - klasa potomna
class Teacher: public Person //dziedziczenie po klasie Person
{
private:
    int experience;
    string title;
public:
    //konstruktor zawierajacy parametry klasy bazowej + swoje czyli experience i title
    //po dwukropku wywolanie klasy bazowej czyli po tej po ktorej klasa dziedziczy

    Teacher(string name1, string surname1, int age1,int experience1, string title1):Person(name1,surname1,age1)
    {
        experience=experience1;
        title=title1;
        cout<<"Konstruktor klasy pochodnej Teacher"<<endl;
    }
    Teacher()
    {
        cout<<"Konstruktor bezparametrowy klasy pochodnej Teacher"<<endl;
    }
    void setExperience(int experience1)
    {
        experience=experience1;
    }
    void setTitle(string title1)
    {
        title=title1;
    }
    int getExperience()
    {
        return experience;
    }
    string getTitle()
    {
        return title;
    }
    bool is_Phd()
    {
        if(title=="Phd")
            return true;
        else
            return false;
    }
    /*void info() //metoda show klasy pochodnej Teacher
    {
       show();
       cout<<"Staz pracy: "<<experience<<" tytul naukowy: "<<title<<endl;
    } */
 virtual void show() //metoda show klasy pochodnej Teacher
    {
       // Person::show(); //W celu wyswietlenia informacji o imieniu, nazwisku oraz wieku nauczyciela, wywolywana jest metoda show
        //z klasy {Person. Nazwy jednej i drugiej metody sa takie same wiec nalezy uzyc :: w celu okreslenia z ktorej klasy ma
        //pochodzic metoda show (przestrzen nazw)
        //jesli nie chcemy wywolywac metody klasy bazowej mozna skorzystac z getterow klasy bazowej poniewaz mamy do nich dostep

       cout<<"Imie: "<<name<<" nazwisko: "<<surname<<" wiek: "<<age<<endl;
       cout<<"Staz pracy: "<<experience<<" tytul naukowy: "<<title<<endl;
    }
   virtual ~Teacher()  //destruktor
    {
        cout<<"Destruktor Teacher"<<endl;
    }
} ;
//klasa potomna Student
class Student: public Person
{
private:
    string index;
    
public:
    Student(string name1, string surname1, int age1,string index1):Person(name1,surname1,age1)
    {
        index=index1;
        cout<<"Konstruktor klasy pochodnej Student"<<endl;
    }
    Student()
    {
        cout<<"Konstruktor bezparametrowy klasy pochodnej Student"<<endl;
    }
    void setIndex(string index1)
    {
        index=index1;
    }
    void poka()
    {
    	
	}
    string getIndex()
    {
        return index;
    }
   virtual void show()
    {
        //Person::show();
        
        cout<<Person::name<<" "<<Person::surname<<" "<<Person::age<<" "<<index<<endl;
        Person::show();
        cout<<" "<<index<<endl;
    }

    virtual ~Student() // destruktor
    {
        cout<<"Destruktor Student"<<endl;
    }

};
int main()
{
    /*Person *o=new Person("Grazyna","Nowak",45); //wskaznik na obiekt typu Person
    o->show();

    Person *o1=new Student("Pawel","Adamiak",17,"123456"); //polimorfizm
    //zmiennej typu Person* zostala zaalokowana pamiec typu Student

    Teacher n1("Barbara","Kowalska",56,30,"Phd");
    Person *o2=&n1; //polimorfizm, zmiennej typu Osoba* przypisana zostala referencja obiektu Teacher

    o1->show(); //wywolanie wirtualnych metod, obiekt o1 wywoluje metode z klasy Student
    o2->show(); //wywolanie wirtualnych metod, obiekt o2 wywoluje metode z klasy Teacher

    ((Student*)o1)->setIndex("12345666666"); //rzutowanie obiektu o1 na typ Student* w celu wywolania metody ktora nie jest wirtualna
    o1->show(); //wywolanie metody wirtualnej w celu pokazania ze nr indeksu zostal zmieniony
    cout<<((Teacher*)o2)->is_Phd()<<endl; //rzutowanie obiektu o2 na typ Teacher* w celu wywolania metody ktora nie jest wirtualna

    delete o;
    delete o1;*/
    Student s("imie","nazwisko",20,"index");
    s.show();
    //Person p("imie","naz",15);
    //p.poka();

    return 0;
}
