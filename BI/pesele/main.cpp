#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int main()
{
    ofstream pesel_file("pesele.txt"); // otwarcie pliku do zapisu

    auto start = chrono::steady_clock::now(); // pomiar czasu początkowego

    vector<string> pesele; // wektor do przechowywania wygenerowanych numerów PESEL

    for(int rok = 1900; rok <= 2023; rok++)
    {
        for(int miesiac = 1; miesiac <= 12; miesiac++)
        {
            int dni = 31;
            if(miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11)
                dni = 30;
            else if(miesiac == 2)
            {
                if((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0)
                    dni = 29;
                else
                    dni = 28;
            }
            for(int dzien = 1; dzien <= dni; dzien++)
            {
                int suma = dzien + miesiac*100 + rok*10000;
                for(int liczba = 0; liczba <= 9999; liczba++)
                {
                    int kontrolna = (9*suma/10)%10 + (7*suma/100)%10 + (3*suma/1000)%10 + (liczba%10) + ((liczba/10)%10)*10 + ((liczba/100)%10)*100 + (liczba/1000)*1000; // obliczenie cyfry kontrolnej
                    string pesel = to_string(suma) + to_string(liczba) + to_string(kontrolna); // utworzenie numeru PESEL
                    while(pesel.length() < 11) // uzupełnienie numeru PESEL zerami na początku, jeśli jest on krótszy niż 11 znaków
                        pesel = "0" + pesel;
                    pesele.push_back(pesel); // dodanie numeru PESEL do wektora
                }
            }
        }
    }

    for(string pesel : pesele) // zapisanie wygenerowanych numerów PESEL do pliku
    {
        pesel_file << pesel << endl;
        if(pesel == "01234567891") // weryfikacja, czy w pliku znajduje się nasz PESEL
            cout << "Znaleziono PESEL: " << pesel << endl;
    }

    auto end = chrono::steady_clock::now(); // pomiar czasu końcowego
    auto diff = end - start; // obliczenie czasu trwania

    cout << "Czas generowania PESELi: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}
