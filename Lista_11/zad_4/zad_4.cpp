#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>

struct CountRepetitions
{
    std::map<int,int> count;
    bool operator()(int n)
    {
        count[n]++;
    }
    void Repetitions()
    {
        for (auto p : count)
            std::cout << p.first << "->" << p.second << "\n";
    }
};

struct Sum
{
    int _sum;
    Sum():_sum(0) {}
    void operator()(int n) {_sum += n;}
    int SumOfElements() const {return _sum;}
};

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
    std::fstream file;
    int tmpNumber;
    file.open("dane.txt", std::ios::in);
    if (file.good())
    {
        std::cout << "The file was loaded" << std::endl;

    } else std::cout << "File not found" << std::endl;

    std::vector<int> v;
    while (!file.eof())
    {
        file >> tmpNumber;
        v.push_back(tmpNumber);
    }
    std::cout << "Size = " << v.size() << "\n";
    std::cout << "Capacity = " << v.capacity() << "\n";
    std::cout << "First value = " << v.front() << "\n";
    std::cout << "Last value = " << v.back() << "\n";
    int countEvenNumbers = std::count_if(v.begin(), v.end(), [](int n) {return ((n % 2) == 0);});
    std::cout << "Even Figures = " << countEvenNumbers << "\n";
    Sum res = std::for_each(v.begin(), v.end(), Sum());
    std::cout << "Sum of elements = " << res.SumOfElements() << "\n";
    std::sort(v.begin(), v.end());
    std::cout << "Sorted tab:";
    printVector(v);
    CountRepetitions res_2 = std::for_each(v.begin(), v.end(), CountRepetitions());
    res_2.Repetitions();

}

