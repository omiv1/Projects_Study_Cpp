//
// Created by lukas on 03.12.2023.
//

#ifndef U3_ARRAY_H
#define U3_ARRAY_H
#include <iostream>
#include <algorithm>

using namespace  std;

template<typename T>
class Array {
private:
    T* tab;
    int size;
    int index;
public:
    Array(){
        size = 10;
        index = 0;
        for (int i = 0;i<size;i++)
        {
            tab[0] = new T;
        }
    }
    Array(int size){
        this -> size = size;
        index = 0;
        tab = new T[size];
    }
    ~Array(){
    }
    void sort_a()
    {
        sort(tab, tab + size);
    }
    T* max_a()
    {
        return max_element(tab,tab + size);
    }
    void show()
    {
        for(int i = 0;i<index;i++)
        {
            cout<<tab[i]<<" ";
        }
        cout<<endl;
    }
    void add(T value)
    {
        tab[index] = value;
        index++;
    }
    T get(int i)
    {
        return tab[i];
    }
    int getIndex()
    {
        return index;
    }
    int getSize()
    {
        return size;
    }

};

template<>
void Array<string>::sort_a() {
    sort(tab,tab + size,[](string a, string b){ return a.length() < b.length();});
}

template<>
string* Array<string>::max_a() {
    return min_element(tab,tab + size,[](string a, string b){ return a.length() < b.length();});
}

#endif //U3_ARRAY_H
