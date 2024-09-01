#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(-100, 100);

    int n = abs(dis(gen));
    cout << "Wylosowana liczba n: " << n << endl;

    vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        int number = dis(gen);
        if(number >= 0)
        {
            numbers.insert(numbers.begin(),number);
        }
        else
        {
            numbers.push_back(number);
        }
    }
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;
    return 0;
}
