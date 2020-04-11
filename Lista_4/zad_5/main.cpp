#include <iostream>

class Samochod
{
private:
    int _sruby;
    int _kola;
public:
    Samochod (int n)
            : _kola (n) //_kola nie jest w tym miejscu zainicjowana - zmiana na n albo przeniesienie przypisania poniżej
    {
        _sruby = 4*_kola;
        std::cout << "Samochod z " << _kola <<  " kolami i "
                  << _sruby << " srubami\n";
    }

};

int main()
{
    Samochod s4 (4);
    Samochod s12 (12);
}