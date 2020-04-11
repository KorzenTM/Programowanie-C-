#include <iostream>

class Wektor    // wersja 0.3, okrojona
{
public:
    size_t m_rozmiar;
    int *  m_ptab;

    Wektor(size_t n)
    : m_rozmiar(n), m_ptab(new int[n])
    {
        for (size_t i = 0; i < m_rozmiar; i++ )
            m_ptab[i] = 0;
    }

    ~Wektor() { delete [] m_ptab; }

    size_t size() const     { return m_rozmiar; }

    int & at(int n)         { return m_ptab[n]; }
    int   at(int n) const   { return m_ptab[n]; }
    int & operator[](int n)         { return m_ptab[n]; }
    int   operator[](int n) const   { return m_ptab[n]; }

    void operator= (Wektor const& wek)
    {
        if (this == &wek)               // jeżeli kopiujemy obiekt na samego siebie...
            return;                     // to nie mamy co robić!

        if(this->m_rozmiar != wek.m_rozmiar)                   // jeśli rozmiary wektorów są różne
        {
            delete [] m_ptab;                                  // zwolnienie pamięci
            this->m_rozmiar = wek.m_rozmiar;                   // skopiowanie rozmiaru
            this->m_ptab = new int [this->m_rozmiar];          // rezerwacja pamięci
        }
        for (size_t i = 0; i < this->m_rozmiar; i++)           // skopiowanie danych
            this->m_ptab[i] = wek.m_ptab[i];
    }
};

int main()
{
    const int size = 10;
    Wektor w(size);

    for (int i = 0; i < size; i++)
        std:: cout << "Wartosc w[" << i << "] = " << w[i] << std:: endl;

    return 0;
}
