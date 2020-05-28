#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <chrono>
#include <unordered_map>

int main()
{
    const int n = 100000;
    int licznik_znalezionych = 0;
    int licznik_nie_znalezionych = 0;

    std::unordered_map<std::string, int> slownik;

    auto start = std::chrono::steady_clock::now();
    for(int i = 1; i <= n; ++i)
    {
        std::ostringstream oss;
        oss << i;
        slownik[oss.str()] = i;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Czas wykonanania operacji wstawiania = " << elapsed_seconds.count() << "\n";

    auto start_2 = std::chrono::steady_clock::now();
    int key = 1;
    for(std::unordered_map<std::string, int>::iterator iter = slownik.begin(); iter != slownik.end(); ++iter)
    {
        std:: ostringstream oss;
        oss << key;
        auto search = slownik.find(oss.str());
        if (search != slownik.end())
        {
            licznik_znalezionych++;
        }
        else licznik_nie_znalezionych++;
        key++;
    }
    auto end_2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds_2 = end_2 - start_2;
    std::cout << "Czas wykonanania operacji odczytywania = " << elapsed_seconds_2.count() << "\n";
    std::cout << "Znaleziono kluczy ->" << licznik_znalezionych << "\n";
    std::cout << "Nie znaleziono ->" << licznik_nie_znalezionych << "\n";
}
