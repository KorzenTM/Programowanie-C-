#include <iostream>

int main(){
    int x=1;
    int y=x++;
    int z=--y+x;
    int v=z+=2;

    std::cout<<"Zmienna x:"<<x<<std::endl;
    std::cout<<"Zmienna y:"<<y<<std::endl;
    std::cout<<"Zmienna v:"<<z<<std::endl;
    std::cout<<"Zmienna z:"<<v<<std::endl;

    return 0;
}