#include <iostream>
#include <regex>

int main() {
    std::string t;
    std::cin >> t;
    
    std::string r = "^\\d+$";  // Dodano ^ (początek) i $ (koniec) aby sprawdzić cały ciąg
    if (std::regex_match(t, std::regex(r))) {
        std::cout << "Tak" << std::endl;
    } else {
        std::cout << "Nie" << std::endl;
    }

    return 0;
}
