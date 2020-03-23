#include <iostream>


int silnia_rek(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*silnia_rek(n-1);
    }
}
int main(){
    const int N=40;
    for(int i=0;i<=N;i++)
    {
        std::cout<<"Silnia z "<<i<< ": "<<silnia_rek(i)<<std::endl;
    }
    

    return 0;
}