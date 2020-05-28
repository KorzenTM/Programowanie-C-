#include <iostream>
#include <map>

int main()
{
    std::map<std::pair<int,int>, int> two_keys_dict;
    std::pair<int, int> key_1 = std::make_pair(1,2);
    std::pair<int, int> key_2 = std::make_pair(3,4);
    two_keys_dict[key_1] = 1;
    two_keys_dict[key_2] = 5;

    std::cout << "("<<key_1.first << ", " << key_1.second << ") = " <<two_keys_dict[key_1] << "\n";
    std::cout << "("<<key_2.first << ", " << key_2.second << ") = " <<two_keys_dict[key_2];

}

