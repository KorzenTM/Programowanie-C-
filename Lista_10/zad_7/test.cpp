#include "stos.h"
#include "stos.cpp"
#include <iostream>

int main()
{
    Stos<double> stos;
    for (int i = 1; i <= 50; i++)
    {
        stos.push(i / 5.0);
    }
    //std:: cout << stos;
    stos.reverse();
    std:: cout << stos;
}