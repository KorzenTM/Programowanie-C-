#include "PPM_to_PGM.h"
#include <fstream>
#include <string>
#include <iostream>

PPM_to_PGM::PPM_to_PGM(const char nazwa_piku[])
{
    std::ifstream F(nazwa_piku, std::ios::binary); //'n' zajmuje 1 bajt
    std::string s; //zmienna pomocniczna
    F >> s >> std::ws; //teraz s powinno mieć wartość "P6"
    while(F.peek() == '#') //pominięcie ewentualnych komentarzy
        F.ignore(100000, '\n');
    F >> _szerokosc >> _wysokosc >> _glebia; //wczytanie parametrów obrazy
    F.ignore(100000, '\n'); //pominiecie bajtów do znaku '\n' włącznie
    _tab = new Kolor*[_wysokosc]; //przydział pamięci dla adresow wierszy
    for(int i = 0; i < _wysokosc; ++i)
    {
        _tab[i] = new Kolor[_szerokosc]; //przydział pamięci dla i-tego wiersza
        char *adres = reinterpret_cast<char*>(_tab[i]); //zmiana typu wskaźnika
        F.read(adres, sizeof(Kolor) * _szerokosc); //wczytanie i-tego wiersza
    }
}

void PPM_to_PGM::konwertuj()
{
    p = new Grey_scale*[_wysokosc];
    for (int y = 0; y < _wysokosc; ++y)
    {
        p[y] = new Grey_scale[_szerokosc];
        for(int x = 0; x < _szerokosc; x++)
        {
            auto srednia = (_tab[y][x].blue + _tab[y][x].red + _tab[y][x].green) / 3;
            p[y][x].grey = srednia;
        }
    }
}

void PPM_to_PGM::zapisz(const char nazwa_pliku[])
{
    std::ofstream F(nazwa_pliku, std::ios::binary);
    F << "P5\n" << _szerokosc << " " << _wysokosc << "\n" << _glebia << "\n";
    for(int i = 0; i < _wysokosc; ++i)
        F.write(reinterpret_cast<char*>(p[i]), _szerokosc);

    delete []p;
}

PPM_to_PGM::~PPM_to_PGM()
{
    for(int i = 0; i < _wysokosc; ++i)
    {
        delete []_tab[i];
        delete []p[i];
    }
    delete []_tab;
    delete []p;
}


