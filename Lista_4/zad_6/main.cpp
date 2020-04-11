#include <iostream>

class X
{
    //friend std::ostream& operator<< (std::ostream &, X const&);
protected:
    int _x;
public:
    X (int arg) : _x(arg) { }
};

std::ostream& operator<< (std::ostream & F, X const & x)
{
    return F << x;
}

int main()
{
    X x(10);
    std::cout << x << "\n";
}

