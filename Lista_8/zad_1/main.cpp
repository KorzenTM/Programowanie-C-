#include <string>
#include <iostream>
#include <sstream>

void str_to_int(std::istringstream& S)
{
    int number;
    for ( ; ;)
    {
        S >> number;
        if (S)
        {
            std::cout << number << "\n";
        }
        else if (S.eof())
            break;
        S.clear();
        S.get();
    }
    std::cout << "Koniec!" << "\n";
}

int main()
{
    std::string text = "1 2 3 4 5 6 7";
    std::istringstream G(text);
    str_to_int(G);
    return 0;
}