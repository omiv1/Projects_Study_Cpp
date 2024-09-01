#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Funkcja obliczająca sumę cyfr w liczbie całkowitej
int sum_of_digits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

// Funkcja obliczająca liczbę cyfr w liczbie całkowitej
int count_digits(int number) {
    int count = 0;
    while (number != 0) {
        count++;
        number /= 10;
    }
    return count;
}

int main() {
    vector<int> numbers = {123, 45, 789, 12, 4567, 89, 12345, 6789};

    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return sum_of_digits(a) < sum_of_digits(b);
    });

    cout << "Sortowanie rosnaco wedlug sumy cyfr:" << endl;
    for_each(numbers.begin(), numbers.end(), [](int number) {
        cout << number << " ";
    });
    cout << endl;

    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return count_digits(a) > count_digits(b);
    });

    cout << "Sortowanie malejaco wedlug liczby cyfr:" << endl;
    for(int number : numbers)
    {
        cout << number << " ";
    }

    return 0;
}
