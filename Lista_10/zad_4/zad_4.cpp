#include <iostream>

template<typename T, unsigned N>
inline
T suma(T tab[])
{
    T sum = 0;
    for(unsigned i = 0; i < N; i++)
    {
        sum += tab[i];
    }
    return sum;
}

const int SIZE = 5;

int main()
{
    double tab[SIZE] = {1.1, 2.3, 3.4, 1.1, 0.55};
    std:: cout << suma<double,SIZE>(tab) << "\n";
    return 0;
}
