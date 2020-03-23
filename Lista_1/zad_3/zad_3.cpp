#include <iostream>

int main(){
    std::cout<<"0xa-012: "<<(0xa-012)<<std::endl; //zwykłe odejmowanie tych samych liczb zapisanych w innych systemach liczbowych
    std::cout<<"13%3: "<<(13%3)<<std::endl; //dzielenie z resztą
    std::cout<<"3,14-3: "<<(3.14-3)<<std::endl; //zwykłe odejmowanie
    std::cout<<"1234^1234: "<<(1234^1234)<<std::endl; //operator XOR
    std::cout<<"1<<3: "<<(1<<3)<<std::endl;//Binarny operator lewej zmiany. Wartość lewego operandu przesuwana jest w lewo o liczbę bitów określoną przez prawy operand.
    std::cout<<"0xF&0xA: "<<(0xF&0xA)<<std::endl; //operator AND
    std::cout<<"3>2>1: "<<(3>2>1)<<std::endl; //operator lewostronnej wielkości. Zwraca True albo False
    std::cout<<"12345+~12345: "<<(12345+~12345)<<std::endl; //~12345 zwróci 12346, operator uzupełnienia jednostek, zamiana 1 na 0
    std::cout<<"1+1e-40-1: "<<(1+1e-40-1)<<std::endl; //utrata dokładności poprzez dodawanie zbliżonych do siebie wartości
    std::cout<<"3==3==3: "<<(3==3==3)<<std::endl; //operator równości
    std::cout<<"1+1e-10f-1: "<<(1+1e-10f-1)<<std::endl; //utrata dokładności poprzez dodawanie zbliżonych do siebie wartości
    std::cout<<"1/4: "<<(1/4)<<std::endl; //obcina do typy int. Brak liczb po przecinku
    std::cout<<"16>>1: "<<(16>>1)<<std::endl; //Binarny operator prawej zmiany. Wartość lewego operandu przesuwana jest w prawo o liczbę bitów określoną przez prawy operand.
    std::cout<<"0xff^0xf0: "<<(0xff^0xf0)<<std::endl; //operator XOR
    std::cout<<"~(-1): "<<(~(-1))<<std::endl; //operator uzupełnienia jednostek, zamiana 1 na 0
    std::cout<<"0xff|0xaa: "<<(0xff|0xaa)<<std::endl; //operator OR
    std::cout<<"0-1u>0: "<<(0-1u>0)<<std::endl; //operator lewostronnej wielkości
    std::cout<<"-1>1u: "<<(-1>1u)<<std::endl; //operator lewostronnej wielkości
    std::cout<<"1234567&1: "<<(1234567&1)<<std::endl; //operator AND
    std::cout<<"1234567|1: "<<(1234567|1)<<std::endl; //operator OR
    std::cout<<"1234567^1: "<<(1234567^1)<<std::endl; //operator XOR
    std::cout<<"1<2?1:2: "<<(1<2?1:2)<<std::endl; //Conditional operator (?). If Condition is true then it returns value of X otherwise returns value of Y.
    std::cout<<"1,2,3,4: "<<(1,2,3,4)<<std::endl; //Operator przecinka powoduje wykonanie sekwencji operacji. Wartość całego wyrażenia przecinkowego jest wartością ostatniego wyrażenia listy oddzielonych przecinkami.
    std::cout<<"3<2&1<2: "<<(3<2&1<2)<<std::endl; //operator AND
    std::cout<<"1<2&&2<1: "<<(1<2&&2<1)<<std::endl; //Nazywany Logicznym i operatorem. Jeśli oba operandy są niezerowe, to warunek staje się prawdziwy.
    std::cout<<"1<2||2>1: "<<(1<2||2>1)<<std::endl; //Nazywa się Operator Logiczny LUB. Jeśli którykolwiek z dwóch operandów jest niezerowy, to warunek staje się prawdziwy.
    std::cout<<"0b1111: "<<(0b1111)<<std::endl; //operator AND
    
    return 0;
}