#include "stos.h"
#include <iostream>

int main()
{
    Stos stos;
    Stos stos2;
    for (int i = 1; i <= 50; i++)
    {
        if (i % 3 == i % 5)
            stos.push(i);
    }
    stos2 = stos;
    while (!stos2.empty())
    {
        std:: cout << stos2.top() << " ";
        stos2.pop();
    }
}