//Kolejnosc konstrukcji i destrukcji obiektow jest logiczna
#include <iostream>

class Cztery
{
public:
    Cztery()
    {
        std::cout << "konstrukcji ";
    }
    ~Cztery()
    {
        std::cout << "jest ";
    }
};

class Trzy
{
public:
    Trzy()
    {
        std::cout << "i ";
    }
    ~Trzy()
    {
        std::cout << "obiektow ";
    }

};

class Dwa
{
public:
    Dwa()
    {
        std:: cout << "Kolejnosc ";
    }
    ~Dwa()
    {
        std:: cout << "logiczna";
    }

};

class Raz: public Dwa
{
public:
    Raz()
    {
        Trzy trzy;
        std::cout << "destrukcji ";
    }
private:
    Cztery _cztery;
};

int main()
{
    Raz raz;
}