#include <iostream>
#include <vector>
#include <climits>

int min(std::vector<int> &w)
{
    int temp; //przechowuje tymczasowo liczbe do porownania
    if (w.size() == 0)
        return INT_MIN;
    else
    {
        temp = w[0]; //pierwsza liczba
        for(unsigned i = 0 ;i < w.size() ;i++)
        {
            if (temp>w[i])
                temp = w[i];
        }
        return temp;
    }
}

int main()
{
    std::vector<int> v={43,55,33,90,21,120,9,11,19,100};
    std::cout << "Wartość najmniejsza wektora:" << min(v) << std::endl;
}

