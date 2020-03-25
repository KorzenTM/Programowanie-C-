#include <iostream>
#include <cmath>
#include <vector>

double suma(double (*f)(int) , int m , double &eps)
{
    static std::vector<double> v(m);
    double sub_total = 0.0;
    double tmp_sum=0.0;
    double s=0.0;
    double e=0.0; //bład

    for (int i = 0; i < m; i ++)
    {
        sub_total += f(i);
        v[i] = sub_total;
    }
    //std::cout<<v<<std::endl;

    while (m >= 2)
    {
        for (int j = 0; j < m; j++)
        {
            tmp_sum=(v[j]+v[j+1])/2.0;
            if (tmp_sum < eps)
                continue;
            else
                v[j]=tmp_sum;
        }
        m --;
    }
    s=(v[0]+v[1])/2;
    eps=std::abs(v[0]-v[1])/2.0;
    return s;
}

double f_1(int n)
{
    double x = static_cast<double> (n);
    if (n > 1) //zabezpieczenie. Z wlasnosci logarytmow - log k => k>0
        return (pow(-1.0 , x)/log(x));
}

double f_2(int n)
{
    double x = static_cast<double> (n);
    return (pow(-1.0 , x) * (1.0 / (n + 1.0)));
}

double f_3(int n)
{
    double x= static_cast<double> (n);
    return (pow(-1.0 , x) * (1.0 / (2.0 * n + 1.0)));
}

int main()
{
    double eps = 10E-10;
    std:: cout << "s1 = " << suma(f_1,50,eps) << "|e = " << eps << std:: endl; //podany szereg nie spełnia warunków f(x)>0 dla x>=0.?
    eps = 10E-10;
    std:: cout << "s2 = " << suma(f_2,50,eps) << "|e = " << eps << std:: endl;
    eps = 10E-10;
    std:: cout << "s3 = " << suma(f_3,50,eps) << "|e = " << eps << std:: endl;
    return 0;
}
