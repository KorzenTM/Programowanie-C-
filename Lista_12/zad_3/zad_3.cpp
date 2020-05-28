#include <iostream>
#include <vector>


template<class Bi, class Bi2>
Bi2 copy_backward_2(Bi first, Bi last, Bi2 res)
{
    while(last != first)
        *(--res) = *(--last);
    return res;
}

int main()
{
    std::vector<int> v;

    for(unsigned int i = 1; i <= 5; i++)
        v.push_back(i * 10);

    v.resize(v.size() + 3);

    copy_backward_2(v.begin(), v.begin() + 5, v.end());

    std::cout << "v contains: ";
    for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        std::cout << " " << *iter;
    std::cout << "\n";
}

