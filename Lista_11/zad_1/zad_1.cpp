#include <iostream>
#include <vector>
#include <algorithm>

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
    std::cout << "vector v: ";
    printVector(v);
    std::cout << (v.begin() == v.end()) ;
    std::cout << "\n";
    std::cout << "vector v after example:";
    printVector(v);



}

//v.erase(v.begin(), v.end()) -> v.clear()
//v.erase(v.end - 1) -> v.pop_back()
//v.insert(v.end(),7) -> v.push_back(7)
//v[v.size() - 1] -> v.back()
//*(v.end() - 1) -> v.back()
//*(v.begin()) -> v.frond()
//v.begin() == v.end() -> v.empty()