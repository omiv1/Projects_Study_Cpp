#include <iostream>

//using namespace std;
namespace space1
{
    class Class1
    {
    private:
        int number1;
    public:
        Class1(int liczba)
        {
            number1=liczba;
        }
        void show()
        {
            std::cout<<"space1 "<<number1<<std::endl;
        }
    };
}
namespace space2
{
    class Class1
    {
    private:
        int number1;
    public:
        Class1(int liczba)
        {
            number1=liczba;
        }
        void show()
        {
            std::cout<<"space2 "<<number1<<std::endl;
        }
    };
}

int main()
{
    using namespace space1;
    {
    Class1 c1(10);
    c1.show();
    }

    using namespace space2;
    space2::Class1 c2(15);
    c2.show();
    return 0;
}
