#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <regex>

using namespace boost::algorithm;
using namespace std;

void zadanie1() {
    string line = "programowanie";
    cout << line << endl;
    to_upper(line);
    cout << "To_upper: " << line << endl;
    line = to_lower_copy(line);
    cout << "To_lower: " << line << endl;
    cout << "Erase_first: "
         << erase_first_copy(line, "o") << endl;
    cout << "Erase_all:" << erase_all_copy(line, "o") << endl;
    cout << "Replace_first: "
         << replace_first_copy(line, "p", "P") << endl;
    cout << "replace_all: "
         << replace_all_copy(line, "o", "-O-") << endl;
    vector<string> vec{"Programowanie", "w", "C++"};
    cout << "Join: " << join(vec, " ") << endl;
    string s = " Programowanie w C++ ";
    cout << s << endl;
    cout << "Trim: " << "_" << trim_copy(s) << "_" << endl;
    s = "---Programowanie w C++---";
    cout << s << endl;
    cout << "Trim_if is_any_of: "
         << trim_copy_if(s, is_any_of("-")) << endl;
    s = "123Programowanie w C++12";
    cout << s << endl;
    cout << "Trim if digit: " << trim_copy_if(s, is_digit()) << endl;
    s = "Programowanie w C++";
    cout << s << endl;
    cout << "Ends_with: " << ends_with(s, "C++") << endl;
    cout << "Contains: " << contains(s, "gram") << endl;
    s = "Programowanie w C++";
    cout << s << endl;
    vector<string> vec1;
    split(vec1, s, is_space());
    cout << "Zawartosc vectora: " << endl;
    for (int i = 0; i < vec1.size(); i++)
        cout << vec1[i] << endl;

    typedef boost::tokenizer
            <boost::char_separator<char>> tokenizer;
    s = "Programowanie w C++";
    boost::char_separator<char> sep{" "};
    tokenizer tok{s, sep};
    cout << s << endl;
    for (tokenizer::iterator it = tok.begin();
         it != tok.end(); ++it)
        cout << *it << endl;
}

void zadanie2() {
    string line = "Programowanie w C++";
    if (regex_match(line, regex("(Prog)(.*)")))
        cout << "Znaleziono" << endl;
    else
        cout << "Nie znaleziono!" << endl;
    regex regPattern("(Prog)(.*)");
    if (regex_match(line, regPattern))
        cout << "Znaleziono" << endl;
    else
        cout << "Nie znaleziono!" << endl;
    if (regex_match(line.begin(), line.end(), regPattern))
        cout << "Znaleziono" << endl;
    else
        cout << "Nie znaleziono!" << endl;
    smatch res;
    regPattern = "(Prog)(.*)";
    regex_match(line, res, regPattern);
    cout << "Regex_match: " << endl;
    cout << "Czy znaleziony? " << res.size() << endl;
    if (res.size() != 0)
        cout << "Wzorzec: " << res[0] << " zostal znaleziony" << endl;
    cout << endl << "Porownanie match i search" << endl;
    line = "*******Programowanie w C++********";
    regPattern = "(Prog)(.*)";
    regex_match(line, res, regPattern);
    cout << "Regex_match: " << endl;
    cout << "Czy znaleziony? " << res.size() << endl;
    if (res.size() != 0)
        cout << "Wzorzec: " << res[0] << " zostal znaleziony" << endl;
    regex_search(line, res, regPattern);
    cout << "Regex_search: " << endl;
    cout << "Liczba dopasowan:" << res.size() << endl;
    cout << "res.str(): " << res.str() << endl;
    cout << "res.length(): " << res.length() << endl;
    cout << "res.position(): " << res.position() << endl;
    cout << "res.prefix: " << res.prefix().str() << endl;
    cout << "res.suffix: " << res.suffix().str() << endl;
    cout << endl;
    cout << "Podgrupy ver1:" << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << "[" << res[i] << "] ";
        cout << "res.str(): " << res.str(i) << endl;
        cout << "res.position(): " << res.position(i) << endl;
        cout << "res.dl: " << res.length(i) << endl;
        cout << endl;
    }
    cout << "Podgrupy ver2:" << endl;
    for (auto pos = res.begin(); pos != res.end(); pos++) {
        cout << "[" << *pos << "] ";
        cout << "dl: " << pos->length() << endl;
    }
    cout << endl << "Replace: " << endl;
    line = "*******Programowanie w C++********";
    regPattern = "(C\\+{2})";
    cout << "Przed replace: " << line << endl;
    line = regex_replace(line, regPattern, "Java");
    cout << "Po replace: " << line << endl;

}

void zadanie10_1()
{
    regex pattern("^[+-]?\\d+(\\.\\d+)?$");

    string test1 = "+6.789";
    string test11 = "6";
    string test12 = "66";
    string test13 = ".788";
    string test2 = "-7.234";
    string test3 = "abc123";

    cout << test1 << ": " << (regex_match(test1, pattern) ? "Pasuje" : "Nie pasuje") << endl;
    cout << test11 << ": " << (regex_match(test11, pattern) ? "Pasuje" : "Nie pasuje") << endl;
    cout << test12 << ": " << (regex_match(test12, pattern) ? "Pasuje" : "Nie pasuje") << endl;
    cout << test13 << ": " << (regex_match(test13, pattern) ? "Pasuje" : "Nie pasuje") << endl;
    cout << test2 << ": " << (regex_match(test2, pattern) ? "Pasuje" : "Nie pasuje") << endl;
    cout << test3 << ": " << (regex_match(test3, pattern) ? "Pasuje" : "Nie pasuje") << endl;
}
void zadanie10_2()
{
    regex pattern("^([01]\\d|2[0-3]):[0-5]\\d(:[0-5]\\d)?$");

    string input;
    cout << "Podaj godzine: ";
    cin >> input;

    if (regex_match(input, pattern)) {
        cout << "Podany zapis godziny jest poprawny\n";
    } else {
        cout << "Blad: Niepoprawny zapis godziny\n";
    }
}

int main() {
    //zadanie1();
    //zadanie2();
    //zadanie10_1();
    zadanie10_2();
    return 0;
}
