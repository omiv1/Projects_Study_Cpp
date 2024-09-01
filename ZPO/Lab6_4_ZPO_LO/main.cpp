#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>

// Przykładowa implementacja klasy Fusion
class Fusion {
public:
    // Implementacja klasy Fusion...
};

// Funkcja zliczająca wystąpienia różnych typów w wektorze Fusion
std::map<std::string, int> countTypes(const std::vector<Fusion>& fusionVector) {
    std::map<std::string, int> typeCounts;

    for (const auto& item : fusionVector) {
        // Uzyskaj nazwę typu przy użyciu typeid
        std::string typeName = typeid(item).name();

        // Zwiększ licznik dla danego typu w mapie
        typeCounts[typeName]++;
    }

    return typeCounts;
}

int main() {
    // Przykładowy wektor Fusion
    std::vector<Fusion> fusionVector = {Fusion(), Fusion(), Fusion(), Fusion(), Fusion(), Fusion()};

    // Wywołaj funkcję countTypes
    std::map<std::string, int> result = countTypes(fusionVector);

    // Wyświetl wyniki
    std::cout << "Counts of different types:" << std::endl;
    for (const auto& pair : result) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
