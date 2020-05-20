#include "stos.h"

template<class T>
Stos<T>::~Stos()
{
    while (!this->empty())
        this->pop();
}
template<class T>
Stos<T>::Stos(Stos const& rhs)
        :_pSzczyt(rhs._pSzczyt), _size(rhs._size)
{
    for (size_t i = 0; i < _size; i++)
        _pSzczyt[i]._dane = rhs._pSzczyt[i]._dane;
}
template<class T>
Stos<T> & Stos<T>:: operator=(const Stos &rhs)
{
    if (this == &rhs)
        return *this;
    if (_size < rhs._size)
    {
        delete _pSzczyt;
        _size = rhs._size;
        _pSzczyt = new Ogniwo<T>(rhs._pSzczyt->_dane, rhs._pSzczyt);
    }
    _size = rhs._size;
    for (size_t i = 0; i < _size; i++)
        _pSzczyt[i]._dane = rhs._pSzczyt[i]._dane;
    return *this;
}
template<class T>
void Stos<T>::reverse()
{
    Ogniwo<T> *next = _pSzczyt;
    Ogniwo<T> *prev = NULL;
    Ogniwo<T> *tmp = NULL;
    while(next != NULL)
    {
        tmp=next->_p_nastepny;
        next->_p_nastepny=prev;
        prev=next;
        next=tmp;
    }
    _pSzczyt = prev;
}

template<class T>
std::ostream &operator<< (std::ostream &F, Stos<T> & stos)
{
    F << "(";
    F << stos.top();
    stos.pop();
    while (!stos.empty())
    {
        F << ", " << stos.top();
        stos.pop();
    }
    F << ")";
    return F;
}