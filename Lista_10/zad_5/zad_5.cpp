#include <iostream>

template<typename T>
inline
void zamien(T &source, T &destination)
{
    T temp_source = source;
    source = destination;
    destination = temp_source;
}

int main()
{
    int x = 5;
    int y = 10;
    std:: cout << "x = " << x << " | y = " << y << "\n";
    zamien(x,y);
    std:: cout << "x = " << x << " | y = " << y << "\n";
    return 0;
}

