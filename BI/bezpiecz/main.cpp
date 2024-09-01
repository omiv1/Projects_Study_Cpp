#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1, s2;
    int c = 0;
    s1 = "abcdef";
    s2 = "bcdeff";
    // czy teksty mają tą samą długość?
    if (s1.length() != s2.length()) {
        cout << "różna długość" << endl;
        return 0;
    }
    // szukanie zgodnych bitów
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == s2[i]) {
            c++;
        }
    }
    cout << "liczba zgodnych bitow: " << c << endl;
    return 0;
}
