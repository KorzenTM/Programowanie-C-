#include <iostream>
#include <vector>

template<typename T>
void zamien(std::vector<T> &w, std::vector<T> &v)
{
    w.swap(v);
}


int main()
{
    std::vector<int> v1(3, 200);
    std::vector<int> v2(5, 100);
    zamien(v1,v2);
    std::cout << "v1 contains:";
    for (unsigned i = 0; i < v1.size(); i++)
        std::cout << " " << v1[i];
    std::cout << "\n";
    std::cout << "v2 contains:";
    for (unsigned i = 0; i < v2.size(); i++)
        std::cout << " " << v2[i];
    std::cout << "\n";
}

