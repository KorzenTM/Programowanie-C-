#ifndef MAIN_STOS_H
#define MAIN_STOS_H
#include <cstdlib>
#include <cassert>
#include <iostream>

template<typename T>
struct Ogniwo
{
    Ogniwo(T n, Ogniwo *p)
    :_dane(n), _p_nastepny(p)
    {}

    T _dane;
    Ogniwo<T> *_p_nastepny; //rekurenycjna struktura danych
};

template<typename T>
class Stos
{
    template<typename U>
    friend std:: ostream& operator<< (std::ostream &, Stos<U> &);
public:
    Stos (); //konstruktor domyślny
    Stos(Stos const&); //konstruktor kopiujący
    ~Stos(); //destruktor

    void push(T i); //dokłada liczbę na stos
    void pop(); //zdejmuje liczbę ze stosu
    void reverse(); //
    T top()const; //udostępnia wartość liczby na szczycie stosu
    T& top(); //udostępnia referencję do liczby na szczycie stosu
    bool empty() const; //czy stos jest pusty?
    size_t size() const; //bieżacy rozmiar logiczny stosu
    Stos& operator=(Stos const&); //operator przypisania
private:
    Ogniwo<T>* _pSzczyt; //wskaznik na ogniwo leżące na szczycie stosu
    size_t _size; //rozmiar stosu
};

template<typename T>
inline Stos<T>::Stos()
:_pSzczyt(0), _size(0)
{}

template<class T>
inline bool Stos<T>::empty() const {return _pSzczyt == 0;}
template<class T>
inline void Stos<T>::push(T n)
{
    _pSzczyt = new Ogniwo<T>(n, _pSzczyt);
    _size++;
}

template<class T>
inline void Stos<T>::pop()
{
    assert(!empty());
    Ogniwo<T> * temp = _pSzczyt;
    _pSzczyt = _pSzczyt->_p_nastepny;
    delete temp;
    _size--;
}

template<class T>
inline T Stos<T>::top() const
{
    assert(!empty());
    return _pSzczyt->_dane;
}
template<class T>
inline T& Stos<T>::top()
{
    assert(!empty());
    return _pSzczyt->_dane;
}

#endif //MAIN_STOS_H

