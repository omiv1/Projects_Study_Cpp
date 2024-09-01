#include <iostream>
#include <algorithm>
#include "Subject.h"
#include "Student.h"

void amount_of_fail_subjects(Student<int> s)
{
    map<string,int> mapa= s.getOceny();
    int suma = count_if(mapa.begin(),mapa.end(),[](pair<string,int> para) {return para.second == 2;});
    cout<<"Ocena niedostateczna z "<<suma<<" przedmiotow"<<endl;
}

int main() {
    Subject sub1(12,"aa","vv",5,4);
    Subject sub2(15,"bb","ff",7,9);
    cout<<sub2.getAmount_of_lessons()<<endl;
    sub2.setAmount_of_lessons(12);
    cout<<sub2.getAmount_of_lessons()<<endl;
    cout<<sub2.getId()<<" < "<<sub1.getId()<<" = "<<(sub2<sub1)<<endl;
    cout<<sub1.getId()<<" < "<<sub2.getId()<<" = "<<(sub1<sub2)<<endl;

    cout<<endl<<"Dla student1 <int>:"<<endl;
    Student<int> st1("imie1","nazwisko1",1);
    st1.add("matematyka",4);
    st1.add("fizyka2",2);
    st1.add("angielski",5);
    st1.add("fizyka",2);
    st1.show_all_grades();
    amount_of_fail_subjects(st1);

    cout<<endl<<"Dla student2 <string>:"<<endl;
    Student<string> st2("imie2","nazwisko2",2);
    st2.add("matematyka","db");
    st2.add("angielski","bdb");
    st2.add("fizyka","ndst");
    st2.show_all_grades();

    cout<<endl<<"Dla student3 <int>:"<<endl;
    map<string,int> mapa;
    mapa["polski"] = 2;
    mapa["matematyka"] = 3;
    mapa["fizyka"] = 2;
    mapa["chemia"] = 2;
    Student<int> st3("imie3","nazwisko3",3,mapa);
    st3.show_all_grades();
    amount_of_fail_subjects(st3);
    return 0;
}
