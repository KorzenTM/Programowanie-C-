#include <complex>
#include <iostream>
#include <cmath>



int main()
{
    typedef std::complex<double> zesp;
    zesp z1(0,1);
    zesp z2(0, 1);
    zesp ComplexPower = std::pow(z1,z2);
    std::cout << "i^i = " << ComplexPower.real();
}

