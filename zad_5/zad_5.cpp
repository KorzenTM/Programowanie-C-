#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>


int fibo1(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
        return fibo1(n-1) + fibo1(n-2);
}

int fibo2(int n)
{
    return 1.0/sqrt(5.0) * ( pow( (1.0+sqrt(5.0))/2.0 , (double)(n) ) - pow( (1.0-sqrt(5.0))/2.0 , (double)(n) ) );
}

int fibo3(int n)
{
    static std::vector<int> v(n);
    if (n == 0)
        v[0]=0;
    if (n == 1)
        v[1]=1;
    else
        v[n]=v[n-1]+v[n-2];
    return v[n];
}

int main()
{
    double time;
    clock_t start,stop;
    std::cout<<"Podpunkt a)"<<std::endl;
    start=clock();
    for(int i=1;i<=48;i++)
    {
        std::cout<<fibo1(i)<<",";
    }
    stop=clock();
    time=(stop-start)/(double)(CLOCKS_PER_SEC);
    std::cout<<"\nCzas wykonania: "<< time << " ms" << std::endl;

    clock_t start_2,stop_2;
    std::cout<<"Podpunkt b)"<<std::endl;
    start_2=clock();
    for(int i=1;i<=48;i++)
    {
        std::cout<<fibo2(i)<<",";
    }
    stop_2=clock();
    time=(stop_2-start_2)/(double)(CLOCKS_PER_SEC);
    std::cout<<"\nCzas wykonania: "<< time <<" ms"<<std::endl;

    clock_t start_3,stop_3;
    std::cout<<"Podpunkt c)"<<std::endl;
    start_3=clock();
    for(int i = 1; i <= 48; i++)
    {
        std::cout<<fibo3(i)<<", ";
    }
    stop_3=clock();
    time=(stop_3-start_3)/(double)(CLOCKS_PER_SEC);
    std::cout<<"\nCzas wykonania: "<< time <<" ms"<<std::endl;

}

