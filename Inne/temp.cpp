#include <iostream>

using namespace std;

template <typename T>
T fun(T a,T b)
{
	
}
float fun(int a,int b)
{
	cout<<(a+6)/b<<endl;
	return a;
}

int main()
{
	fun(4.0,5.0);
}
