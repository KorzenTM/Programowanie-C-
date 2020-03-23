#include <iostream>
#include <cmath>

double podpunkt_a(int N){
    double wynik_1=0.0;
    double factor=-1.0;
    std::cout<<"Podpunkt a:"<<std::endl;
    for(int i=1;i<=N;i++){
        factor=-factor;
        wynik_1+=((factor)/(2.0*i-1.0));
    }
    return 4.0*wynik_1;
}

double podpunkt_b(int N){
    double wynik_2=1.0;
    std::cout<<"Podpunkt b:"<<std::endl;
    for(int j=1;j<=N;j++){
        wynik_2*=((4.0*j*j)/(4.0*j*j-1.0));
    }
    return 2.0*wynik_2;
}

double podpunkt_c(int N){
    double wynik_3=0.0;
    double temp;
    std::cout<<"Podpunkt c:"<<std::endl;
    for(int k=1;k<=N;k++){
        temp=2.0*k-1.0;
        wynik_3+=((1.0)/(pow(temp,2.0)));
    }
    return sqrt(8.0*wynik_3);
}

int main(){
    const int N=1000000;
    std:: cout << "Wartość liczby PI:" << M_PI << std::endl;
    std:: cout << "Wynik:" << podpunkt_a(N) << std::endl;
    std:: cout << "Wynik:"<< podpunkt_b(N) << std::endl;
    std:: cout << "Wynik:"<< podpunkt_c(N) << std::endl;
    
    return 0;
}