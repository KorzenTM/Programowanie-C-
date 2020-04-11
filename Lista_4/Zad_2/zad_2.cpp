//A programme carrying out basic activities on composite numbers using classes and operator overloads. 
#include <iostream>
#include <cassert>

class Complex
{
    friend std:: ostream& operator<<(std:: ostream &, Complex const&);
    friend std:: istream& operator>>(std:: istream &, Complex &);
public:
    double Re, Im;

    Complex(int a_re = 0, int a_im = 0)
    : Re(a_re), Im(a_im)
    {
        std:: cout << "" << std:: endl;
    }

    Complex operator+ (Complex const& c2)
    {
        Complex sum;
        sum.Re = this->Re + c2.Re;
        sum.Im = this->Im + c2.Im;
        return sum;
    }

    Complex operator- (Complex const& c2)
    {
        Complex sub;
        sub.Re = this->Re - c2.Re;
        sub.Im = this->Im - c2.Im;
        return sub;
    }

    Complex operator* (Complex const& c2)
    {
        Complex product;
        product.Re = (this->Re * c2.Re) - (this->Im * c2.Im);
        product.Im = (this->Re * c2.Im) + (this->Im * c2.Re);
        return product;
    }

    Complex operator/ (Complex const& c2)
    {
        assert((c2.Re * c2.Re) + (c2.Im * c2.Im) > 0);
        Complex division;
        division.Re = ((this->Re * c2.Re) + (this->Im * c2.Im)) / ((c2.Re * c2.Re) + (c2.Im * c2.Im));
        division.Im = ((this->Im * c2.Re) - (this->Re * c2.Im)) / ((c2.Re * c2.Re) + (c2.Im * c2.Im));
        return division;
    }
    ~Complex() {}
};

std:: ostream& operator<<(std:: ostream &F, Complex const &c)
{
    F << c.Re << "+" << c.Im << "i";
    return F;
}

std:: istream& operator>>(std:: istream &F, Complex & c)
{
    std:: cout << "Enter real part:";
    F >> c.Re;
    std:: cout << "Enter imaginary part:";
    F >> c.Im;
    return F;
}
int main()
{
    Complex z1;
    std:: cout << "First complex number (a+ib):" << std:: endl;
    std:: cin >> z1;
    std:: cout << z1 << std:: endl;
    Complex z2;
    std:: cout << "Second complex number (c+id):" << std:: endl;
    std:: cin >> z2;
    std:: cout << z2 << std:: endl;
    std:: cout << "Total =" << z1 + z2 << std:: endl;
    std:: cout << "Difference = " << z1 - z2 << std:: endl;
    std:: cout << "Product = " << z1 * z2 << std:: endl;
    std:: cout << "Quotient = " << z1 / z2 << std:: endl;
    return 0;
}