#include <iostream>
#include <map>

using namespace std;

map<long, long> pudlo;

int main()
{
    pudlo[1, 2] = 1;
    pudlo[3, 4] = 1;

    for(int i = 0; i < 10; i++)
    {
        for(int k = 0; k < 10; k++)
        {
            cout << i << " " << k << " " << pudlo[i, k] << endl;
        }
    }
}

//Autor programu użył operatora ",", który zwraca ostatnią wartość wyrażenia [i, k]
//Wartość wyrażenie [i, k] nie zależy od i, ponieważ operator , powoduje, że wyrażenie pudlo[i, k] == pudlo[k], wiec i jest pomiajne
//Wartoscia wyrazenia pudlo[0,0] == 0, ponieważ kontener domyślnie ustawia wartośc 0 dla niezainicjalozowanych elementów
