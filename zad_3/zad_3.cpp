#include <iostream>
#include <vector>

double operator* (std::vector<double> const& v,std::vector<double> const& w)
{
    double wynik = 0.0;
    for(unsigned i = 0; i < v.size() and i < w.size(); i++)
        wynik+=(v[i]*w[i]);
    return wynik;
}

std::ostream &operator<< (std::ostream &F,std::vector<double> const&w)
{
    F << "(";
    if(!w.empty())
        F << w[0];
    for(unsigned i = 0; i < w.size(); i++)
        F << "," << w[i];
    F << ")";
    return F;
}

int main()
{
    std::vector<double> v={32.5,4.5,1.2,7.3,1.8};
    std::vector<double> w={3.3,2.76,33.1,44.1,5.5};
    std::cout<<"v="<<v<<std::endl;
    std::cout<<"w="<<w<<std::endl;
    std::cout<<"v*w="<<(v*w)<<std::endl;
}

