#include "PPMimage.h"
#include <fstream>
#include <string>
#include <cmath>

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

void PPM_to_PGM::znieksztalc(int param_x, int param_y)
{
    Kolor *p = new Kolor[_szerokosc];
    for (int y = 0; y < _wysokosc; ++y)
    {
        int dx = int(0.5 + param_x/2.0 * sin(2 * M_PI * y / param_y));
        for(int x = 0; x < _szerokosc; x++)
        {
            int index = (x+dx) % _szerokosc;
            if (index < 0)
                index += _szerokosc;
            p[x] = _tab[y][index];
        }
        std::swap(_tab[y], p);
    }
    delete [] p;
}

void PPM_to_PGM::zmiekcz()
{
    for (int y = 1; y < _wysokosc; ++y)
    {
        for(int x = 1; x < _szerokosc; x++)
        {
            _tab[y][x].red =  (_tab[y][x-1].red + _tab[y][x+1].red) / 2;
            _tab[y][x].green =  (_tab[y][x-1].green + _tab[y][x+1].green) / 2;
            _tab[y][x].blue =  (_tab[y][x-1].blue + _tab[y][x+1].blue) / 2;
        }
    }
}

void PPM_to_PGM::zapisz(const char nazwa_pliku[])
{
    std::ofstream F(nazwa_pliku, std::ios::binary);
    F << "P6\n" << _szerokosc << " " << _wysokosc << "\n" << _glebia << "\n";
    for(int i = 0; i < _wysokosc; ++i)
        F.write(reinterpret_cast<char*>(_tab[i]), 3 * _szerokosc);
}

PPM_to_PGM::~PPM_to_PGM()
{
    for(int i = 0; i < _wysokosc; ++i)
        delete []_tab[i];
    delete []_tab;
}