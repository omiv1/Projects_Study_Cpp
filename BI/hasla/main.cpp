#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Funkcja generująca hasła
void generatePasswords(int length, int mode)
{
    // Ustalanie liczby możliwych znaków na podstawie trybu działania
    string allowed_chars;
    if (mode == 1) {
        allowed_chars = "abcdefghijklmnopqrstuvwxyz"; // tylko małe litery
    } else if (mode == 2) {
        allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // małe i duże litery
    } else {
        allowed_chars = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"; // znaki ASCII od 32 do 126
    }

    int num_chars = allowed_chars.length();
    int num_passwords = pow(num_chars, length);

    // Przygotowywanie bufora na hasła
    const int BUFFER_SIZE = 1024 * 1024; // 1 MB
    const int PASSWORD_LENGTH = length + 1; // długość hasła + znak nowej linii
    char buffer[BUFFER_SIZE];
    int index = 0;

    // Generowanie haseł i zapisywanie ich w buforze
    auto start = high_resolution_clock::now(); // początek pomiaru czasu
    for (int i = 0; i < num_passwords; i++) {
        // Konwersja liczby na system o podstawie num_chars
        int value = i;
        for (int j = 0; j < length; j++) {
            buffer[index++] = allowed_chars[value % num_chars];
            value /= num_chars;
        }
        buffer[index++] = '\n'; // dodawanie znaku nowej linii

        // Zapisywanie hasła do pliku, gdy bufor jest pełny
        if (index >= BUFFER_SIZE - PASSWORD_LENGTH) {
            ofstream file("passwords.txt", ios::app); // otwieranie pliku do dopisywania
            file.write(buffer, index);
            file.close();
            index = 0;
        }
    }

    if (index > 0) {
        ofstream file("passwords.txt", ios::app);
        file.write(buffer, index);
        file.close();
    }
    auto stop = high_resolution_clock::now(); // koniec pomiaru czasu
    auto duration = duration_cast<milliseconds>(stop - start); // obliczanie czasu działania funkcji w milisekundach
    cout << "Czas wykonywania funkcji: " << duration.count() << " ms" << endl;

}

int main()
{
    // Przykładowe wywołanie funkcji
    generatePasswords(5, 3); // generowanie haseł o długości 4, składających się tylko z małych i dużych liter

    return 0;
}
