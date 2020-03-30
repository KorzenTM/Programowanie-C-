#include <iostream>

int main()
{
    double tab[10];
    int x;
    int* p = &x;
    p=0x22ff18;

    std:: cout << p << "\t" << &tab[-1] << "\n";
}

