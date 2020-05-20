#include <iostream>
#include <vector>

template<typename T>
void printVector(T v)
{
    for (auto iter = v.begin(); iter != v.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<double> v = {0.55, 1.25, -1.3, 4.11, 5.11, 12.13};
    printVector(v);
}
