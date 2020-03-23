#include <iostream>
#include <vector>

void zeruj(std::vector<double> &w)
{
    for(int i = 0; i < w.size(); i++)
    {
        w[i]=0.0;
    }
}

std::ostream &operator<< (std::ostream &F,std::vector<double> const&w)
{
    F << "(";
    if(!w.empty())
        F << w[0];
    for(unsigned i=0;i<w.size();i++)
        F << "," << w[i];
    F << ")";
    return F;
}

int main()
{
    std::vector<double> v={32.5,4.5,1.2,7.3,1.8};
    std::cout<<"v="<<v<<std::endl;
    zeruj(v);
    std::cout<<"v="<<v<<std::endl;
}
