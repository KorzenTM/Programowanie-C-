#include <iostream>
#include <math.h>

float podpunkt_a(int N){
    float wynik_1=0.0;
    std::cout<<"Podpunkt a:"<<std::endl;
    for(int i=1;i<=N;i++){
        wynik_1+=((pow(-1,i+1))/(2*i-1));
    }
    return 4*wynik_1;
}

float podpunkt_b(int N){
    float wynik_2=1.0;
    std::cout<<"Podpunkt b:"<<std::endl;
    for(int j=1;j<=N;j++){
        wynik_2*=((4*pow(j,2))/(4*pow(j,2)-1));
    }
    return 2*wynik_2;
}

float podpunkt_c(int N){
    float wynik_3=0.0;
    std::cout<<"Podpunkt c:"<<std::endl;
    for(int k=1;k<=N;k++){
        wynik_3+=((1)/(pow(2*k-1,2)));
    }
    return sqrt(8*wynik_3);
}

int main(){
    const int N=1000000;
    std::cout<<"Wartość liczby PI:"<<M_PI<<std::endl;
    std::cout<<"Wynik:"<<podpunkt_a(N)<<std::endl;
    std::cout<<"Wynik:"<<podpunkt_b(N)<<std::endl;
    std::cout<<"Wynik:"<<podpunkt_c(N)<<std::endl;
    
    return 0;
}