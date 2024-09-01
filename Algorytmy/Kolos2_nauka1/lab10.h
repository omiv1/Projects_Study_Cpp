#include <iostream>
#include <fstream>
#include <regex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Osoba {
public:
    std::string imie, nazwisko, wiek, numerTelefonu, email;

    Osoba(const std::string& imie, const std::string& nazwisko, const std::string& wiek,
          const std::string& numerTelefonu, const std::string& email)
            : imie(imie), nazwisko(nazwisko), wiek(wiek), numerTelefonu(numerTelefonu), email(email) {}

    // Funkcja wypisująca dane osoby w formacie do zapisu
    void wypisz(std::ofstream& plik) const {
        plik << imie << ";" << nazwisko << ";" << wiek << ";" << numerTelefonu << ";" << email << std::endl;
    }
};

void lab10_0() {
    std::string tekst = "abc123def456ghi789";
    std::regex wzorzec("\\d+");  // Dopasowanie ciągu cyfr
    std::cout<< "Tekst: " << tekst << std::endl;
    std::smatch dopasowanie;
    if (std::regex_search(tekst, dopasowanie, wzorzec)) {
        std::cout << "Znaleziono dopasowanie w tekście." << std::endl;
        std::cout << "Dopasowany fragment: " << dopasowanie.str() << std::endl;
        std::cout << "Pozycja dopasowania: " << dopasowanie.position() << std::endl;
    } else {
        std::cout << "Nie znaleziono dopasowania w tekście." << std::endl;
    }

    string t;
    cin>>t;
    string r = "^\\d+$";
    if (regex_match(tekst, regex(r)))
    {
        cout<<"Tak";
    }
    else
    {
        cout<<"Nie";
    }

}
void lab10_4() {
    std::vector<Osoba> osoby;

    // Wczytywanie danych od użytkownika
    std::cout << "Podaj imie: ";
    std::string imie;
    std::cin >> imie;

    // Sprawdzenie imienia za pomocą wyrażenia regularnego
    std::regex wzorzecImienia("[A-Za-z]+");
    if (!std::regex_match(imie, wzorzecImienia)) {
        std::cerr << "Nieprawidlowe imie." << std::endl;
    }

    // Analogicznie sprawdz pozostałe dane (nazwisko, wiek, numerTelefonu, email) używając odpowiednich wyrażeń regularnych

    // Dodaj osobę do wektora osoby
    Osoba nowaOsoba(imie, "nazwisko", "8", "9", "email");
    osoby.push_back(nowaOsoba);

    // Zapisz dane do pliku
    std::ofstream plik("danex.csv", std::ios::app);  // Otwarcie pliku do dopisywania
    if (plik.is_open()) {
        nowaOsoba.wypisz(plik);  // Zapisz dane nowej osoby do pliku
        plik.close();  // Zamknij plik
    } else {
        std::cerr << "Blad przy otwieraniu pliku." << std::endl;

    }

    // Wyświetlanie informacji statystycznych
    std::unordered_set<std::string> unikatoweDomeny;
    std::unordered_set<std::string> numeryTelefonowParzyste;
    std::unordered_set<std::string> nazwiskaLaczone;
    std::unordered_map<std::string, int> statystykaImion;

    // Odczytaj dane z pliku i wykonaj odpowiednie operacje
    std::ifstream odczytPliku("dane.csv");
    if (odczytPliku.is_open()) {
        std::string linia;
        while (std::getline(odczytPliku, linia)) {
            std::istringstream ss(linia);
            std::string token;

            std::getline(ss, token, ';');  // Imie
            std::string imieOsoby = token;

            std::getline(ss, token, ';');  // Nazwisko
            std::string nazwiskoOsoby = token;

            std::getline(ss, token, ';');  // Wiek
            std::string wiekOsoby = token;

            std::getline(ss, token, ';');  // Numer telefonu
            std::string numerTelefonuOsoby = token;

            std::getline(ss, token, ';');  // Email
            std::string emailOsoby = token;

            // Statystyki dla unikatowych domen
            size_t pozycjaKropki = emailOsoby.find_last_of('.');
            if (pozycjaKropki != std::string::npos) {
                std::string domena = emailOsoby.substr(pozycjaKropki + 1);
                unikatoweDomeny.insert(domena);
            }

            // Statystyki dla numerów telefonów parzystych
            int ostatniaCyfra = numerTelefonuOsoby.back() - '0';
            if (ostatniaCyfra % 2 == 0) {
                numeryTelefonowParzyste.insert(numerTelefonuOsoby);
            }

            // Statystyki dla nazwisk łączonych
            if (nazwiskoOsoby.find('-') != std::string::npos) {
                nazwiskaLaczone.insert(nazwiskoOsoby);
            }

            // Statystyki dla imion
            statystykaImion[imieOsoby]++;
        }

        odczytPliku.close();
    } else {
        std::cerr << "Blad przy otwieraniu pliku do odczytu." << std::endl;

    }

    // Wyświetlanie wyników
    std::cout << "Unikatowe domeny email: ";
    for (const auto& domena : unikatoweDomeny) {
        std::cout << domena << " ";
    }
    std::cout << std::endl;

    std::cout << "Numery telefonow parzyste: ";
    for (const auto& numer : numeryTelefonowParzyste) {
        std::cout << numer << " ";
    }
    std::cout << std::endl;

    std::cout << "Nazwiska laczone: ";
    for (const auto& nazwisko : nazwiskaLaczone) {
        std::cout << nazwisko << " ";
    }
    std::cout << std::endl;

    std::cout << "Statystyka imion:" << std::endl;
    for (const auto& entry : statystykaImion) {
        std::cout << entry.first << ": " << entry.second << " wystapien" << std::endl;
    }
}