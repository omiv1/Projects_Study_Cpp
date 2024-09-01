#include <iostream>

int main() {
    int n;

    std::cout << "Ile rownan liniowych nalezy pobrac?: ";
    std::cin >> n;

    double tab[n][n + 1];

    for(int i = 1; i <= n ; i ++ )
    {
        tab[0][i - 1] = i;
        for(int j = 0 ; j <= n ; j ++)
        {
            std::cout << "Wpisz wartosc " << i << " rownania=";
            std::cin >> tab[i][j];

        }
        std::cout<<"\n";
    }

    std::cout << "Macierz [A \\ b ] wynosi:" << std::endl;
    for(int i = 1 ; i <= n ; i ++ )
    {
        std::cout << "|";
        for(int j = 0; j <= n ; j ++)
        {
            std::cout << tab[i][j] << " ";
        }
        std::cout << "|" << "\n";
    }

    double test;

    for(int i = 0; i < n ; i ++ ) {
        if (tab[i+1][i] != 0) {
            for (int j = i + 2; j < n + 1; j++) {
                if (tab[j][i] != 0) {
                    test = tab[j][i] / tab[i+1][i];
                    for (int k = i; k < n + 1; k++) {
                        tab[j][k] -= (test * tab[i+1][k]);
                    }
                }
            }

        }
        else
        {
            std::cout << "Nie mozna rozwiazac takiego rownania!";
            return 0;
        }
        std::cout << "\n";

        test = 0;

        for (int i = 1; i <= n; i++) {
            std::cout << "|";
            for (int j = 0; j <= n; j++) {
                std::cout << tab[i][j] << " ";
            }
            std::cout << "|" << "\n";
        }
        std::cout << "\n";
    }
    for(int i = 0 ; i < n ; i ++ )
    {
        for(int j = i ; j < n ; j ++)
        {
            tab[n-j][n] -=(test * tab[n-j][n-i]);
        }
        test = tab[n-i][n] / tab[n-i][n-1-i];
        tab[n-i][n] /= tab[n-i][n-1-i];
    }


    for(int i = 1 ; i <= n ; i ++ )
    {
        std::cout << "|";
        for(int j = 0; j <= n ; j ++)
        {
            std::cout << tab[i][j] << " ";
        }
        std::cout << "|" << "\n";
    }

    for(int i = 1 ; i < n +1; i ++ )
        std::cout << tab[i][n] << std::endl;

    return 0;
}